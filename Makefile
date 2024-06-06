# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalacio <lpalacio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:41:29 by lpalacio          #+#    #+#              #
#    Updated: 2024/06/04 21:25:26 by lpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	so_long.c check_args.c

OBJDIR	=  bin
OBJS	= ${SRCS:%.c=${OBJDIR}/%.o}

NAME = so_long
LIBDIR = lib
GNLLIB_DIR = ${LIBDIR}/gnl
LIBGNL = ${GNLLIB_DIR}/libgnl.a
LIBFT_DIR = ${LIBDIR}/ft
LIBFT = ${LIBFT_DIR}/libft.a

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLIBGNL = -L ${GNLLIB_DIR} -lgnl
CLIBFT = -L ${LIBFT_DIR} -lft


all: $(NAME)

bin/%.o : %.c
	@mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) | $(LIBGNL) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS) $(CLIBGNL) $(CLIBFT) $(CFLAGS)
	@echo "so_long has been compiled"

$(LIBGNL):
	@$(MAKE) -C $(GNLLIB_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) ${OBJS} ${OBJDIR}
	@$(MAKE) -C ${GNLLIB_DIR} clean
	@$(MAKE) -C ${LIBFT_DIR} clean

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ${GNLLIB_DIR} fclean
	@$(MAKE) -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re