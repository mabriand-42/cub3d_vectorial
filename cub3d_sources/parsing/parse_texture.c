/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:43:28 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/09 13:17:39 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Récupère une partie d'une chaîne de caractères
** correspondant à un path vers une texture.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : l'adresse d'une chaîne de caractères
**		(correspondant un path contenu dans
**		une t_configuration et initialisé à NULL
**		en début de parsing).
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_path(char *line, size_t *pos, char **path)
{
	if (ft_isspace(line[*pos]) == 1)
	{
		ft_reinit_buffer(*pos, line);
		*path = strdup(line);
		return (1);
	}
	return (0);
}

/*
** Récupère le path vers une texture, vérifie
** la validité du check correspondant et actualise
** ce dernier en "yes" si tout est OK.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_reso.
** #4 : un pointeur sur un t_bool.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_text(char *line, size_t *pos, char **path, t_bool *check)
{
	(*pos)++;
	if ((ft_path(line, pos, path) == 1) && (*check == no))
	{
		*check = yes;
		return (1);
	}
	return (0);
}
