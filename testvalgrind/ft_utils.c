/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:00:01 by echai             #+#    #+#             */
/*   Updated: 2021/04/09 21:00:04 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    free_grid(int **grid, int col)
{
    int i;

    i = 0;
    while (i < col)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}