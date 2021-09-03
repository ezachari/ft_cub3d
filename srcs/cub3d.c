/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:19:13 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 14:09:00 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			calc_pol(t_all *all, int x)
{
	int	p;

	p = 0;
	if (all->game.side == 0)
	{
		all->game.pwd = (all->game.map_x - all->game.pos_x + \
		(1 - all->game.step_x) / 2) / all->game.rdx;
		if (all->game.step_x < 0)
			p = 0;
		else if (all->game.step_x > 0)
			p = 1;
	}
	else if (all->game.side == 1)
	{
		all->game.pwd = (all->game.map_y - all->game.pos_y + \
		(1 - all->game.step_y) / 2) / all->game.rdy;
		if (all->game.step_y < 0)
			p = 2;
		else if (all->game.step_y > 0)
			p = 3;
	}
	all->game.zbuf[x] = all->game.pwd;
	return (p);
}

int			perform_dda(t_all *all, int x)
{
	int	p;

	p = 0;
	while (all->game.hit == 0)
	{
		if (all->game.sdx < all->game.sdy)
		{
			all->game.sdx += all->game.ddx;
			all->game.map_x += all->game.step_x;
			all->game.side = 0;
		}
		else
		{
			all->game.sdy += all->game.ddy;
			all->game.map_y += all->game.step_y;
			all->game.side = 1;
		}
		if (all->pars.map[all->game.map_x][all->game.map_y] == '1')
			all->game.hit = 1;
		p = calc_pol(all, x);
	}
	return (p);
}

int			game_loop(t_all *all)
{
	calc(all);
	key_update(all);
	mlx_put_image_to_window(all->game.mlx, all->game.win,
	all->img.img, 0, 0);
	mlx_do_sync(all->game.mlx);
	return (0);
}

int			all_init(t_all *all, int count)
{
	init_params(all);
	init_win(all, "MY GAME");
	full_init_texture(all);
	init_img(all);
	if (all->pars.spr_num > 0)
		init_spr(all, count);
	vision(all);
	return (0);
}

int			close_window(t_all *all)
{
	int i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(all->game.mlx, all->game.images[i]->img);
		i++;
	}
	mlx_destroy_image(all->game.mlx, all->img.img);
	mlx_destroy_window(all->game.mlx, all->game.win);
	exit(0);
}
