/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:47:15 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/17 11:08:34 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


/*
** finds the last placed piece denoted in the vm by x or o
** i really should rename the last_y to last_o for clarity's sake
*/

static void	set_last_x_or_o(t_filler *filler, int which, int x, int y)
{
	if (which == 'x')
	{
		filler->last_x = x;
		filler->last_xy = y;
	}
	else
	{
		filler->last_o = x;
		filler->last_oy = y;
	}
}

static void	find_last_placement(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	filler->last_x = -1;
	filler->last_xy = -1;
	filler->last_o = -1;
	filler->last_oy = -1;
	while (i < filler->map_dim_y)
	{
		j = 0;
		while (j < filler->map_dim_x)
		{
			if (filler->map[i][j] == 65)
				set_last_x_or_o(filler, 'x', j, i);
			if (filler->map[i][j] == 74)
				set_last_x_or_o(filler, 'o', j, i);
			j++;
		}
		i++;
	}
}

/*
** this will attempt to find the closest point to the other players pieces
*/

static void	start_check_at_middle_of_map(t_filler *filler)
{
	filler->check_start_x = (filler->map_dim_x / 2);
	filler->check_start_y =  (filler->map_dim_y / 2);
}

static void	only_one_piece_placed(t_filler *filler)
{
	if (filler->player == 1)
	{
		filler->check_start_x = filler->last_o;
		filler->check_start_y = filler->last_oy;
	}
	else if (filler->player == 2)
	{
		filler->check_start_x = filler->last_x;
		filler->check_start_y = filler->last_xy;
	}
}

static void	both_placed_pieces(t_filler *filler)
{
	int		dif;

	dif = filler->last_x - filler->last_o;
	if (dif < 0)
		dif *= -1;
	filler->check_start_x = (filler->last_x > filler->last_o) ?
		filler->last_x - (dif / 2) : filler->last_o - (dif / 2);
	dif = filler->last_xy - filler->last_oy;
	if (dif < 0)
		dif *= -1;
	filler->check_start_y = (filler->last_xy > filler->last_oy) ?
		filler->last_xy - (dif / 2) : filler->last_oy - (dif / 2);
}

int		find_closest_point(t_filler *filler)
{
	find_last_placement(filler);
	if (!filler->last_x && !filler->last_xy &&
			!filler->last_o && !filler->last_oy)
		start_check_at_middle_of_map(filler);
	else if ((!filler->last_x || !filler->last_xy) ||
			(!filler->last_o || filler->last_oy))
		only_one_piece_placed(filler);
	else
		both_placed_pieces(filler);
	return (0);
}
