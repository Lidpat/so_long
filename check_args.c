/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:55:17 by lpalacio          #+#    #+#             */
/*   Updated: 2024/06/06 22:55:20 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_out(int n)
{
    write (1, "Fatal Error\n", 12);
    write (1,"Terminating program\n",20);
    exit(n);
}

t_list  *read_map(char *argv)
{
    int     fd;
    t_list  *lst_map;
    char    *line;

	fd = -1;
    lst_map = NULL;
	if (!argv)
        error_out(1);
	fd  = open(argv, O_RDONLY);
    if (fd < 0)
    {
        error_out(3); 
    }
    line = get_next_line(fd);
    if (line)
    {
        ft_lstadd_back(&lst_map, ft_lstnew(line));
        line = get_next_line(fd);
        while (line)
        {
             ft_lstadd_back(&lst_map, ft_lstnew(line));
             line = get_next_line(fd);
        }
    }
    close(fd);
    return (lst_map);
}

char    **check_args(char *argv)
{
    t_list  *lst_map;
    t_list  *lst;

    lst_map = read_map(argv);
    lst = lst_map;
    while (lst)
    {
        printf ("%s\n", (char *)(lst)->content);
        lst = (lst)->next;
    }
    ft_lstclear(&lst_map, free);
    return (NULL);


}