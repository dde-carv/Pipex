/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:05:09 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/14 17:19:05 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

t_pipe	*data(void)
{
	static t_pipe	data;

	return (&data);
}

static int	check_empty(int argc, char **argv)
{
	int	i;
	int	j;
	int	blank;

	i = 1;
	while (i < argc)
	{
		j = 0;
		blank = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				blank++;
			j++;
		}
		if (blank == j)
			return (0);
		i++;
	}
	return (1);
}

static t_cmd	*set_input(int argc, char **argv, char **paths)
{
	int		i;
	t_cmd	*input;

	if (!ft_strncmp(argv[1], "here_doc", 9))
		i = 3;
	else
		i = 2;
	input = ft_newcmd(argv[i], check_path(argv[i], paths));
	i++;
	while (argv[i] && i < (argc - 1))
	{
		ft_addcmd(&input, ft_newcmd(argv[i], check_path(argv[i], paths)));
		i++;
	}
	return (input);
}

static t_cmd	*init_pipex(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	if (!ft_strncmp(argv[1], "here_doc", 9))
		here_doc_main(argc, argv);
	else
	{
		data()->fd_in = open(argv[1], O_RDONLY);
		if (data()->fd_in == -1)
			exit_pipex(NULL, 2);
		data()->fd_out = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data()->fd_out == -1)
			exit_pipex(NULL, 3);
	}
	data()->paths = get_path(envp);
	input = set_input(argc, argv, data()->paths);
	data()->first = input;
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	if (argc > 5)
	{
		if (!check_empty(argc, argv))
			exit_pipex(NULL, 1);
		input = init_pipex(argc, argv, envp);
		father_son(input, envp);
	}
	else
	{
		ft_printf("Bad syntax:\n./pipex file1 cmd1 cmd2 cmd3 ... file2\n\
			or\n./pipex here_doc LIMITER cmd1 cmd2 file\n");
		return (1);
	}
	return (0);
}
