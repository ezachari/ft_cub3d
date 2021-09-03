/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:24:47 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/20 14:04:02 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_minimum(int *width, int *height, int max_w, int max_h)
{
	if (*width < MIN_W)
	{
		*width = MIN_W;
		*height = MIN_H;
		return ;
	}
	else if (*width > max_w)
	{
		*height = max_h;
		*width = max_w;
		return ;
	}
	if (*height < MIN_H)
	{
		*width = MIN_W;
		*height = MIN_H;
		return ;
	}
	else if (*height > max_h)
	{
		*height = max_h;
		*width = max_w;
		return ;
	}
}

int			check_color_diapason(int number)
{
	if (number < 0 || number > 255)
		exit(print_err(1, ERR_COLOR_1));
	return (number);
}

int			full_check(t_pars *pars)
{
	if (pars->path_no && pars->path_so && pars->path_we \
	&& pars->path_ea && pars->res_h && pars->res_w \
	&& pars->path_sprite && pars->cell && pars->floor)
		return (1);
	return (0);
}

void		ft_parse_lines(t_list **head, t_all *all, int size)
{
	t_list	*tmp;
	int		flag;
	int		start;

	mlx_get_screen_size(all->game.mlx, &all->pars.max_width,
	&all->pars.max_height);
	start = 0;
	flag = 0;
	tmp = *head;
	while (tmp)
	{
		if (full_check(&all->pars))
		{
			check_map(&tmp, all, size, flag);
			break ;
		}
		else
			check_params(tmp->content, all, start);
		if (!full_check(&all->pars) && tmp->next == NULL && all->pars.size == 0)
			exit(print_err(1, "Not full info for cub"));
		tmp = tmp->next;
	}
	if ((init_plr_pos(all, all->pars.size)) != 1)
		exit(print_err(1, "NO/TO MANY PLAYER POSITION"));
}

void		ft_parser(t_list **head, t_all *all, char *name)
{
	int		fd;
	int		size;
	char	*line;

	check_name(name);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		print_perr("Cant open this file");
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(head, ft_lstnew(line));
	ft_lstadd_back(head, ft_lstnew(line));
	size = ft_lstsize(*head);
	ft_parse_lines(head, all, size);
	if ((close(fd)) == -1)
		print_perr("Cant close this file");
}
