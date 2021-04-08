/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:16:05 by echai             #+#    #+#             */
/*   Updated: 2021/04/08 20:19:27 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_filled(int x, int y, t_answer ans)
{
	if (x > (ans.x - ans.max) && x <= ans.x &&
			y > (ans.y - ans.max) && y <= ans.y)
		return (1);
	return (0);
}

void	print_output(int **grid, t_answer ans, t_init init, t_charset c)
{
	int	i;
	int j;

	i = 1;
	while (i < init.height + 1)
	{
		j = 1;
		while (j < init.width + 1)
		{
			if (is_filled(i - 1, j - 1, ans))
				ft_putchar(c.full);
			else if (grid[i][j] == 0)
				ft_putchar(c.obstacle);
			else
				ft_putchar(c.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
