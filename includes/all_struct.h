/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <anubis5298@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:31:34 by ezachari          #+#    #+#             */
/*   Updated: 2021/02/20 14:00:59 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_STRUCT_H
# define ALL_STRUCT_H

typedef struct	s_spr
{
	float x;
	float y;
}				t_spr;

typedef struct	s_data
{
	void	*img;
	void	*addr;
	int		bits_pp;
	int		line_l;
	int		endian;
	int		img_w;
	int		img_h;
	char	*path;
}				t_data;

typedef struct	s_game
{
	t_spr	**s;
	t_data	**images;
	float	*zbuf;
	void	*mlx;
	void	*win;
	char	*pol;
	float	pos_x;
	float	pos_y;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	float	cx;
	float	rdx;
	float	rdy;
	float	sdx;
	float	sdy;
	float	pwd;
	float	ms;
	float	rs;
	float	ddx;
	float	ddy;
	float	wall_x;
	float	step;
	float	tex_pos;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		start;
	int		end;
	int		color;
	int		h;
	int		w;
	int		color_f;
	int		color_c;
	int		color_cf;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	int		k_rht;
	int		k_lef;
	int		k_w;
	int		k_a;
	int		k_s;
	int		k_d;
	int		k_esc;
}				t_game;

typedef struct	s_pars
{
	char	**map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*path_sprite;
	int		res_w;
	int		res_h;
	int		cell;
	int		floor;
	int		spr_num;
	int		size;
	int		we;
	int		ea;
	int		no;
	int		so;
	int		max_width;
	int		max_height;
}				t_pars;

typedef struct	s_sprite
{
	float	sprite_x;
	float	sprite_y;
	float	inv_det;
	float	trans_x;
	float	trans_y;
	int		sprite_scrx;
	int		sprite_h;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_w;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		tex_y;
	int		d;
	int		y;
}				t_sprite;

typedef struct	s_all
{
	t_data		img;
	t_game		game;
	t_pars		pars;
	t_sprite	sprite;
}				t_all;

#endif
