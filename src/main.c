/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:27:51 by jtaylor           #+#    #+#             */
/*   Updated: 2019/12/14 13:48:46 by jtaylor          ###   ########.fr       */
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

int		main(void)
{
	t_filler		filler;

	set_struct_val_zero(&filler);
	filler_parser(&filler);
	return (0);
}
