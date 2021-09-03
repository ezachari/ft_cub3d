/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:03:09 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 13:20:15 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_vision(float *x, float *y, float setx, float sety)
{
	*x = setx;
	*y = sety;
}

void	vision(t_all *all)
{
	if (all->pars.so)
	{
		set_vision(&all->game.dir_x, &all->game.plane_y, 1.0, -0.66);
		all->game.dir_y = 0.0;
		all->game.plane_x = 0.0;
	}
	if (all->pars.no)
	{
		set_vision(&all->game.dir_x, &all->game.plane_y, -1.0, 0.66);
		all->game.dir_y = 0.0;
		all->game.plane_x = 0.0;
	}
	if (all->pars.we)
	{
		set_vision(&all->game.dir_y, &all->game.plane_x, -1.0, -0.66);
		all->game.dir_x = 0.0;
		all->game.plane_y = 0.0;
	}
	if (all->pars.ea)
	{
		set_vision(&all->game.dir_y, &all->game.plane_x, 1.0, 0.66);
		all->game.dir_x = 0.0;
		all->game.plane_y = 0.0;
	}
}

void	init_calc(t_all *a, int x)
{
	a->game.cx = (2 * x) / (float)a->game.w - 1;
	a->game.rdx = a->game.dir_x + a->game.plane_x * a->game.cx;
	a->game.rdy = a->game.dir_y + a->game.plane_y * a->game.cx;
	a->game.map_x = (int)a->game.pos_x;
	a->game.map_y = (int)a->game.pos_y;
	a->game.ddx = fabs(1.0f / a->game.rdx);
	a->game.ddy = fabs(1.0f / a->game.rdy);
	a->game.hit = 0;
}

void	ft_mlx(t_all *all)
{
	mlx_loop_hook(all->game.mlx, &game_loop, all);
	mlx_hook(all->game.win, 2, 0, &key_press, all);
	mlx_hook(all->game.win, 3, 0, &key_release, all);
	mlx_hook(all->game.win, 17, 0, &close_window, all);
	mlx_loop(all->game.mlx);
}
