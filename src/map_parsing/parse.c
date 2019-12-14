/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:15:38 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/14 14:15:47 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

/* so it looks like most of the people seperate each component of the parsing
** functionality into seperate functions rather than reading everything at once
*/

/*
** Sample input
**
**	$$$ exec p1 : [./jtaylor.player]
**	Plateau 24 40:
**	    0123456789012345678901234567890123456789
**	000 ........................................
**	001 ........................................
**	002 ........................................
**	003 ...O....................................
**	004 ........................................
**	005 ........................................
**	006 ........................................
**	007 ........................................
**	008 ........................................
**	009 ........................................
**	010 ........................................
**	011 ........................................
**	012 ........................................
**	013 ........................................
**	014 ........................................
**	015 ........................................
**	016 ........................................
**	017 ........................................
**	018 ........................................
**	019 ................................X.......
**	020 ........................................
**	021 ........................................
**	022 ........................................
**	023 ........................................
**	Piece 2 3:
**	...
**	**.
*/

/*
** parses this component of the input
** $$$ exec p1 : [./jtaylor.player]
*/
static int		check_exec(t_filler *filler)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line))
	{
		if (ft_strstr(line, "jtaylor.player"))
		{
			if (ft_strstr(line, "p1"))
				i = 1;
			else if (ft_strstr(line, "p2"))
				i = 2;
			else
				i = -1;
		}
		else
			i = -1;
	}
	else
		i = -1;
	free(line);
	filler->player = i;
	return (i);
}


/*
** parses this part of the input
**  Piece 2 3:
**  ...
**  **.
*/

static int		check_piece_header(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	filler->piece_size_y = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (line[++i])
		filler->piece_size_x = ft_atoi(line + i);
	free(line);
	return (i);
}

static int		check_piece(t_filler *filler)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line))
	{
		i = check_piece_header(filler, line);
		if (!i)
			return (i);
		i = 0;
		filler->piece =
			(char **)malloc(sizeof(char *) * (filler->piece_size_y + 1));
		while (i < filler->piece_size_y)
		{
			get_next_line(0, &line);
			filler->piece[i] = line;
			i++;
		}
		filler->piece[i] = NULL;
	}
	else
		i = -1;
	return (i);
}

/*
** This calls the other parsing functions
*/

int				filler_parser(t_filler *filler)
{
	int		i;

	i = check_exec(filler);
	if (!i)
		return (i);
	i = check_map(filler);
	if (!i)
		return (i);
	i = check_piece(filler);
	if (!i)
		return (i);
	sleep(100);
	return (i);
}
