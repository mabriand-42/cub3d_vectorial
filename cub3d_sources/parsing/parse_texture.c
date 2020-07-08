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
** #3 : une position dans cette chaîne.
** #4 : l'adresse d'une chaîne de caractères
**		(correspondant un path contenu dans
**		une t_configuration et initialisé à NULL
**		en début de parsing).
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_path(char *line, size_t *pos, size_t save_pos, char **path)
{
	size_t	path_size;

	path_size = 0;
	if (ft_isspace(line[*pos]) == 0 && line[*pos] != '\t' && line[*pos] != '\0')
	{
		while (ft_isspace(line[*pos]) == 0 && line[*pos] != '\t'
											&& line[*pos] != '\0')
		{
			(*pos)++;
			path_size++;
		}
		while (line[*pos] != '\0')
		{
			if (ft_isspace(line[*pos]) == 1 || line[*pos] == '\t')
				(*pos)++;
			else
				return (0);
		}
		ft_reinit_buffer(save_pos, line);
		*path = ft_strndup(line, path_size);
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
	size_t	save_pos;

	save_pos = 0;
	(*pos)++;
	if (ft_isspace(line[*pos]) == 1 || line[*pos] == '\t')
	{
		ft_skip_spaces(line, pos);
		save_pos = *pos - 1;
		if ((ft_path(line, pos, save_pos, path) == 1) && (*check == no))
		{
			*check = yes;
			return (1);
		}
	}
	ft_printf("Error\nPlease check the path of your textures!\n");
	return (0);
}
