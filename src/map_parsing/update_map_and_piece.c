/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_and_piece.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:20:02 by jtaylor           #+#    #+#             */
/*   Updated: 2020/01/15 17:20:14 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fetch_update_map_no_header(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	filler->map_in = (char **)malloc(sizeof(char *) * (filler->map_dim_y + 1));
	if (get_next_line(0, &line))
	{
		i = 0;
		filler->map_in[i] = ft_strdup(line + 4);
		free(line);
		while (++i < filler->map_dim_y)
		{
			get_next_line(0, &line);
			filler->map_in[i] = ft_strdup(line + 4);
			free(line);
		}
		filler->map_in[i] = 0;
	}
	else
		i = -1;
	return (i);
}

static int		fetch_new_map(t_filler *filler)
{
	int		i;

	i = 0;
	while (i < filler->map_dim_y)
	{
		free(filler->map[i]);
		free(filler->map_in[i++]);
	}
	free(filler->map_in);
	free(filler->map);
	i = fetch_update_map_no_header(filler);
	return (i);
}

static int		fetch_new_piece(t_filler *filler)
{
	int		i;

	i = 0;
	while (i < filler->piece_size_y)
		free(filler->piece[i++]);
	free(filler->piece);
	i = check_piece(filler);
	return (i);
}

int				re_fetch(t_filler *filler)
{
	int	i;

	i = fetch_new_map(filler);
	if (!i)
		return (i);
	i = fetch_new_piece(filler);
	if (!i)
		return (i);
	i = re_input_map_to_int_matrix(filler);
	if (i != 0)
		return (i);
	return (1);
}
