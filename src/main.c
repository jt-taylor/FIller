/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:27:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/14 21:34:14 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "Filler.h"

void	set_struct_val_zero(t_filler *filler)
{
	filler->piece = NULL;
	filler->map_in = NULL;
	filler->map = NULL;
	filler->last_x = -1;
	filler->last_y = -1;
	filler->map_dim_x = -1;
	filler->map_dim_y = -1;
	filler->piece_size_y = -1;
	filler->piece_size_x = -1;
	filler->player = -1;
}

static void	dump_struct_contents(t_filler *filler, int fd)
{
	int		i;

	i = 0;
	ft_dprintf(fd, "\nDUMP::\n\nvalues:\nlast_x\t%d\nlast_y\t%d\nmap_dim_x\t%d\nmap_dim_y\
		\t%d\npiece_size_y\t%d\npiece_size_x\t%d\nplayer\t%d\n", filler->last_x,
		filler->last_y, filler->map_dim_x, filler->map_dim_y,
		filler->piece_size_y, filler->piece_size_x, filler->player);
	ft_dprintf(fd ,"Piece:\n");
	while (filler->piece[i])
		//ft_putendl_fd(filler->piece[i++], fd);
		ft_dprintf(fd, "%s\n", filler->piece[i++]);
	i = 0;
	ft_dprintf(fd, "\nMap_in:\n");
	while (filler->map_in[i])
		//ft_putendl_fd(filler->map_in[i++], fd);
		ft_dprintf(fd, "%s\n", filler->map_in[i++]);
	ft_dprintf(fd, "Map: fill me in");
}


int		main(void)
{
	t_filler		filler;

	set_struct_val_zero(&filler);
	filler_parser(&filler);
	dump_struct_contents(&filler, 2);
	sleep(100);
	return (0);
}
