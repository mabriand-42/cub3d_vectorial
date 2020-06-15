/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_STRUCT_H
# define CUB3D_GAME_STRUCT_H

# include "cub3d_parse_struct.h"

typedef	struct	s_window
{
	void	*win_ptr;
	t_reso	r;

}				t_window;


typedef	struct	s_image
{
	void	*img_ptr;
	void 	*addr;
	int		*i_addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_reso	r;
	char	*path;
}				t_image;


typedef	struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_box
{
	int	x;
	int	y;
}				t_box;

typedef struct	s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
	t_box	box;
}				t_player;


typedef struct	s_cast
{
	double	cam;
	t_vect 	ray_dir;
	t_vect	side_dist;
	t_vect	delta_dist;
	t_box	step;
	t_box	map;
	t_card	wall;
	double	line_height;
	double	slice;
	double	in_w;
	t_box	in_t;
}				t_cast;

typedef	struct	s_texture
{
	t_image	no_img;
	t_image	so_img;
	t_image	we_img;
	t_image	ea_img;
	t_image	s_img;

}				t_texture;

typedef struct	s_draw
{
	int		c_rgb;
	int		f_rgb;
	t_box	ceiling;
	t_box	wall;
	t_box	floor;
	t_box	sprite_h;
	t_box	sprite_w;
}				t_draw;

typedef struct	s_sprite
{
	size_t	count;
	t_box	*coor;
	double	*dist;
	size_t	*rank;
	t_vect	trans;
	int		color;
	int		s_cam;
}				t_sprite;


typedef struct	s_cub
{
	void		*mlx_ptr;
	t_window	win;
	t_image		img;

	t_bool		save; // pas sur qu'on en ai vraiment besoin
	t_bool		done;

	char		**box_map;

	t_player	player;
	t_cast		cast;
	t_draw		draw;

	t_texture	texture;

	t_sprite	sprite;
}				t_cub;



#endif