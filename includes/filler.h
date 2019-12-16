/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:18:09 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/16 11:39:29 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

typedef struct	s_filler
{
	char	**piece;
	char	**map_in;
	int		**map;
	int		last_x;
	int		last_y;
	int		map_dim_x;
	int		map_dim_y;
	int		piece_size_x;
	int		piece_size_y;
	int		player;
}				t_filler;

/*
** prototypes
*/

int				filler_parser(t_filler *filler);
int				check_map(t_filler *filler);
int				check_piece(t_filler *filler);
int				re_fetch(t_filler *filler);
int				input_map_to_int_matrix(t_filler *filler);
#endif
