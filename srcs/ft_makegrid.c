/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makegrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:26:44 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/10 12:26:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		give_int(char c, t_charset charset)
{
	if (c == charset.empty)
		return (1);
	else if (c == charset.obstacle)
		return (0);
	else
		return (-1);
}

int		populate_grid(int **grid, int file, t_charset charset, t_init init)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (read(file, &c, 1) > 0 && i < (init.height * init.width))
	{
		j = give_int(c, charset);
		if ((c == '\n' && (i % init.width != 0)) ||
				(j == -1 && c != '\n'))
			return (0);
		grid[i % init.width][i / init.width] = j;
		if (c != '\n')
			i++;
	}
	if (i != (init.height * init.width))
		return (0);
	return (1);
}

int		**make_grid(int file, t_charset charset, t_init init)
{
	int		**grid;
	int		i;

	grid = malloc(sizeof(int *) * init.width);
	i = 0;
	while (i < init.width)
	{
		grid[i] = malloc(sizeof(int) * init.height);
		i++;
	}
	if (populate_grid(grid, file, charset, init))
		return (grid);
	else
	{
		free_grid(grid, init.width);
		return (NULL);
	}
}
