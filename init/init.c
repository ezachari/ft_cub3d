/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:19:43 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:15:06 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_all *all)
{
	int i;

	i = 0;
	if (!(all->game.images = (t_data **)malloc(sizeof(t_data *) * 5)))
		print_perr("init.c | init_texture() | t_data **images");
	while (i < 5)
	{
		if (!(all->game.images[i] = (t_data *)malloc(sizeof(t_data))))
			print_perr("init.c | init_texture() | t_data **images[i]");
		i++;
	}
}

void	full_init_texture(t_all *all)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		if (!(all->game.images[j]->img =
		mlx_xpm_file_to_image(all->game.mlx, all->game.images[j]->path,
		&all->game.images[j]->img_w, &all->game.images[j]->img_h)))
			exit(print_err(1, "mlx_xpm_file_to_image return NULL"));
		if (!(all->game.images[j]->addr =
		mlx_get_data_addr(all->game.images[j]->img,
		&all->game.images[j]->bits_pp, &all->game.images[j]->line_l,
		&all->game.images[j]->endian)))
			exit(print_err(1, "mlx_get_data_addr return NULL"));
		j++;
	}
}

void	init_win(t_all *all, char *name)
{
	if (!(all->game.mlx = mlx_init()))
		exit(print_err(1, ERR_INIT_1));
	if (!(all->game.win = mlx_new_window(all->game.mlx,
	all->game.w, all->game.h, name)))
		exit(print_err(2, ERR_INIT_2));
	if (!(all->game.zbuf = (float *)malloc(sizeof(float) * all->game.w)))
		print_perr("init.c | init_win() | int *zbuf");
}

void	init_img(t_all *all)
{
	if (!(all->img.img = mlx_new_image(all->game.mlx,
	all->game.w, all->game.h)))
		exit(print_err(3, ERR_INIT_3));
	if (!(all->img.addr =
	mlx_get_data_addr(all->img.img, &all->img.bits_pp,
	&all->img.line_l, &all->img.endian)))
		exit(print_err(4, ERR_INIT_4));
}

void	init_params(t_all *all)
{
	all->game.images[0]->path = all->pars.path_no;
	all->game.images[1]->path = all->pars.path_so;
	all->game.images[2]->path = all->pars.path_we;
	all->game.images[3]->path = all->pars.path_ea;
	all->game.images[4]->path = all->pars.path_sprite;
	all->game.color_c = all->pars.cell;
	all->game.color_f = all->pars.floor;
	all->game.ms = 0.1;
	all->game.k_a = 0;
	all->game.k_s = 0;
	all->game.k_w = 0;
	all->game.k_d = 0;
	all->game.k_rht = 0;
	all->game.k_lef = 0;
	all->game.rs = 0.05;
	all->game.h = all->pars.res_h;
	all->game.w = all->pars.res_w;
}
