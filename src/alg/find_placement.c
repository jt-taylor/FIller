/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_placement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:16:45 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/18 15:29:53 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** I would like to make this a much better alg
** but for now this is just going to be real simple filling alg
** TODO : implement the jeat map and weight based on that
*/

static int	print_placement(t_filler *filler)
{
	ft_printf("%d %d\n", filler->point.y, filler->point.x);
	//ft_dprintf(2,"%d %d\n", filler->point.y, filler->point.x);
	filler->point.x = 0;
	filler->point.y = 0;
	return (1);
}

int			find_placement(t_filler *filler)
{
	filler->point.x = 0;
	filler->point.y = 0;
	while (filler->point.y < filler->map_dim_y)
	{
		filler->point.x = 0;
		while (filler->point.x < filler->map_dim_x)
		{
			if (check_if_valid_position(filler,
					filler->point.x, filler->point.y))
			{
				//ft_dprintf(2,"%d %d\n", filler->point.y, filler->point.x);
				return (print_placement(filler));
			}
			filler->point.x++;
		}
		filler->point.y++;
	}
	//ft_dprintf(2, "in find");
	free_struct(filler);
	exit(0);
}
