/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:13:56 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 16:18:42 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_color(t_data *img, int x, int y)
{
	unsigned int	color;
	unsigned char	addr[4];

	color = (unsigned int)((int *)img->addr)[y * img->line_l / 4 + x];
	addr[0] = (unsigned char)(color);
	addr[1] = (unsigned char)(color >> 8);
	addr[2] = (unsigned char)(color >> 16);
	addr[3] = (unsigned char)(color >> 24);
	return (*(unsigned int *)(addr));
}

void			fheader(t_all *all, int fd)
{
	unsigned char	res[54];
	int				filesize;

	filesize = all->game.w * (all->img.bits_pp / 8) * all->game.h + 54;
	ft_bzero(res, 54);
	res[0] = (unsigned char)('B');
	res[1] = (unsigned char)('M');
	res[2] = (unsigned char)(filesize);
	res[3] = (unsigned char)(filesize >> 8);
	res[4] = (unsigned char)(filesize >> 16);
	res[5] = (unsigned char)(filesize >> 24);
	res[10] = (unsigned char)(54);
	res[14] = (unsigned char)(40);
	res[18] = (unsigned char)(all->game.w);
	res[19] = (unsigned char)(all->game.w >> 8);
	res[20] = (unsigned char)(all->game.w >> 16);
	res[21] = (unsigned char)(all->game.w >> 24);
	res[22] = (unsigned char)(all->game.h);
	res[23] = (unsigned char)(all->game.h >> 8);
	res[24] = (unsigned char)(all->game.h >> 16);
	res[25] = (unsigned char)(all->game.h >> 24);
	res[26] = (unsigned char)(1);
	res[28] = (unsigned char)(32);
	if ((write(fd, res, 54)) != 54)
		exit(print_err(1, "Cant save screenshot"));
}

void			save_screenshot(t_all *all)
{
	int				fd;
	int				x;
	int				y;
	int				color;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0)
		print_perr("Cant create or open file");
	fheader(all, fd);
	y = all->game.h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->game.w)
		{
			color = get_color(&all->img, x, y);
			if ((write(fd, &color, 4)) != 4)
				exit(print_err(1, "Cant save screenshot"));
			x++;
		}
		y--;
	}
	if ((close(fd)) < 0)
		print_perr("Cant close file");
}

int				scrn_game_loop(t_all *all)
{
	calc(all);
	save_screenshot(all);
	return (0);
}

int				screen_init(t_all *all, int count)
{
	init_params(all);
	scrn_win(all);
	full_init_texture(all);
	init_img(all);
	if (all->pars.spr_num > 0)
		init_spr(all, count);
	vision(all);
	return (0);
}
