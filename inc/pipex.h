/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:18:46 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/05 14:39:24 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_cmd
{
	int				fd[2];
	char			*cmd;
	char			*path;
	char			**av;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}		t_cmd;

typedef struct s_pipe
{
	int			pid;
	int			flag;
	int			fd_in;
	int			fd_out;
	char		**path;
	t_cmd		*first;
}		t_pipe;




#endif
