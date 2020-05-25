/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Initialise une structure de type
** t_configuration : met à 0 la résolution,
** à NULL les textures, à -1 les couleurs,
** et en "no" les checks de configuration.
** =========
** #1 : un pointeur sur une t_configuration.
** =========
*/

void	ft_init_config(t_data *data)
{
	data->r.x = 0;
	data->r.y = 0;
	data->c.r = -1;
	data->c.g = -1;
	data->c.b = -1;
	data->f.r = -1;
	data->f.g = -1;
	data->f.b = -1;
	data->t.path_no = NULL;
	data->t.path_so = NULL;
	data->t.path_we = NULL;
	data->t.path_ea = NULL;
	data->t.path_s = NULL;
	ft_init_check(&(data->check));
}

/*
** Initialise une structure de type t_check
** en mettant tout en "no".
** (Une telle structure à pour vocation d'être
** modifiée au cours du parsing afin de suivre
** la récupération des données de configuration).
** =========
** #1 : un pointeur sur un t_check.
** =========
*/

void	ft_init_check(t_check *c)
{
	c->reso = no;
	c->no_text = no;
	c->so_text = no;
	c->we_text = no;
	c->ea_text = no;
	c->s_text = no;
	c->f_color = no;
	c->c_color = no;
}

/*
** Initialise une structure de type t_map
** en mettant les deux versions de la carte
** (1D et 2D) à NULL, le statut de la première
** ligne de la map en "NO" et celui de la
** position du joueur en "Not_given".
** =========
** #1 : un pointeur sur une t_map.
** =========
*/

void	ft_init_map(t_map *m)
{
	m->map = NULL;
	m->two_d = NULL;
	m->first = no;
	m->card = not_given;
}

/*
** Initialise une structure de type t_pars
** =========
** #1 : un pointeur sur une t_pars.
** =========
*/

void	ft_init_pars_struct(t_pars *ptr)
{
	ft_init_config(&(ptr->data));
	ft_init_map(&(ptr->map));
	ptr->save = no;
}
