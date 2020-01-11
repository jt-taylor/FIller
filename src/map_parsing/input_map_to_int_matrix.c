/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_to_int_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:52:06 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/10 16:06:17 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	malloc_for_int_matrix(t_filler *filler)
{
	int		i;

	i = 0;
	if (!(filler->map =
				(int **)malloc(sizeof(int *) * (filler->map_dim_y + 1))))
		return (-1);
	while (i < filler->map_dim_y)
	{
		if (!(filler->map[i] =
					(int *)malloc(sizeof(int) * (filler->map_dim_x + 1))))
			return (-1);
		i++;
	}
	filler->map[i] = 0;
	return (0);
}

static int	input_map_to_int_values(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (filler->map_in[y])
	{
		x = 0;
		while (filler->map_in[y][x])
		{
			filler->map[y][x] = (char)(filler->map_in[y][x]) - 46;
			x++;
		}
		y++;
	}
	return (0);
}

static void	check_valid_map(t_filler *filler)
{
	int		i;
	int		j;

	if (filler->has_both_pieces)
		return ;
	i = 0;
	while (i < filler->map_dim_y)
	{
		j = 0;
		while (j < filler->map_dim_x)
		{
			if (filler->has_both_pieces ^ 1 && filler->map[i][j] == 33)
			{
				filler->has_both_pieces |= 1;
			}
			else if (filler->has_both_pieces ^ 2 && filler->map[i][j] == 42)
			{
				filler->has_both_pieces |= 2;
			}
			j++;
		}
		i++;
	}
	if (filler->has_both_pieces != 3)
		free_struct(filler);
}

int			re_input_map_to_int_matrix(t_filler *filler)
{
	int		i;

	i = 0;
	i = malloc_for_int_matrix(filler);
	if (i)
		return (i);
	i = input_map_to_int_values(filler);
	if (i)
		return (i);
	//check_valid_map(filler);
	return (0);
}

int			input_map_to_int_matrix(t_filler *filler)
{
	int		i;

	i = malloc_for_int_matrix(filler);
	if (i)
		return (i);
	i = input_map_to_int_values(filler);
	if (i)
		return (i);
	check_valid_map(filler);
	return (0);
}
