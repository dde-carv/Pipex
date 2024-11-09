/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:53:43 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/09 12:28:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	free_all_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

static void	ft_free_rest(t_cmd **input, char **paths)
{
	int		i;
	t_cmd	*tmp;

	while (*input)
	{
		i = 0;
		tmp = (*input);
		(*input) = (*input)->next;
		while (tmp->av[i])
		{
			free(tmp->av[i]);
			i++;
		}
		free(tmp->av);
		free(tmp->path);
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	if(paths)
		free(paths);
}

static void	ft_exitcmd(t_cmd *input)
{
	int i;

	i = 0;
	ft_printf("Error:\nUnable to execute the command:");
	while (input->av[i])
	{
		ft_printf(" %s", input->av[i]);
		i++;
	}
	ft_printf("\n");
	input = data()->first;
	ft_free_rest(&input, data()->paths);
}

void	exit_pipex(t_cmd *input, int error)
{
	if (data()->flag == 42)
		unlink(".temp");
	if (error != 0)
	{
		if (error == 1)
			ft_printf("Error:\nEmpty argument.\n");
		else if (error == 2)
			ft_printf("Error:\nCan't open infile.\n");
		else if (error == 3)
			ft_printf("Error:\nCan't create outfile.\n");
		else if (error == 4)
			ft_printf("Error:\nCan't get the commands PATH.\n");
		else if (error == 5)
			ft_printf("Error:\nCan't fork process.\n");
		else if (error == 6)
			ft_exitcmd(input);
		else if (error == 7)
			ft_printf("Error:\nCan't run here_doc.\n");
		exit(1);
	}
	input = data()->first;
	ft_free_rest(&input, data()->paths);
	exit(0);
}
