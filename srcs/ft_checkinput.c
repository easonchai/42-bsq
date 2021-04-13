/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:41:58 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/13 10:00:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int		get_len(t_init *init, int file)
{
	int		init_len;
	int		grid_width;
	int		newlines;
	char	c;

	newlines = 0;
	init_len = 0;
	grid_width = 0;
	while (read(file, &c, sizeof(c)) > 0 && newlines < 2)
	{
		if (newlines == 0 && c != '\n')
			init_len++;
		if (newlines == 1 && c != '\n')
			grid_width++;
		if (c == '\n')
			newlines++;
	}
	init->width = grid_width;
	return (init_len);
}

int		valid_input(char *init, int len)
{
	int i;
	int tmp;
	int num;

	num = 0;
	if (len < 4)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (!(init[i] >= ' ' && init[i] <= '~'))
			return (-1);
		tmp = i + 1;
		if (init[len - 1] == init[len - 2] ||
			init[len - 1] == init[len - 3] || init[len - 2] == init[len - 3])
			return (-1);
		if (i < (len - 3))
		{
			if (!(init[i] >= '0' && init[i] <= '9'))
				return (-1);
			num = (num * 10) + (init[i] - '0');
		}
		i++;
	}
	return (num);
}

int		test_input(t_init *init, t_charset *charset, int len, int file)
{
	char	buffer[len];
	char	c;
	int		i;
	int		height;

	i = 0;
	while (read(file, &c, 1))
	{
		if (c == '\n')
			break ;
		buffer[i] = c;
		i++;
	}
	height = valid_input(buffer, len);
	if (height == -1)
		return (0);
	init->height = height;
	charset->empty = buffer[len - 3];
	charset->obstacle = buffer[len - 2];
	charset->full = buffer[len - 1];
	return (1);
}
