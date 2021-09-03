/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:04:31 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:23:49 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distcalc(t_all *a, int *order, float *dist)
{
	int i;

	i = 0;
	while (i < a->pars.spr_num)
	{
		order[i] = i;
		dist[i] = ((a->game.pos_x -
		a->game.s[i]->x) * (a->game.pos_x - a->game.s[i]->x)) +
		((a->game.pos_y - a->game.s[i]->y) *
		(a->game.pos_y - a->game.s[i]->y));
		i++;
	}
}

void	sort_ord(int *order, float *dist, int amount, t_all *all)
{
	int		i;
	int		j;
	float	tmp;
	int		ord;

	distcalc(all, order, dist);
	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - i - 1)
		{
			if (dist[j] > dist[j + 1])
			{
				ord = order[j];
				order[j] = order[j + 1];
				order[j + 1] = ord;
				tmp = dist[j];
				dist[j] = dist[j + 1];
				dist[j + 1] = tmp;
			}
		}
	}
}
