/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_prio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:38 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:23:03 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_y_neg_x_neg(t_filler *filler)
{
	filler->point.x = filler->map_dim_x - 1;
	filler->point.y = filler->map_dim_y - 1;
	while (filler->point.y > -1)
	{
		filler->point.x = filler->map_dim_x - 1;
		while (filler->point.x > -1)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.x--;
		}
		filler->point.y--;
	}
	free_struct(filler);
	exit(0);
}

int		find_y_neg_x_pos(t_filler *filler)
{
	filler->point.x = 0;
	filler->point.y = filler->map_dim_y - 1;
	while (filler->point.y > -1)
	{
		filler->point.x = 0;
		while (filler->point.x < filler->map_dim_x)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.x++;
		}
		filler->point.y--;
	}
	free_struct(filler);
	exit(0);
}

int		find_y_pos_x_neg(t_filler *filler)
{
	filler->point.x = filler->map_dim_x - 1;
	filler->point.y = 0;
	while (filler->point.y < filler->map_dim_y)
	{
		filler->point.x = filler->map_dim_x - 1;
		while (filler->point.x > -1)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.x--;
		}
		filler->point.y++;
	}
	free_struct(filler);
	exit(0);
}

int		find_y_pos_x_pos(t_filler *filler)
{
	filler->point.x = 0;
	filler->point.y = 0;
	while (filler->point.y < filler->map_dim_y)
	{
		filler->point.x = 0;
		while (filler->point.x < filler->map_dim_x)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.x++;
		}
		filler->point.y++;
	}
	free_struct(filler);
	exit(0);
}
