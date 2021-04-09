/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/09 20:47:22 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	print_grid(int **grid, t_init init);
void	print_err(void)
{
	write(1, "map error\n", 10);
}

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
		if (init[len - 1] == init[len - 2] == init[len - 3])
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

int		give_int(char c, t_charset charset)
{
	if (c == charset.empty)
		return (1);
	else if (c == charset.obstacle)
		return (0);
	else
		return (-1);
}

#include <stdio.h>
int		**make_grid(int file, t_charset charset, t_init init)
{
	int		**grid;
	int		i;
	int		j;
	char	c;

	grid = malloc(sizeof(int *) * init.width);
	i = 0;
	while (i < init.width)
	{
		grid[i] = malloc(sizeof(int) * init.height);
		i++;
	}
	i = 0;
	while (read(file, &c, 1) > 0 && i < (init.height * init.width))
	{
		j = give_int(c, charset);
		if ((c == '\n' && (i % init.width != 0)) ||
				(j == -1 && c != '\n'))
			return (NULL);
		grid[i % init.width][i / init.width] = j;
		if (c != '\n')
			i++;
	}
	if (i != (init.height * init.width))
		return (NULL);
	return (grid);
}

void	free_grid(void)
{
	//TODO
}

void	open_file(char *filename)
{
	int			file;
	t_init		init;
	t_charset	charset;
	int			init_len;
	int			**grid;

	file = open(filename, O_RDONLY);
	if (file == -1)
		print_err();
	else
	{	
		init_len = get_len(&init, file);
		file = open(filename, O_RDONLY);
		if (!test_input(&init, &charset, init_len, file))
			print_err();
		else
		{
			grid = make_grid(file, charset, init);
			if (grid == NULL)
			{
				print_err();
				return ;
			}
			dissect_grid(grid, charset, init);
		}
		close(file);
	}
}

int		main(int argc, char *argv[])
{
	// TODO if (argc == 1)
	int			i;

	i = 1;
	while (i < argc)
	{	
		open_file(argv[i]);
		i++;
	}
}
