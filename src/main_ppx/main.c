/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:15:04 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/07 11:32:01 by dde-carv         ###   ########.fr       */
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

static void	set_input(int argc, char **argv, char **paths, t_cmd *input)
{
	int	i;

	i = 2;
	input = ft_newcmd(argv[i], check_path(argv[i], paths));
	while (argv[i] && i < (argc - 1))
	{
		ft_addcmd(&input, ft_newcmd(argv[i], check_path(argv[i], paths)));
		i++;
	}
	return ;
}

static void	init_pipex(int argc, char **argv, char **envp, t_cmd *input)
{
	data()->flag = 0;
	data()->fd_in = open(argv[1], O_RDONLY);
	if (data()->fd_in < 0)
		exit_pipex(NULL, 2);
	data()->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data()->fd_out < 0)
		exit_pipex(NULL, 3);
	data()->paths = get_path(envp);
	set_input(argc, argv, data()->paths, input);
	data()->first = input;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	if (argc == 5)
	{
		if (!check_empty(argc, argv))
			exit_pipex(NULL, 1);
		init_pipex(argc, argv, envp, &input);
		father_son(&input, envp);
	}
	else
		ft_printf("Bad syntax:\n./pipex file1 \"cmd1\" \"cmd2\" file2\n");
	return (0);
}
