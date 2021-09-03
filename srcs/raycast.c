/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:29:41 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:20:39 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_texture(t_all *a, int p)
{
	a->game.line_h = (int)(a->game.h / a->game.pwd);
	a->game.start = -a->game.line_h / 2 + a->game.h / 2;
	if (a->game.start < 0)
		a->game.start = 0;
	a->game.end = a->game.line_h / 2 + a->game.h / 2;
	if (a->game.end >= a->game.h)
		a->game.end = a->game.h - 1;
	if (a->game.side == 0)
		a->game.wall_x = a->game.pos_y + a->game.pwd * a->game.rdy;
	else
		a->game.wall_x = a->game.pos_x + a->game.pwd * a->game.rdx;
	a->game.wall_x -= floor((a->game.wall_x));
	a->game.tex_x = (int)fabs((a->game.wall_x *
	(float)(a->game.images[p]->img_w)));
	if (a->game.side == 0 && a->game.rdx > 0)
		a->game.tex_x = a->game.images[p]->img_w - a->game.tex_x - 1;
	if (a->game.side == 1 && a->game.rdy < 0)
		a->game.tex_x = a->game.images[p]->img_w - a->game.tex_x - 1;
}

void	calc_texcolor(t_all *a, int x, int p)
{
	int	y;

	a->game.step = 1.0f * a->game.images[p]->img_h / a->game.line_h;
	a->game.tex_pos = (a->game.start - a->game.h / 2 +
	a->game.line_h / 2) * a->game.step;
	y = a->game.start;
	while (y < a->game.end)
	{
		a->game.tex_y = (int)a->game.tex_pos &
		(a->game.images[p]->img_h - 1);
		a->game.tex_pos += a->game.step;
		((int *)a->img.addr)[y * a->img.line_l / 4 + x] =
		((int *)a->game.images[p]->addr)[a->game.tex_y *
		a->game.images[p]->line_l / 4 + a->game.tex_x];
		y++;
	}
}

void	calc_dir(t_all *a)
{
	if (a->game.rdx < 0)
	{
		a->game.step_x = -1;
		a->game.sdx = (a->game.pos_x - a->game.map_x) * a->game.ddx;
	}
	else
	{
		a->game.step_x = 1;
		a->game.sdx = (a->game.map_x + 1.0 - a->game.pos_x) * a->game.ddx;
	}
	if (a->game.rdy < 0)
	{
		a->game.step_y = -1;
		a->game.sdy = (a->game.pos_y - a->game.map_y) * a->game.ddy;
	}
	else
	{
		a->game.step_y = 1;
		a->game.sdy = (a->game.map_y + 1.0 - a->game.pos_y) * a->game.ddy;
	}
}

void	calc(t_all *a)
{
	int	x;
	int	p;

	x = 0;
	while (x < a->game.w)
	{
		init_calc(a, x);
		calc_dir(a);
		p = perform_dda(a, x);
		calc_texture(a, p);
		draw_cell(a, x);
		calc_texcolor(a, x, p);
		draw_floor(a, x);
		x++;
	}
	if (a->pars.spr_num > 0)
		calc_sprite(a);
}
