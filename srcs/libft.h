/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:09:06 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 14:48:25 by echai            ###   ########.fr       */
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

void			ft_putchar(char c);
void			free_grid(int **grid, int col);
int				get_len(t_init *init, int file);
int				valid_input(char *init, int len);
int				test_input(t_init *init, t_charset *charset, int len, int file);
int				**make_grid(int file, t_charset charset, t_init init);
t_answer		solve(t_answer ans, t_init init, int **grid);
void			display_map(int **grid, t_answer a, t_init i, t_charset c);
void			dissect_grid(int **grid, t_charset c, t_init init);

#endif
