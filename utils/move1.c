/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:06:56 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:25:30 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_all *a)
{
	if (a->pars.map[(int)(a->game.pos_x + a->game.dir_x *
	a->game.ms)][(int)(a->game.pos_y)] != '1')
		a->game.pos_x += a->game.dir_x * a->game.ms;
	if (a->pars.map[(int)(a->game.pos_x)][(int)(a->game.pos_y +
	a->game.dir_y * a->game.ms)] != '1')
		a->game.pos_y += a->game.dir_y * a->game.ms;
}

void	go_backward(t_all *a)
{
	if (a->pars.map[(int)(a->game.pos_x - a->game.dir_x *
	a->game.ms)][(int)(a->game.pos_y)] != '1')
		a->game.pos_x -= a->game.dir_x * a->game.ms;
	if (a->pars.map[(int)(a->game.pos_x)][(int)(a->game.pos_y -
	a->game.dir_y * a->game.ms)] != '1')
		a->game.pos_y -= a->game.dir_y * a->game.ms;
}

void	go_lef(t_all *a)
{
	if (a->pars.map[(int)(a->game.pos_x - a->game.plane_x *
	a->game.ms)][(int)(a->game.pos_y)] != '1')
		a->game.pos_x -= a->game.plane_x * a->game.ms;
	if (a->pars.map[(int)(a->game.pos_x)][(int)(a->game.pos_y -
	a->game.plane_y * a->game.ms)] != '1')
		a->game.pos_y -= a->game.plane_y * a->game.ms;
}

void	go_rht(t_all *a)
{
	if (a->pars.map[(int)(a->game.pos_x + a->game.plane_x *
	a->game.ms)][(int)(a->game.pos_y)] != '1')
		a->game.pos_x += a->game.plane_x * a->game.ms;
	if (a->pars.map[(int)(a->game.pos_x)][(int)(a->game.pos_y +
	a->game.plane_y * a->game.ms)] != '1')
		a->game.pos_y += a->game.plane_y * a->game.ms;
}

void	go_left(t_all *a)
{
	float olddir_x;
	float oldplane_x;

	olddir_x = a->game.dir_x;
	a->game.dir_x = a->game.dir_x * cos(-a->game.rs) -
	a->game.dir_y * sin(-a->game.rs);
	a->game.dir_y = olddir_x * sin(-a->game.rs) +
	a->game.dir_y * cos(-a->game.rs);
	oldplane_x = a->game.plane_x;
	a->game.plane_x = a->game.plane_x * cos(-a->game.rs) -
	a->game.plane_y * sin(-a->game.rs);
	a->game.plane_y = oldplane_x * sin(-a->game.rs) +
	a->game.plane_y * cos(-a->game.rs);
}
