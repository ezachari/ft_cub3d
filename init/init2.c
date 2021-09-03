/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:09:57 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 14:17:12 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	polus(t_all *all, char elem)
{
	if (elem == 'S')
		all->pars.so = 1;
	if (elem == 'N')
		all->pars.no = 1;
	if (elem == 'W')
		all->pars.we = 1;
	if (elem == 'E')
		all->pars.ea = 1;
}

int		init_plr_pos(t_all *all, int count)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (all->pars.map[i][j] != '\0')
		{
			if ((all->pars.map[i][j] == 'N' || all->pars.map[i][j] == 'S' ||
			all->pars.map[i][j] == 'W' || all->pars.map[i][j] == 'E'))
			{
				polus(all, all->pars.map[i][j]);
				all->game.pos_x = i + 0.5;
				all->game.pos_y = j + 0.5;
				flag += 1;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

void	init_spr_pos(t_all *all, int count)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (all->pars.map[i][j] != '\0')
		{
			if (all->pars.map[i][j] == '2')
			{
				all->game.s[k]->x = i + 0.5;
				all->game.s[k]->y = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_spr(t_all *all, int count)
{
	int i;
	int j;

	i = -1;
	j = all->pars.spr_num;
	if (!(all->game.s = (t_spr **)malloc(sizeof(t_spr *) * j)))
		print_perr("init.c | init_spr() | t_spr **s");
	while (++i < all->pars.spr_num)
		if (!(all->game.s[i] = (t_spr *)malloc(sizeof(t_spr))))
			print_perr("init.c | init_spr() | t_spr **s[i]");
	init_spr_pos(all, count);
}

void	scrn_win(t_all *all)
{
	if (!(all->game.mlx = mlx_init()))
		exit(print_err(1, ERR_INIT_1));
	if (!(all->game.zbuf = (float *)malloc(sizeof(float) * all->game.w)))
		print_perr("init.c | init_win() | int *zbuf");
}
