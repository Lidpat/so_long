# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalacio <lpalacio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 20:55:24 by lpalacio          #+#    #+#              #
#    Updated: 2024/06/04 21:01:11 by lpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= get_next_line_utils.c get_next_line.c

OBJDIR = bin
OBJS	= ${SRCS:%.c=$(OBJDIR)/%.o}
NAME	= libgnl.a
RM	= rm -rf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror

bin/%.o : %.c
		@$(CC) ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
	@ar crus ${NAME} ${OBJS}

$(OBJS): | $(OBJDIR)

all:	${NAME}

${OBJDIR}:
	@mkdir ${OBJDIR}

clean: 
		@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME} $(OBJDIR)

re:	fclean all

.PHONY: all clean fclean re