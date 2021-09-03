/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:53:34 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 17:13:00 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_cross(t_pars *pars, int i, int j, int len)
{
	if (((i - 1) == -1) || ((j - 1) == -1) || ((i + 1) > pars->size) ||
	j + 1 > len - 1)
		exit(print_err(1, "Invalid map"));
	if (j > (int)ft_strlen(pars->map[i + 1]) - 1 || j >
	(int)ft_strlen(pars->map[i - 1]) - 1)
		exit(print_err(1, "Invalid map"));
	if (pars->map[i + 1][j] != ' ' && pars->map[i][j + 1] != ' '
	&& pars->map[i - 1][j] != ' ' && pars->map[i][j - 1] != ' ')
		return (1);
	return (0);
}

int		check_elem(char elem, t_pars *pars)
{
	if (elem == '2')
		pars->spr_num += 1;
	if (elem == ' ' || elem == '0' || elem == '1' || elem == '2' || \
	elem == 'S' || elem == 'N' || elem == 'W' || elem == 'E')
		return (1);
	return (0);
}

int		check_all_elems(t_pars *pars)
{
	int i;
	int j;

	i = 0;
	while (i < pars->size)
	{
		j = 0;
		while (pars->map[i][j])
		{
			if (pars->map[i][j] == '\0')
				i++;
			if (check_elem(pars->map[i][j], pars) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		valid_map(t_pars *pars)
{
	int i;
	int j;
	int len;

	pars->spr_num = 0;
	i = -1;
	if ((check_all_elems(pars)) == -1)
		return (-1);
	while (++i < pars->size)
	{
		j = -1;
		len = ft_strlen(pars->map[i]);
		while (++j < len)
		{
			if (pars->map[i][j] == '0' || pars->map[i][j] == '2'
			|| pars->map[i][j] == 'S' || pars->map[i][j] == 'W'
			|| pars->map[i][j] == 'N' || pars->map[i][j] == 'E')
			{
				if ((check_cross(pars, i, j, len)) != 1)
					return (-1);
			}
		}
	}
	return (0);
}
