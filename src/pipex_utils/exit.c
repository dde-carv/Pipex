/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:53:43 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

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
		exit(1);
	}
	input = data()->first;
	ft_free_rest(&input, data()->paths);
	exit(0);
}
