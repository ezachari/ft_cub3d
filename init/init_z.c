/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:16:03 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/20 14:09:49 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inting(t_all *all)
{
	ft_bzero(&all->game, sizeof(t_game));
	ft_bzero(&all->pars, sizeof(t_pars));
	ft_bzero(&all->img, sizeof(t_data));
	ft_bzero(&all->sprite, sizeof(t_sprite));
}
