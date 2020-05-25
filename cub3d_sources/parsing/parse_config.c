/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:19:35 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/05 17:38:44 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Vérifie qu'avec le premier, le deuxième caractère
** passé en argument permet de former un des identifiers suivants :
** NO, WE, EA.
** =========
** #1 : un caractère.
** #2 : le caractère suivant.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_check_id(char c1, char c2)
{
	if ((c1 == 'N' && c2 == 'O')
	|| (c1 == 'W' && c2 == 'E')
	|| (c1 == 'E' && c2 == 'A'))
		return (1);
	return (0);
}

/*
** Vérifie si un identifier est présent en début de
** ligne lue, si c'est le cas, il est stocké dans id.
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : une chaîne de caractères.
** #3 : un pointeur sur la position actuelle dans la ligne.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_find_id(char *line, char *id, size_t *pos)
{
	char *letters_0;
	char *letters_1;

	letters_0 = "RFC";
	letters_1 = "NWE";
	if (ft_find_char(line[*pos], letters_0) == 1)
		return (ft_id_rfc(pos, line, id));
	else if (ft_find_char(line[*pos], letters_1) == 1)
		return (ft_id_nwe(pos, line, id));
	else if (line[*pos] == 'S')
		return (ft_id_s(pos, line, id));
	return (0);
}

/*
** Vérifie qu'il s'agit d'un identifier R, F ou C
** en regardant s'il y a bien un espace après le
** caractère correspondant trouvé. Si c'est le cas,
** il est stocké dans id.
** =========
** #3 : un pointeur sur la position actuelle dans la ligne.
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : une chaîne de caractères.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_id_rfc(size_t *pos, char *line, char *id)
{
	(*pos)++;
	if (ft_isspace(line[*pos]) == 1)
	{
		id = ft_strncpy(id, line, 1);
		return (1);
	}
	return (0);
}

/*
** Vérifie qu'il s'agit d'un identifier NO, WE ou EA
** en regardant si le caractère suivant celui trouvé
** permet de le créer. Si oui, il est stocké dans id.
** =========
** #3 : un pointeur sur la position actuelle dans la ligne.
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : une chaîne de caractères.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_id_nwe(size_t *pos, char *line, char *id)
{
	char *letters_2;

	letters_2 = "OEA";
	(*pos)++;
	if (ft_isspace(line[*pos]) == 0 || ft_find_char(line[*pos], letters_2) == 1)
	{
		if (ft_check_id(line[*pos - 1], line[*pos]) == 1)
		{
			id = ft_strncpy(id, line, 2);
			return (1);
		}
	}
	return (0);
}

/*
** Vérifie qu'il s'agit d'un identifier S ou SO
** en regardant s'il y a bien un espace après le
** caractère correspondant trouvé ou un 'O'.
** Si c'est le cas, il est stocké dans id.
** =========
** #3 : un pointeur sur la position actuelle dans la ligne.
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : une chaîne de caractères.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_id_s(size_t *pos, char *line, char *id)
{
	(*pos)++;
	if ((ft_isspace(line[*pos]) == 1))
	{
		id = ft_strncpy(id, line, 1);
		return (1);
	}
	else if (line[*pos] == 'O')
	{
		id = ft_strncpy(id, line, 2);
		return (1);
	}
	return (0);
}
