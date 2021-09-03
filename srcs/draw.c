/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:37:34 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:20:28 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_all *a, int x)
{
	int y;

	y = a->game.end;
	while (y < a->game.h)
	{
		((int *)a->img.addr)[y * a->img.line_l / 4 + x] = a->game.color_f;
		y++;
	}
}

void	draw_cell(t_all *a, int x)
{
	int y;

	y = 0;
	while (y < a->game.start)
	{
		((int *)a->img.addr)[y * a->img.line_l / 4 + x] = a->game.color_c;
		y++;
	}
}
