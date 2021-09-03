/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:09:56 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 19:40:06 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spr_drcalc(t_all *a)
{
	if (a->sprite.draw_start_y < 0)
		a->sprite.draw_start_y = 0;
	a->sprite.draw_end_y = a->sprite.sprite_h / 2 + a->game.h / 2;
	if (a->sprite.draw_end_y >= a->game.h)
		a->sprite.draw_end_y = (a->game.h - 1);
	a->sprite.sprite_w = (int)fabs((float)a->game.w / a->sprite.trans_y);
	a->sprite.draw_start_x = (-a->sprite.sprite_w / 2 + a->sprite.sprite_scrx);
	if (a->sprite.draw_start_x < 0)
		a->sprite.draw_start_x = 0;
	a->sprite.draw_end_x = (a->sprite.sprite_w / 2 + a->sprite.sprite_scrx);
	if (a->sprite.draw_end_x >= a->game.w)
		a->sprite.draw_end_x = a->game.w - 1;
	a->sprite.stripe = a->sprite.draw_start_x;
}

void	spr_calc(t_all *a, int i, int *order)
{
	a->sprite.sprite_x = a->game.s[order[i]]->x - a->game.pos_x;
	a->sprite.sprite_y = a->game.s[order[i]]->y - a->game.pos_y;
	a->sprite.inv_det = 1.0f / (a->game.plane_x * a->game.dir_y -
	a->game.dir_x * a->game.plane_y);
	a->sprite.trans_x = a->sprite.inv_det *
	(a->game.dir_y * a->sprite.sprite_x -
	a->game.dir_x * a->sprite.sprite_y);
	a->sprite.trans_y = a->sprite.inv_det
	* (-a->game.plane_y * a->sprite.sprite_x +
	a->game.plane_x * a->sprite.sprite_y);
	a->sprite.sprite_scrx = (int)((a->game.w / 2) *
	(1 + a->sprite.trans_x / a->sprite.trans_y));
	a->sprite.sprite_h = (int)fabs((float)a->game.h / a->sprite.trans_y);
	a->sprite.draw_start_y = (-a->sprite.sprite_h / 2 + a->game.h / 2);
}

void	draw_stripe(t_all *a, int *addr, int sp_h)
{
	int color;

	a->sprite.d = a->sprite.y * 256 -
	a->game.h * 128 + a->sprite.sprite_h * 128;
	a->sprite.tex_y = ((a->sprite.d *
	sp_h) / a->sprite.sprite_h) / 256;
	color = addr[a->sprite.tex_y
	* a->game.images[4]->line_l / 4 + a->sprite.tex_x];
	if ((color & 0x00FFFFFF) != 0)
		((int *)a->img.addr)[a->sprite.y * a->img.line_l /
		4 + a->sprite.stripe] = color;
}

void	draw_spr(t_all *a, int *addr, int sp_w, int sp_h)
{
	while (a->sprite.stripe < a->sprite.draw_end_x)
	{
		a->sprite.tex_x = (int)(256 * (a->sprite.stripe -
		(-a->sprite.sprite_w / 2 + a->sprite.sprite_scrx))
		* sp_w / a->sprite.sprite_w) / 256;
		if (a->sprite.trans_y > 0 && a->sprite.stripe > 0 && a->sprite.stripe
		< a->game.w && a->sprite.trans_y < a->game.zbuf[a->sprite.stripe] &&
		a->sprite.tex_x < a->game.images[4]->img_w && a->sprite.tex_y <
		a->game.images[4]->img_h)
		{
			a->sprite.y = a->sprite.draw_start_y;
			while (a->sprite.y < a->sprite.draw_end_y)
			{
				draw_stripe(a, addr, sp_h);
				a->sprite.y++;
			}
		}
		a->sprite.stripe++;
	}
}

int		calc_sprite(t_all *a)
{
	int		i;
	int		order[a->pars.spr_num];
	float	dist[a->pars.spr_num];

	sort_ord(order, dist, a->pars.spr_num, a);
	i = a->pars.spr_num;
	while (--i >= 0)
	{
		if (dist[i] > 0.1)
		{
			spr_calc(a, i, order);
			spr_drcalc(a);
			draw_spr(a, a->game.images[4]->addr,
			a->game.images[4]->img_w, a->game.images[4]->img_h);
		}
	}
	return (0);
}
