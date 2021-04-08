/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/08 15:04:53 by jkhong           ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	// TODO if (argc == 1)
	
	int			i;
	int			file;
	t_init		init;
	t_charset	charset;

	i = 1;
	while (i < argc) // loop through all of the files
	{	
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			print_err();
		else
		{
			printf("%i\n", get_len(&init, file));
			printf("%i\n", init.width);
		}
		// find charset (pass in init and charset addresses)
		i++;
	}

}
