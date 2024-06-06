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

#include <stdio.h>

int	main(int argc, char **argv)
{
		if (argc == 2)
	{
		check_args(argv[1]);
	}
	else
		error_out(2);
	return (0);
}
