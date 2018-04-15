/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:28:22 by hjo               #+#    #+#             */
/*   Updated: 2018/04/07 19:28:23 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	invalid_print(char *s, int amount)
{
	while (*s && amount)
	{
		ft_putchar(*s++);
		amount--;
	}
	ft_putchar('\n');
}

char	**del_horidots(char **tet)
{
	int i;
	int j;

	i = 0;
	while (tet[i])
	{
		j = i;
		if (ft_strcmp("....", tet[i]) ? 0 : 1)
		{
			free(tet[i]);
			while (tet[j + 1])
			{
				tet[j] = tet[j + 1];
				j++;
			}
			tet[j] = NULL;
		}
		else
			i++;
	}
	return (tet);
}

char	**del_veridots(char **tet)
{
	int i;
	int j;

	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j] == '.')
			j++;
		while (tet[i][j] == '#')
			j++;
		tet[i][j] = '\0';
		i++;
	}
	return (tet);
}

int		find_movelen(char **tet)
{
	int i;
	int j;
	int len;

	len = 4;
	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j] == '.')
			j++;
		if (len > j)
			len = j;
		i++;
	}
	return (len);
}

char	**go_back(char **tet, int len)
{
	int i;
	int j;

	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j] == '.' && tet[i][j])
			j++;
		while (tet[i][j] == '#')
		{
			tet[i][j - len] = tet[i][j];
			tet[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tet);
}
