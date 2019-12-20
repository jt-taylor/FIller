/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:18:09 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/19 11:46:50 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

/*
** so we can return the x y cord
*/

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_filler
{
	char	**piece;
	char	**map_in;
	int		**map;
	int		last_x;
	int		last_xy;
	int		last_o;
	int		last_oy;
	int		map_dim_x;
	int		map_dim_y;
	int		piece_size_x;
	int		piece_size_y;
	int		player;
	int		has_both_pieces;
	int		check_start_x;
	int		check_start_y;
	int		p1_count;
	int		p2_count;
	t_point	point;
}				t_filler;

/*
** prototypes
*/

int				filler_parser(t_filler *filler);
int				check_map(t_filler *filler);
int				check_piece(t_filler *filler);
int				re_fetch(t_filler *filler);
int				input_map_to_int_matrix(t_filler *filler);
int				re_input_map_to_int_matrix(t_filler *filler);
void			free_struct(t_filler *filler);
int				find_closest_point(t_filler *filler);
int				check_if_valid_position(t_filler *filler, int x, int y);
int				find_placement(t_filler *filler);

#endif
