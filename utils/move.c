/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <ezachari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:52:55 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/18 17:08:45 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_update(t_all *a)
{
	if (a->game.k_w)
		go_forward(a);
	if (a->game.k_s)
		go_backward(a);
	if (a->game.k_lef)
		go_right(a);
	if (a->game.k_rht)
		go_left(a);
	if (a->game.k_a)
		go_lef(a);
	if (a->game.k_d)
		go_rht(a);
	return (0);
}

int		key_press(int key, t_all *a)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		a->game.k_w = 1;
	if (key == 1)
		a->game.k_s = 1;
	if (key == 124)
		a->game.k_rht = 1;
	if (key == 123)
		a->game.k_lef = 1;
	if (key == 0)
		a->game.k_a = 1;
	if (key == 2)
		a->game.k_d = 1;
	return (0);
}

int		key_release(int key, t_all *a)
{
	if (key == 13)
		a->game.k_w = 0;
	if (key == 1)
		a->game.k_s = 0;
	if (key == 124)
		a->game.k_rht = 0;
	if (key == 123)
		a->game.k_lef = 0;
	if (key == 0)
		a->game.k_a = 0;
	if (key == 2)
		a->game.k_d = 0;
	return (0);
}
