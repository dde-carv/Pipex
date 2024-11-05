/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:15:04 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/05 16:37:05 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*input;

	if (argc == 5)
	{
		if (!check_empty(argc, argv))
			exit_pipex();
		init_pipex(argc, argv, envp);
	}
	else
		ft_printf("Bad syntax:\n./pipex file1 \"cmd1\" \"cmd2\" file2\n");
	return (0);
}
