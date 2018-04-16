/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 00:35:34 by astrole           #+#    #+#             */
/*   Updated: 2018/04/12 00:35:35 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		possible(char **board, char **tet, int size, t_point *curr)
{
	t_point iter;
	t_point boarditer;

	iter.y = 0;
	boarditer.y = curr->y;
	while (tet[iter.y])
	{
		iter.x = 0;
		boarditer.x = curr->x;
		while (tet[iter.y][iter.x])
		{
			if (tet[iter.y][iter.x] == '.')
			{
				add_ints(&iter.x, &boarditer.x);
				continue ;
			}
			if (board[boarditer.y][boarditer.x] != '.' || boarditer.x > size)
				return (0);
			add_ints(&iter.x, &boarditer.x);
		}
		add_ints(&iter.y, &boarditer.y);
		if (boarditer.y > size || boarditer.x > size)
			return (0);
	}
	return (1);
}

static char		**place(char **tet, char **board, t_point *pos, char c)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	k = pos->y;
	l = pos->x;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j])
		{
			if (tet[i][j] == '#')
				board[k][l] = c;
			l++;
			j++;
		}
		l = pos->x;
		k++;
		i++;
	}
	return (board);
}

static t_point	*copy_point(t_point *original)
{
	t_point *new;

	new = ft_memalloc(sizeof(t_point));
	new->y = original->y;
	new->x = original->x;
	return (new);
}

static int		solve(t_board *board, char ***tets, int current)
{
	t_point curr;
	t_point *pos;

	if (!tets[current])
		return (1);
	curr.y = -1;
	while (BOARD[++curr.y])
	{
		curr.x = -1;
		while (BOARD[curr.y][++curr.x])
		{
			pos = copy_point(&curr);
			if (possible(BOARD, tets[current], SIZE, pos))
			{
				BOARD = place(tets[current], BOARD, pos,
					'A' + current);
				if (solve(board, tets, current + 1) == 1)
					return (1);
				BOARD = place(tets[current], BOARD, pos, '.');
			}
			free(pos);
		}
	}
	return (0);
}

t_board			*solve_board(char ***tets)
{
	t_board	*board;
	int		current;
	int		output;
	int		len;

	len = 0;
	while (tets[len])
		len++;
	board = ft_memalloc(sizeof(t_board));
	board->size = len * 4;
	SIZE = 2;
	BOARD = big_board_gen(board->size);
	while (1)
	{
		current = 0;
		output = solve(board, tets, current);
		if (output != 1)
		{
			SIZE++;
			BOARD = board_del(BOARD, SIZE);
		}
		else
			break ;
	}
	return (board);
}
