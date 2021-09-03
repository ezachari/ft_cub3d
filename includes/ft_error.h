/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:43:20 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/19 16:38:40 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define ERR_US "Unexpected symbol in .cub"
# define ERR_RES_1 "Wrong number of arguments"
# define ERR_RES_2 "Somthing WRONG with parametr R"
# define ERR_COLOR_1 "RGB (0 - 255)"
# define ERR_MLC_1 "Malloc return NULL in ft_strdup()"
# define ERR_MAP_1 "Find 0 in map border"
# define ERR_MAP_2 "accessible: ' ', '0', '1', '2', 'S', 'N', 'W', 'E'"
# define ERR_INIT_1 "mlx_init() RETURN NULL"
# define ERR_INIT_2 "mlx_new_window() RETURN NULL"
# define ERR_INIT_3 "mlx_new_image() RETURN NULL"
# define ERR_INIT_4 "mlx_get_data_addr() RETURN NULL"
# define ERR_SAVE "wrong flag, only available --save"
# define ERR_NAME_1 "need .cub file"
# define ERR_NAME_2 "minimum 5 word"
#endif
