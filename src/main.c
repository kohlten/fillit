/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:07:03 by hjo               #+#    #+#             */
/*   Updated: 2018/03/21 22:07:05 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_error(void)
{
	ft_putendl("error");
	return (1);
}

int			main(int argc, char **argv)
{
	char	***buf;
	t_board	*board;
	int		i;

	if (argc != 2)
	{
		ft_putendl("./fillit filename");
		return (0);
	}
	if (!(buf = init(argv[1])))
		return (ft_error());
	buf = prepare(buf);
	board = solve_board(buf);
	i = 0;
	while (i < SIZE)
		invalid_print(BOARD[i++], SIZE);
	free_3d_array((void ***)buf);
	i = 0;
	while (BOARD[i])
		free(BOARD[i++]);
	free(BOARD);
	free(board);
	return (0);
}
