/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 23:39:48 by hjo               #+#    #+#             */
/*   Updated: 2018/04/04 23:39:49 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**big_board_gen(int size)
{
	int		i;
	int		j;
	char	**board;

	board = (char **)malloc((size + 1) * sizeof(char *));
	ft_bzero(board, (size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		board[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			board[i][j] = '.';
		i++;
	}
	return (board);
}

char	**board_del(char **board, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}
