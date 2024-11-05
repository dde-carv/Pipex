# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 10:20:42 by dde-carv          #+#    #+#              #
#    Updated: 2024/11/04 14:46:29 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

LIBFT	=	./libft/libft.a
INC	=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/
SRCB_DIR	=	src_b/
OBJB_DIR	=	obj_b/

CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra -g -I
RM	=	@rm -f

	=	$(SRC_DIR)

MAIN_PPX_DIR	=	$(SRC_DIR)main_ppx/main.c

BONUS_DIR		=	$(SRCB_DIR)

SRCS	=	$()
SRCS_B	=	$()

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_B	=	$(patsubst $(SRCB_DIR)%/*.c,$(OBJB_DIR)%/*.o,$(SRCS_B))

$(LIBFT):
		@make -s -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
		@echo "Make .o and exacuteble."
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_B):	$(OBJS) $(LIBFT)
		@echo "Make .o and exacuteble."
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)
		@$(CC) $(CFLAGS) $(INC) $(OBJS_B) $(LIBFT) -o $(NAME_B)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

bonus:		$(NAME_B)

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		bonus clean fclean re
