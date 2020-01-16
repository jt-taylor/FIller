/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:40:16 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:24:19 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			inner_check(t_filler *filler)
{
	int	ret;

	ret = 0;
	if (filler->player == 1 && filler->p1_count == 1 && filler->p2_count == 0)
		ret = 1;
	else if (filler->player == 2 && filler->p1_count == 0 &&
			filler->p2_count == 1)
		ret = 2;
	else
		ret = -1;
	filler->p1_count = 0;
	filler->p2_count = 0;
	return (ret);
}

static inline void	check_pieces(t_filler *filler, int x, int y, int yoff)
{
	int xoff;

	xoff = 0;
	while (xoff < filler->piece_size_x)
	{
		if (filler->piece[yoff][xoff] == '*' &&
			(filler->map[y + yoff][x + xoff] == 33 ||
			filler->map[y + yoff][x + xoff] == 65))
			filler->p1_count += 1;
		else if (filler->piece[yoff][xoff] == '*' &&
			(filler->map[y + yoff][x + xoff] == 42 ||
			filler->map[y + yoff][x + xoff] == 74))
			filler->p2_count += 1;
		xoff++;
	}
}

int					check_if_valid_position(t_filler *filler, int x, int y)
{
	int		yoff;

	filler->p1_count = 0;
	filler->p2_count = 0;
	if (y + filler->piece_size_y >= filler->map_dim_y ||
		x + filler->piece_size_x >= filler->map_dim_x)
		return (-1);
	yoff = 0;
	while (yoff < filler->piece_size_y)
	{
		if (filler->piece[yoff])
			check_pieces(filler, x, y, yoff);
		yoff++;
	}
	return (inner_check(filler));
}
