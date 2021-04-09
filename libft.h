/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:09:06 by echai             #+#    #+#             */
/*   Updated: 2021/04/09 20:14:04 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef	struct	s_answer
{
	int	max;
	int	x;
	int	y;
}				t_answer;

typedef	struct	s_init
{
	int	height;
	int	width;
}				t_init;

typedef	struct	s_charset
{
	char	empty;
	char	obstacle;
	char	full;
}				t_charset;

t_answer solve(t_answer ans, t_init init, int **grid);
void	display_map(int **grid, t_answer a, t_init i, t_charset c);
void	dissect_grid(int **grid, t_charset c, t_init init);

#endif
