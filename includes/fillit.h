/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:31:53 by astrole           #+#    #+#             */
/*   Updated: 2018/04/02 22:31:54 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define BLOCK_SIZE 1024
# define BOARD board->board
# define SIZE board->current_size

typedef struct	s_board
{
	char	**board;
	int		size;
	int		current_size;
}				t_board;

typedef struct	s_tetrominos
{
	char	**tetro;
	int		width;
	int		height;
	char	letter;
}				t_tetrominos;

struct			s_square
{
	char	***out;
	int		len;
	int		current;
	char	tmp[30];
};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

char			***get_sqaures	(char *s);
void			***free_3d_array(void ***arr);
char			**go_back		(char **tet, int len);
int				find_movelen	(char **tet);
char			**del_horidots	(char **tet);
char			**del_veridots	(char **tet);
char			**big_board_gen	(int size);
char			**board_del		(char **board, int size);
t_board			*solve_board	(char ***tets);
void			invalid_print	(char *s, int amount);
char			***init			(char *fn);
void			add_ints		(int *one, int *two);
char			***prepare		(char ***buf);

#endif
