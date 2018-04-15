/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:40:33 by hjo               #+#    #+#             */
/*   Updated: 2018/03/26 17:40:34 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		***free_3d_array(void ***buf)
{
	int i;
	int j;

	i = 0;
	while (buf[i])
	{
		j = 0;
		while (buf[i][j])
		{
			free(buf[i][j]);
			j++;
		}
		free(buf[i]);
		i++;
	}
	free(buf);
	buf = NULL;
	return (buf);
}

static int	get_slen(char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[2])
	{
		if ((*s == '\n') && (s[1] == '\n') && s[2] != '\0')
			len++;
		s++;
	}
	return (len);
}

char		***prepare(char ***buf)
{
	int len;
	int i;

	i = 0;
	while (buf[i])
	{
		len = find_movelen(buf[i]);
		buf[i] = del_horidots(buf[i]);
		if (len > 0)
			buf[i] = go_back(buf[i], len);
		buf[i] = del_veridots(buf[i]);
		i++;
	}
	return (buf);
}

char		***get_sqaures(char *s)
{
	struct s_square	square;
	int				i;

	square.len = get_slen(s) + 1;
	square.out = ft_memalloc((square.len + 1) * sizeof(char **));
	if (!square.out)
		return (NULL);
	square.current = 0;
	i = 0;
	while (i < square.len && *s)
	{
		ft_bzero(square.tmp, 21);
		ft_strncpy(square.tmp, s, 20);
		square.out[i] = ft_strsplit(square.tmp, '\n');
		if (!square.out[i])
			return (NULL);
		i++;
		s += 21;
	}
	square.out[i] = NULL;
	return (square.out);
}

void		add_ints(int *one, int *two)
{
	*one += 1;
	*two += 1;
}
