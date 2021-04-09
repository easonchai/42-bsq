/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:53:41 by echai             #+#    #+#             */
/*   Updated: 2021/04/09 20:27:35 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		display_map(int **grid, t_answer a, t_init i, t_charset c);

int			get_min(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

t_answer	solve(t_answer ans, t_init init, int **grid)
{
	int min;
	int	i;
	int	j;

	i = 0;
	while (++i < init.height)
	{
		j = 0;
		while (++j < init.width)
		{
			if (grid[j][i])
			{
				min = get_min(grid[j - 1][i - 1], grid[j][i - 1],
						grid[j - 1][i]);
				grid[j][i] = min + 1;
				if (min + 1 > ans.max)
				{
					ans.max = min + 1;
					ans.x = j;
					ans.y = i;
				}
			}
		}
	}
	return (ans);
}

#include <stdio.h>
void		print_grid(int **grid, t_init init)
{
	int i;
	int j;

	i = 0;
	while (i < init.height)
	{
		j = 0;
		while (j < init.width)
		{
			printf("%d", grid[j++][i]);
		}
		printf("\n");
		i++;
	}
}

void		dissect_grid(int **grid, t_charset c, t_init init)
{
	t_answer	ans;

	ans.max = 0;
	ans.x = 0;
	ans.y = 0;
	ans = solve(ans, init, grid);
	display_map(grid, ans, init, c);
}
