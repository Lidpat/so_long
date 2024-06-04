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


SRCS	=	so_long.c

OBJDIR	=  bin
OBJS	= ${SRCS:%.c=${OBJDIR}/%.o}

NAME = so_long
LIBDIR = lib
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
GNLLIBDIR = ${LIBDIR}/gnl
CLIBGNL = -L ${GNLLIBDIR} -lgnl
LIBGNL = libgnl.a


all: $(NAME)

bin/%.o : %.c
	@mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) | $(LIBGNL)
	@$(CC) -o $(NAME) $(OBJS) $(CLIBGNL) $(CFLAGS)
	@echo "so_long has been compiled"

$(LIBGNL):
	@$(MAKE) -C $(GNLLIBDIR)

clean:
	@$(RM) ${OBJS} ${OBJDIR}
	@$(MAKE) -C ${GNLLIBDIR} clean

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ${GNLLIBDIR} fclean

re: fclean all

.PHONY: all clean fclean re