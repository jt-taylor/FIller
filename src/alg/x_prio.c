/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_prio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:07:23 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 16:19:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_x_neg_y_neg(t_filler *filler)
{
	//ft_dprintf(2, "x_neg_y_neg");
	filler->point.y = filler->map_dim_y - 1;
	filler->point.x = filler->map_dim_x - 1;
	while (filler->point.x > -1)
	{
		filler->point.y = filler->map_dim_y - 1;
		while (filler->point.y > -1)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.y--;
		}
		filler->point.x--;
	}
	free_struct(filler);
	exit(0);
}

int		find_x_neg_y_pos(t_filler *filler)
{
	//ft_dprintf(2, "x_neg_y_pos");
	filler->point.y = 0;
	filler->point.x = filler->map_dim_x - 1;
	while (filler->point.x > -1)
	{
		filler->point.y = 0;
		while (filler->point.y < filler->map_dim_y)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.y++;
		}
		filler->point.x--;
	}
	free_struct(filler);
	exit(0);
}
int		find_x_pos_y_neg(t_filler *filler)
{
	//ft_dprintf(2, "x_pos_y_neg");
	filler->point.y = filler->map_dim_y - 1;
	filler->point.x = 0;
	while (filler->point.x < filler->map_dim_x)
	{
		filler->point.y = filler->map_dim_y - 1;
		while (filler->point.y > -1)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.y--;
		}
		filler->point.x++;
	}
	free_struct(filler);
	exit(0);
}

int		find_x_pos_y_pos(t_filler *filler)
{
	//ft_dprintf(2, "x_pos_y_pos");
	filler->point.y = 0;
	filler->point.x = 0;
	while (filler->point.x < filler->map_dim_x)
	{
		filler->point.y = 0;
		while (filler->point.y < filler->map_dim_y)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y) > 0)
				return (print_placement(filler));
			filler->point.y++;
		}
		filler->point.x++;
	}
	free_struct(filler);
	exit(0);
}

