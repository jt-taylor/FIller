/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:40:16 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/10 14:25:03 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	dump_struct_contents(t_filler *filler, int fd);

static int	inner_check(t_filler *filler)
{
	int	ret;

	ret = 0;
	if (filler->player == 1 && filler->p1_count == 1 && filler->p2_count == 0)
		ret = 1;
	else if (filler->player == 2 && filler->p1_count == 0 && filler->p2_count == 1)
		ret = 2;
	else
		ret = -1;
	//
	//ft_dprintf(2, "p1_count: %d\t\tp2_count: %d", filler->p1_count, filler->p2_count);
	//ft_dprintf(2, "ret_value == %d\n", ret);
	filler->p1_count = 0;
	filler->p2_count = 0;
	return (ret);
}

static inline void	check_pieces(t_filler *filler, int x, int y, int yoff)
{
	//dump_struct_contents(filler, 2);
	int xoff;
		//	ft_dprintf(2, "checking::'%c'\t", filler->piece[yoff][xoff]);
		//	ft_dprintf(2, "and::'%d'\n", filler->map[y + yoff][x + xoff]);
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

int	check_if_valid_position(t_filler *filler, int x, int y)
{
	int		yoff;

	if (y + filler->piece_size_y >= filler->map_dim_y ||
		x + filler->piece_size_x >= filler->map_dim_x)
		return (-1);
	yoff = 0;
	while (yoff < filler->piece_size_y)
	{
		check_pieces(filler, x, y, yoff);
		if (filler->p1_count >= 2 || filler->p2_count >= 2)
			return (-1);
		yoff++;
	}
	//
	//int i = inner_check(filler);
	//ft_dprintf(2, "ret == %d", i);
	//
	//return (i);
	return (inner_check(filler));
}