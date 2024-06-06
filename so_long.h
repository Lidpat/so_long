/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:05:39 by lpalacio          #+#    #+#             */
/*   Updated: 2024/06/04 21:09:49 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include "lib/gnl/get_next_line.h"
# include "lib/ft/libft.h"
# include <fcntl.h>

# include <stdio.h>   ///BORRAR!!!!

char    **check_args(char *argv);
void    error_out(int n);

#endif