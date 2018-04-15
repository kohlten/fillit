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
	t_board	*solved;
	int		i;

	if (argc != 2)
	{
		ft_putendl("./fillit filename");
		return (0);
	}
	if (!(buf = init(argv[1])))
		return (ft_error());
	buf = prepare(buf);
	solved = solve_board(buf);
	i = 0;
	while (i < solved->current_size)
		invalid_print(solved->board[i++], solved->current_size);
	free_3d_array((void ***)buf);
	i = 0;
	while (solved->board[i])
		free(solved->board[i++]);
	free(solved->board);
	free(solved);
	return (0);
}
