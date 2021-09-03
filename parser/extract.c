/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:16:54 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/20 14:09:43 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		extract_res(char *line, t_all *all, t_pars *pars)
{
	char	*tmp;
	char	**sp;

	tmp = ft_strtrim(&line[1], " ");
	check_res_line(tmp);
	sp = ft_split(tmp, ' ');
	if (sp[0] && sp[1] && sp[2] == 0 && !pars->res_w && !pars->res_h)
	{
		if (ft_strlen(sp[0]) > 6 || ft_strlen(sp[1]) > 6)
		{
			all->pars.res_w = all->pars.max_width;
			all->pars.res_h = all->pars.max_height;
			free(tmp);
			free_split(sp);
			return ;
		}
		all->pars.res_w = ft_atoi(sp[0]);
		all->pars.res_h = ft_atoi(sp[1]);
	}
	else
		exit(print_err(1, "Wrong number of arguments"));
	set_minimum(&all->pars.res_w, &all->pars.res_h, all->pars.max_width,
	all->pars.max_height);
	free_split(sp);
	free(tmp);
}

void		extract_path(char *line, char **path, int start)
{
	while (skip_space(line[start]))
		start++;
	if (!(*path))
		*path = ft_strdup(&line[start]);
	else
		exit(print_err(1, ANSI_COLOR_CYAN \
		"Wrong number of arguments"));
}

void		extract_color(char *line, int *color)
{
	char	*tmp;
	char	**split;
	int		red;
	int		green;
	int		blue;

	tmp = ft_strtrim(&line[1], " ");
	check_color_line(tmp);
	split = ft_split(tmp, ',');
	if (split[0] && split[1] && split[2] && split[3] == NULL &&
	!(*color))
	{
		check_color_length(split);
		red = check_color_diapason(ft_atoi(split[0]));
		green = check_color_diapason(ft_atoi(split[1]));
		blue = check_color_diapason(ft_atoi(split[2]));
		*color = ((1 << 24) | (red << 16) | (green << 8) | blue);
	}
	else
		exit(print_err(1, ANSI_COLOR_CYAN \
		"Wrong number of arguments"));
	free_split(split);
	free(tmp);
}
