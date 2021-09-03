/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:52:50 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/09 16:11:26 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_err(int error, char *err)
{
	ft_putendl_fd(ANSI_COLOR_RED "Error", 1);
	ft_putendl_fd(err, 1);
	return (error);
}

void	print_perr(char *mas)
{
	perror(mas);
	exit(1);
}
