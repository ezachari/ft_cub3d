/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:18:16 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 19:36:09 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_res_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		while (skip_space(line[i]))
			i++;
		if (!ft_isdigit(line[i]) && !skip_space(line[i]))
			exit(print_err(1, ANSI_COLOR_CYAN \
			"Find unexpected symbols in resolution"));
		i++;
	}
}

void		check_color_line(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == ',')
			count++;
		if (!ft_isdigit(line[i]) && line[i] != ' '
		&& line[i] != ',')
			exit(print_err(1, ANSI_COLOR_CYAN \
			"Find unexpected symbols in color"));
		if (count > 2)
			exit(print_err(1, ANSI_COLOR_CYAN \
			"Find unexpected symbols in color"));
		i++;
	}
}

void		check_color_length(char **split)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (split[i] != NULL)
	{
		tmp = ft_strtrim(split[i], " ");
		j = 0;
		while (ft_isdigit(tmp[j]))
			j++;
		if (!ft_isdigit(tmp[j]) && tmp[j] != '\0')
			exit(print_err(1, ANSI_COLOR_CYAN \
			"RGB (0 - 255)"));
		if (j > 3)
			exit(print_err(1, ANSI_COLOR_CYAN \
			"RGB (0 - 255)"));
		free(tmp);
		i++;
	}
}

void		check_params(char *content, t_all *all, int start)
{
	char	*tmp;

	while (skip_space(content[start]))
		start++;
	tmp = ft_strtrim(content, " ");
	if (tmp[0] == 'R' && tmp[1] == ' ')
		extract_res(tmp, all, &all->pars);
	else if (tmp[0] == 'N' && tmp[1] == 'O' && tmp[2] == ' ')
		extract_path(content, &all->pars.path_no, start + 2);
	else if (tmp[0] == 'S' && tmp[1] == 'O' && tmp[2] == ' ')
		extract_path(content, &all->pars.path_so, start + 2);
	else if (tmp[0] == 'W' && tmp[1] == 'E' && tmp[2] == ' ')
		extract_path(content, &all->pars.path_we, start + 2);
	else if (tmp[0] == 'E' && tmp[1] == 'A' && tmp[2] == ' ')
		extract_path(content, &all->pars.path_ea, start + 2);
	else if (tmp[0] == 'S' && tmp[1] == ' ')
		extract_path(content, &all->pars.path_sprite, start + 1);
	else if (tmp[0] == 'C' && tmp[1] == ' ')
		extract_color(tmp, &all->pars.cell);
	else if (tmp[0] == 'F' && tmp[1] == ' ')
		extract_color(tmp, &all->pars.floor);
	else if (tmp[0] != 0 && tmp[0] != ' ')
		exit(print_err(1, ERR_US));
	free(tmp);
}

void		check_map(t_list **head, t_all *all, int size, int flag)
{
	t_list	*tmp;
	char	*str;

	tmp = *head;
	if (!(all->pars.map = (char **)malloc(sizeof(char *) * (size))))
		print_perr("Cannot allocate memmory for all->pars->map");
	skip_empty(&tmp);
	while (tmp)
	{
		str = (char *)tmp->content;
		while (str[0] != 0 && tmp)
		{
			str = (char *)tmp->content;
			all->pars.map[all->pars.size++] = str;
			tmp = tmp->next;
		}
		while (str[0] == 0 && tmp)
		{
			flag = 1;
			str = (char *)tmp->content;
			tmp = tmp->next;
		}
		if ((str[0] != 0 && flag))
			exit(print_err(1, "Invalid map"));
	}
}
