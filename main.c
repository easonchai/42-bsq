/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/08 17:59:13 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> // TO REMOVE
#include <stdlib.h>
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

t_data	**make_grid(int file, t_charset charset, t_init init)
{
	t_data	**grid;
	int		i;
	int		check_len;
	char	c;
	int		num;

	grid = malloc(sizeof(t_data *) * init.height);
	i = 0;
	while (i < init.height)
	{
		grid[i] = malloc(sizeof(t_data) * init.width);
		i++;
	}
	i = 0;
	while (read(file, &c, 1) > 0 && i < (init.height * init.width))
	{	
		/*
		if (i % init.width == 0 && c != '\n') TODO
			return (NULL);
		*/
		if (c == charset.empty)
			grid[i / init.width][i % init.width].c = 0;
		else if (c == charset.obstacle)
			grid[i / init.width][i % init.width].c = 1;
		grid[i / init.width][i % init.width].x = i % init.width;
		grid[i / init.width][i % init.width].y = i / init.width;
		if (c != '\n')
			i++;
	}
	return (grid);
}

void	free_grid(void)
{
	// TODO
}

void	print_grid(t_data **grid)
{
	for (int i = 0; i < 9; i++)
	{
		for (int x = 0; x < 27; x++)
		{
			printf("%i ", grid[i][x].c);;
		}
		printf("\n");
	}
}

int		main(int argc, char *argv[])
{
	// TODO if (argc == 1)
	
	int			i;
	int			file;
	t_init		init;
	t_charset	charset;
	int			init_len;
	t_data		**grid;

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
				// check if makegrid got errors
				grid = make_grid(file, charset, init);
				print_grid(grid);
			}
		}
		// find charset (pass in init and charset addresses)
		i++;
	}
}
