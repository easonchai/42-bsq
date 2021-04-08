/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/08 16:56:37 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> // TO REMOVE
#include "libft.h"

void	print_err(void)
{
	write(1, "map error\n", 10);
}


// return true or false
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
	close(file);
	// assign length to init
	init->width = grid_width;
	return (init_len);
}
int		valid_input(char *init, int len) // return number
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
		while (i >= (len + 3)  && tmp < len)
		{
			if (init[tmp] == init[i])
				return (-1);
			tmp++;
		}
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
			break;
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

int		main(int argc, char *argv[])
{
	// TODO if (argc == 1)
	
	int			i;
	int			file;
	t_init		init;
	t_charset	charset;
	int			init_len;

	i = 1;
	while (i < argc) // loop through all of the files
	{	
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			print_err();
		else
		{	
			init_len = get_len(&init, file);
			file = open(argv[i], O_RDONLY);
			if (!test_input(&init, &charset, init_len, file))
			{
				close(file);
				print_err();
			}
			else
			{
				printf("%i\n", init.height);
				printf("%i\n", init.width);
				printf("%c\n", charset.empty);
				printf("%c\n", charset.obstacle);
				printf("%c\n", charset.full);
			}
		}
		// find charset (pass in init and charset addresses)
		i++;
	}
}
