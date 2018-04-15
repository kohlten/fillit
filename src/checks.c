/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:40:13 by hjo               #+#    #+#             */
/*   Updated: 2018/03/26 17:40:14 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 1. check thru all the spots.
** 2. if dot, ignore.
** 3. if hash, check if all 4 spots around it are valid.
** 4. check if it is a valid spot (not out of board).
** 5. if it is a valid spot, check if it is a hash.
** 6. if it is a hash, add 1 to that spot. at all spots around it.
*/

static int	check_around(char **str)
{
	int i;
	int j;
	int score;

	i = -1;
	score = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '#')
			{
				if (i > 0 && str[i - 1][j] == '#')
					score++;
				if (j > 0 && str[i][j - 1] == '#')
					score++;
				if (j < 3 && str[i][j + 1] == '#')
					score++;
				if (i < 3 && str[i + 1][j] == '#')
					score++;
			}
		}
	}
	return (score);
}

static int	square_form(char **str)
{
	int i;
	int j;
	int running;

	i = -1;
	running = 1;
	while (running && str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '#')
			{
				running = 0;
				break ;
			}
		}
	}
	if (j > 2 || i > 2)
		return (0);
	if (str[i][j + 1] == '#' && str[i + 1][j] == '#'
		&& str[i + 1][j + 1] == '#')
		return (1);
	return (0);
}

static int	valid_tets(char ***tet)
{
	int score;
	int i;
	int j;

	i = 0;
	while (tet[i])
	{
		j = -1;
		while (tet[i][++j])
			if (ft_strlen(tet[i][j]) != 4)
				return (0);
		score = check_around(tet[i]);
		if ((square_form(tet[i++]) && score == 8) || score == 6)
			continue ;
		else
			return (0);
	}
	return (1);
}

static int	file_is_valid(char *s)
{
	int count;

	count = 1;
	while (*s)
	{
		if (count % 5 == 0 && *s == '\n')
			return (0);
		else if (count % 20 == 0)
		{
			if (*s != '\n' || s[1] != '\n')
				return (0);
		}
		else if (*s != '.' && *s != '#' && *s != '\n')
			return (0);
		s++;
		count++;
	}
	return (1);
}

char		***init(char *fn)
{
	char *in;
	char ***buf;

	in = ft_open(fn);
	if (!in)
		return (NULL);
	if ((ft_strlen(in) + 1) % 21 != 0 || file_is_valid(in))
	{
		free(in);
		return (NULL);
	}
	buf = get_sqaures(in);
	free(in);
	if (!buf)
		return (NULL);
	if (!valid_tets(buf))
		return (NULL);
	return (buf);
}
