/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:00:01 by echai             #+#    #+#             */
/*   Updated: 2021/04/13 09:21:06 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	free_grid(int **grid, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

char	*std_input_file(void)
{
	int		file;
	char	*filename;
	char	c;

	filename = "stdin_map";
	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	while (read(0, &c, 1) != 0)
	{
		write(file, &c, 1);
	}
	ft_putchar('\n');
	close(file);
	return (filename);
}
