/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:03:05 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/20 13:56:57 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WEST "W"
# define NORTH "N"
# define EAST "E"
# define SOUTH "S"
# define MIN_H 200
# define MIN_W 320
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "ft_error.h"
# include "get_next_line.h"
# include "all_struct.h"

/*
**		Calculate section
*/
void			init_calc(t_all *all, int x);
void			calc_wall(t_all *all, int x);
void			calc_color(t_all *all);
void			calc_dir(t_all *all);
void			calc(t_all *all);
int				calc_sprite(t_all *all);
int				calc_pol(t_all *all, int x);
/*
**		DDA section
*/
int				perform_dda(t_all *all, int x);
int				game_loop(t_all *all);
void			ft_mlx(t_all *all);
/*
**		Draw section
*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_floor(t_all *all, int x);
void			draw_cell(t_all *all, int x);
void			draw(t_all *all);
/*
**		Move event section
*/
int				key_press(int key, t_all *all);
int				key_release(int key, t_all *all);
int				key_update(t_all *all);
void			go_forward(t_all *all);
void			go_backward(t_all *all);
void			go_left(t_all *all);
void			go_right(t_all *all);
void			go_lef(t_all *a);
void			go_rht(t_all *a);
/*
**		Init section
*/
void			inting(t_all *all);
void			init_texture(t_all *all);
void			full_init_texture(t_all *all);
int				init_plr_pos(t_all *all, int count);
void			init_win(t_all *all, char *name);
void			init_img(t_all *all);
void			init_params(t_all *all);
void			init_calc(t_all *a, int x);
void			init_spr(t_all *all, int count);
void			init_spr_pos(t_all *all, int count);
int				all_init(t_all *all, int count);
void			init_srn_img(t_all *all);
/*
**		Parsing section
*/
t_all			*return_all(void);
void			ft_mlx(t_all *all);
void			set_minimum(int *width, int *height, int max_w, int max_h);
void			check_res_line(char *line);
int				ft_inset(char elem, char set);
void			check_color_line(char *line);
void			extract_res(char *line, t_all *all, t_pars *pars);
void			check_color_length(char **split);
int				check_color_diapason(int number);
void			extract_path(char *line, char **path, int start);
void			extract_color(char *line, int *color);
void			check_params(char *content, t_all *all, int start);
void			check_map(t_list **head, t_all *all, int size, int flag);
int				full_check(t_pars *pars);
void			ft_parse_lines(t_list **head, t_all *all, int size);
void			ft_parser(t_list **head, t_all *all, char *name);
void			check_name(char *name);
void			check_save(char *name);
void			free_split(char **spl);
int				skip_space(char elem);
int				check_cross(t_pars *pars, int i, int j, int len);
int				check_elem(char elem, t_pars *pars);
int				check_all_elems(t_pars *pars);
int				valid_map(t_pars *pars);
void			sample_game(t_all *all, t_list *list, char **argv);
void			only_screenshot(t_all *all, t_list *list, char **argv);
int				close_window(t_all *all);
void			scrn_win(t_all *all);
void			save_screenshot(t_all *all);
void			scrn_extract_res(char *line, t_all *all);
int				scrn_game_loop(t_all *all);
int				screen_init(t_all *all, int count);
void			vision(t_all *all);
void			sort_ord(int *order, float *dist, int amount, t_all *all);
void			skip_empty(t_list **tmp);
void			ft_scrn_parser(t_list **head, t_all *all, char *name);
void			ft_scrn_parse_lines(t_list **head, t_all *all, int size);
void			scrn_check_params(char *content, t_all *all);
/*
**		Error section
*/
int				print_err(int error, char *err);
void			print_perr(char *mas);
#endif
