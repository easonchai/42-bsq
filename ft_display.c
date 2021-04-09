/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:27:19 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/08 21:52:06 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

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

void	display_map(int **grid, t_answer ans, t_init init, t_charset c)
{
	int	i;
	int j;

	i = 0;
	while (i < init.height)
	{
		j = 0;
		while (j < init.width)
		{
			if (is_filled(j, i, ans))
				ft_putchar(c.full);
			else if (grid[j][i] == 0)
				ft_putchar(c.obstacle);
			else
				ft_putchar(c.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
