/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_placement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:16:45 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:22:28 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			print_placement(t_filler *filler)
{
	ft_printf("%d %d\n", filler->point.y, filler->point.x);
	filler->point.x = 0;
	filler->point.y = 0;
	return (1);
}

static int	find_x_prio(t_filler *filler)
{
	if (filler->dir_x > 0)
	{
		if (filler->dir_y > 0)
			return (find_x_pos_y_pos(filler));
		else
			return (find_x_pos_y_neg(filler));
	}
	else
	{
		if (filler->dir_y > 0)
			return (find_x_neg_y_pos(filler));
		else
			return (find_x_neg_y_neg(filler));
	}
}

static int	find_y_prio(t_filler *filler)
{
	if (filler->dir_y > 0)
	{
		if (filler->dir_x > 0)
			return (find_y_pos_x_pos(filler));
		else
			return (find_y_pos_x_neg(filler));
	}
	else
	{
		if (filler->dir_x > 0)
			return (find_y_neg_x_pos(filler));
		else
			return (find_y_neg_x_neg(filler));
	}
}

int			find_placement(t_filler *filler)
{
	if (filler->dir_prio == 1)
		return (find_y_prio(filler));
	else
		return (find_x_prio(filler));
}
