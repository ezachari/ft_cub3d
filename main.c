/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:17:40 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 15:16:08 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sample_game(t_all *all, t_list *list, char **argv)
{
	ft_parser(&list, all, argv[1]);
	if (valid_map(&all->pars) == -1)
		exit(print_err(1, "Invalid map"));
	init_texture(all);
	all_init(all, all->pars.size);
	ft_mlx(all);
}

void		only_screenshot(t_all *all, t_list *list, char **argv)
{
	check_save(argv[2]);
	ft_parser(&list, all, argv[1]);
	if (valid_map(&all->pars) == -1)
		exit(print_err(1, "Invalid map"));
	init_texture(all);
	screen_init(all, all->pars.size);
	scrn_game_loop(all);
}

int			main(int argc, char **argv)
{
	t_list	*list;
	t_all	all;

	list = NULL;
	inting(&all);
	if (argc == 2)
		sample_game(&all, list, argv);
	if (argc == 3)
		only_screenshot(&all, list, argv);
	else
		exit(print_err(1, "1-2 argc min"));
	return (0);
}
