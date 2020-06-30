/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSE_STRUCT_H
# define CUB3D_PARSE_STRUCT_H

typedef	struct	s_reso
{
	int x;
	int y;
}				t_reso;

typedef struct	s_text
{
	char *path_no;
	char *path_so;
	char *path_we;
	char *path_ea;
	char *path_s;
}				t_text;

typedef	struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef	enum	e_bool
{
	no,
	yes,
}				t_bool;

typedef struct	s_check
{
	t_bool	reso;
	t_bool	no_text;
	t_bool	so_text;
	t_bool	we_text;
	t_bool	ea_text;
	t_bool	s_text;
	t_bool	f_color;
	t_bool	c_color;
}				t_check;

typedef struct	s_data
{
	t_reso	r;
	t_color	f;
	t_color	c;
	t_text	t;
	t_check	check;
}				t_data;

typedef	struct	s_duo
{
	char	*line;
	char	*prev;
}				t_duo;

typedef	enum	e_card
{
	not_given,
	north,
	south,
	east,
	west,
}				t_card;

typedef struct	s_map
{
	char	*map;
	char	**two_d;
	t_bool	first;
	t_bool	last;
	t_bool	end;
	t_bool	pb;
	t_card	card;

}				t_map;

typedef struct	s_pars
{
	t_data	data;
	t_map	map;
	t_bool	save;
}				t_pars;

#endif
