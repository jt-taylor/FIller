/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_specific_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:06:05 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 12:10:12 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** these two parse this component of the input
** Plateau 24 40:
**     0123456789012345678901234567890123456789
** 000 ........................................
** 001 ........................................
** 002 ........................................
** 003 ...O....................................
** 004 ........................................
** 005 ..........X.............................
** 006 ........................................
** ...
*/

/*
** this parses this part of the input
**
** Plateau 24 40:
*/

static int		check_map_header(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line))
	{
		while (!ft_isdigit(line[i]))
			i++;
		if (!line[i])
			i = -1;
		else if (ft_isdigit(line[i]))
		{
			filler->map_dim_y = ft_atoi((line + i));
			while (ft_isdigit(line[i]))
				i++;
			i++;
			if (ft_isdigit(line[i]))
				filler->map_dim_x = ft_atoi(line + i);
		}
	}
	else
		i = -1;
	free(line);
	return (i);
}

/*
** parses this part of the input
**     0123456789012345678901234567890123456789
** 000 ........................................
** 001 ........................................
** 002 ........................................
** 003 ...O....................................
** 004 ........................................
** 005 ..........X.............................
** 006 ........................................
** ...
*/

int				check_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = check_map_header(filler);
	if (!i)
		return (i);
	filler->map_in = (char **)malloc(sizeof(char *) * (filler->map_dim_y + 1));
	if (get_next_line(0, &line))
	{
		free(line);
		i = 0;
		while (i < filler->map_dim_y)
		{
			get_next_line(0, &line);
			filler->map_in[i] = ft_strdup(line + 4);
			free(line);
			i++;
		}
		filler->map_in[i] = 0;
	}
	else
		i = -1;
	return (i);
}
