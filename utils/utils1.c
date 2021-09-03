/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:31:14 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 19:23:02 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		skip_empty(t_list **tmp)
{
	char	*str;

	while (*tmp)
	{
		str = (char *)(*tmp)->content;
		while (str[0] == 0 && *tmp)
		{
			*tmp = (*tmp)->next;
			if (!(*tmp))
				exit(print_err(1, "Invalid cub"));
			str = (char *)(*tmp)->content;
		}
		if (str[0] != 0)
			break ;
	}
}

void		go_right(t_all *a)
{
	float olddir_x;
	float oldplane_x;

	olddir_x = a->game.dir_x;
	a->game.dir_x = a->game.dir_x * cos(a->game.rs) -
	a->game.dir_y * sin(a->game.rs);
	a->game.dir_y = olddir_x * sin(a->game.rs) +
	a->game.dir_y * cos(a->game.rs);
	oldplane_x = a->game.plane_x;
	a->game.plane_x = a->game.plane_x * cos(a->game.rs) -
	a->game.plane_y * sin(a->game.rs);
	a->game.plane_y = oldplane_x * sin(a->game.rs) +
	a->game.plane_y * cos(a->game.rs);
}
