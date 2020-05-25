/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:16:11 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:05:17 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Vérifie que c est un caractère autorisé pour
** l'orientation du joueur.
** =========
** #1 : un caractère.
** =========
** Retourne 1 si le caractère est valide, 0 sinon.
*/

int		ft_iscardinal(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** Actualise la position du joueur,
** en fonction du caractère donné.
** =========
** #1 : un caractère 'N', 'S', 'E' ou 'W'.
** #2 : un pointeur sur une t_map.
** =========
*/

int		ft_update_player(char c, t_map *m)
{
	if (m->card == not_given)
	{
		if (c == 'N')
			m->card = north;
		if (c == 'S')
			m->card = south;
		if (c == 'E')
			m->card = east;
		if (c == 'W')
			m->card = west;
		return (1);
	}
	else
		return (0);
}

/*
** Vérifie si toutes les informations de
** configuration ont été récupérées.
** =========
** #1 : un t_check.
** =========
** Retourne 0 si une des informations de
** configuration est manquante, 1 si tout est OK.
*/

int		ft_check_config(t_check check)
{
	if (check.reso == no)
		return (0);
	if (check.no_text == no)
		return (0);
	if (check.so_text == no)
		return (0);
	if (check.we_text == no)
		return (0);
	if (check.ea_text == no)
		return (0);
	if (check.s_text == no)
		return (0);
	if (check.c_color == no)
		return (0);
	if (check.f_color == no)
		return (0);
	return (1);
}
