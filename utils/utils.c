/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:48:46 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/12 08:26:12 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_name(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len < 5)
		exit(print_err(1, ERR_NAME_2));
	if (ft_strncmp(&name[len - 4], ".cub", 4) != 0)
		exit(print_err(1, ERR_NAME_1));
}

void		check_save(char *name)
{
	if (ft_strncmp(name, "--save", 7) != 0)
		exit(print_err(1, ERR_SAVE));
}

void		free_split(char **spl)
{
	int i;

	i = 0;
	while (spl[i] != NULL)
		free(spl[i++]);
	free(spl);
}

int			skip_space(char elem)
{
	if (elem == 32 || (elem >= 9 && elem <= 13))
		return (1);
	return (0);
}

int			ft_inset(char elem, char set)
{
	if (elem == set)
		return (1);
	return (0);
}
