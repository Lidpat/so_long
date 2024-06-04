/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:35:07 by lpalacio          #+#    #+#             */
/*   Updated: 2024/06/04 21:08:04 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;

	fd = -1;
	if (argc == 2)
	{
		fd  = open(argv[1], O_RDONLY);
		
		printf ("fd: %d\n", fd) ; //BORRAR

		close(fd);
	}
	else
	//print error message
	return (0);
}
