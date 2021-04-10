/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/10 14:46:27 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

void	print_err(void)
{
	write(1, "map error\n", 10);
}

void	process_file(int file, char *filename)
{
	t_init		init;
	t_charset	charset;
	int			init_len;
	int			**grid;

	init_len = get_len(&init, file);
	close(file);
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
		free_grid(grid, init.width);
	}
	close(file);
}

void	open_file(char *filename)
{
	int			file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		print_err();
	else
		process_file(file, filename);
}

int		main(int argc, char *argv[])
{
	int			i;

	// TODO if (argc == 1)
	i = 1;
	while (i < argc)
	{
		open_file(argv[i]);
		i++;
	}
}
