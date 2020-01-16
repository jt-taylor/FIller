/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:02:43 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:21:02 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** todo :: generic matrix(matrices(?)) free function
*/

static inline void	filler_free_map(int **map)
{
	int		i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static inline void	filler_free_map_in(char **map_in)
{
	int		i;

	i = 0;
	while (map_in[i])
		free(map_in[i++]);
	free(map_in);
}

static inline void	filler_free_piece(char **piece)
{
	int	i;

	i = 0;
	while (piece[i])
		free(piece[i++]);
	free(piece);
}

void				free_struct(t_filler *filler)
{
	filler_free_map(filler->map);
	filler_free_map_in(filler->map_in);
	filler_free_piece(filler->piece);
	exit(1);
}
