/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:53:41 by echai             #+#    #+#             */
/*   Updated: 2021/04/13 09:29:05 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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

int			min_handler(int **grid, int i, int j)
{
	int	min;

	if (i == 0 || j == 0)
		return (0);
	min = get_min(grid[j - 1][i - 1], grid[j][i - 1],
			grid[j - 1][i]);
	return (min);
}

t_answer	solve(t_answer ans, t_init init, int **grid)
{
	int min;
	int	i;
	int	j;

	i = -1;
	while (++i < init.height)
	{
		j = -1;
		while (++j < init.width)
		{
			if (grid[j][i])
			{
				min = min_handler(grid, i, j);
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

void		dissect_grid(int **grid, t_charset c, t_init init)
{
	t_answer	ans;

	ans.max = 0;
	ans.x = 0;
	ans.y = 0;
	ans = solve(ans, init, grid);
	display_map(grid, ans, init, c);
}
