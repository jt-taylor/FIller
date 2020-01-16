/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_dir_to_fill_in.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:23:37 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:11:35 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline void	inner(t_point *player, int x, int y)
{
	player->x = x;
	player->y = y;
}

static void			chose_direction(t_filler *filler, t_point *mp, t_point *op)
{
	int		dif_x;
	int		dif_y;

	dif_x = op->x - mp->x;
	dif_y = op->y - mp->y;
	if (dif_x < 0 && dif_y < 0)
		filler->dir_prio = (dif_y > dif_x) ? -1 : 1;
	else
		filler->dir_prio = (dif_y > dif_x) ? 1 : -1;
	filler->dir_x = dif_x * -1;
	filler->dir_y = dif_y * -1;
}

void				chose_direction_to_fill_in(t_filler *filler)
{
	char		target;
	t_point		player_with_o;
	t_point		player_with_x;
	int			x;
	int			y;

	target = (filler->player == 1) ? 'X' : 'O';
	y = 0;
	while (y < filler->map_dim_y)
	{
		x = 0;
		while (x < filler->map_dim_x)
		{
			if (filler->map[y][x] != 0)
				(filler->map[y][x] == 'O' - 46) ? inner(&player_with_o, x, y) :
					inner(&player_with_x, x, y);
			x++;
		}
		y++;
	}
	(filler->player == 1) ? chose_direction(filler,
			&player_with_o, &player_with_x) :
			chose_direction(filler, &player_with_x, &player_with_o);
}
