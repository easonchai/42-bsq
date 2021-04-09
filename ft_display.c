/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:27:19 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/09 20:28:34 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_filled(int x, int y, t_answer a)
{
	if (x > (a.x - a.max) && x <= a.x &&
			y > (a.y - a.max) && y <= a.y)
		return (1);
	return (0);
}

void	display_map(int **grid, t_answer a, t_init i, t_charset c)
{
	int	in;
	int j;

	in = 0;
	while (in < i.height)
	{
		j = 0;
		while (j < i.width)
		{
			if (is_filled(j, in, a))
				ft_putchar(c.full);
			else if (grid[j][in] == 0)
				ft_putchar(c.obstacle);
			else
				ft_putchar(c.empty);
			j++;
		}
		ft_putchar('\n');
		in++;
	}
}
