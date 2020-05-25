/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:13:57 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 09:56:57 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Vérifie que la portion de ligne allant de
** la position donnée au caractère de fin de
** chaîne soit bien fermée.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** =========
** Retourne 0 si tout est OK, 1 sinon.
*/

int		ft_closed_map(char *line, size_t *pos)
{
	while (line[*pos] != '\0')
	{
		if (line[*pos] == '1' || line[*pos] == ' ')
			(*pos)++;
		else
			return (0);
	}
	return (1);
}

/*
** Compare les caractères à un indice donné
** de deux chaînes différentes afin de vérifier une partie
** de la validité de la description de la map. La fonction
** actualise également le statut de la position du joueur
** dans la map si l'information est donnée.
** =========
** #1 : le caractère de la première chaîne.
** #2 : le caractère de la deuxième au même indice.
** #3 : un pointeur sur une t_map.
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_cmp_char(char c1, char c2, t_map *map)
{
	if (ft_isvalidchar(c1) == 0 && ft_iscardinal(c1) == 0)
		return (0);
	else if (ft_isvalidchar(c2) == 0 && ft_iscardinal(c2) == 0)
		return (0);
	else if (c1 == ' ' && (c2 == '0' || c2 == '2' || ft_iscardinal(c2) == 1))
		return (0);
	else if ((c1 == '0' || c1 == '2' || ft_iscardinal(c1) == 1) && c2 == ' ')
		return (0);
	if (ft_iscardinal(c1) == 1 && ft_iscardinal(c2) == 0)
		return (ft_update_player(c1, map));
	else if (ft_iscardinal(c1) == 1 && ft_iscardinal(c2) == 1)
		return (ft_update_player(c2, map));
	else
		return (1);
}

/*
** Compare le caractère d'une chaîne aux caractères
** d'(indice - 1) et d'(indice + 1) d'une chaîne différente
** afin de vérifier une partie de la validité
** de la description de la map.
** =========
** #1 : le caractère de la première chaîne.
** #2 : la deuxième chaîne de caractères
** #3 : l'index du premier paramètre.
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_cmp_prev_next(char c1, char *line, size_t index)
{
	size_t	i_next;
	size_t	i_prev;
	char	c2;
	char	c3;

	i_next = index + 1;
	i_prev = index - 1;
	c2 = line[i_prev];
	c3 = line[i_next];
	if (c1 == ' ' && (c2 == '0' || c2 == '2' || ft_iscardinal(c2) == 1))
		return (0);
	else if (c1 == ' ' && (c3 == '0' || c3 == '2' || ft_iscardinal(c2) == 1))
		return (0);
	else if (c1 == '0' && (c2 == ' ' || c3 == ' '))
		return (0);
	else if (c1 == '2' && (c2 == ' ' || c2 == ' '))
		return (0);
	else if (ft_iscardinal(c1) == 1 && (c2 == ' ' || ft_iscardinal(c2) == 1))
		return (0);
	else if (ft_iscardinal(c1) == 1 && (c3 == ' ' || ft_iscardinal(c3) == 1))
		return (0);
	return (1);
}

/*
** Vérifie la validité de la description de la map en
** comparant la ligne actuelle à la ligne précédente,
** toutes deux lues par GNL en amont dans le parsing.
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : la chaîne de caractères précédente (lue par GNL).
** #3 : un pointeur sur une t_map.
** =========
** Retourne 0 si tout est OK, 1 sinon.
*/

int		ft_duo_line(char *next, char *prev, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (next[i] != '\0' && prev[j] != '\0')
	{
		if (ft_cmp_char(next[i], prev[j], map) == 1)
		{
			if (ft_cmp_prev_next(prev[i], next, j) == 1)
			{
				i++;
				j++;
			}
			else
				return (0);
		}
		else if (ft_cmp_char(next[i], prev[j], map) == 0)
			break ;
	}
	return (ft_duo_line_cp(next, prev, &i, &j));
}

/*
** Vérifie les cas particuliers de ft_duo_line(3).
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : la chaîne de caractères précédente (lue par GNL).
** #3 : un pointeur sur une t_map.
** =========
** Retourne 0 si tout est OK, 1 sinon.
*/

int		ft_duo_line_cp(char *next, char *prev, size_t *ptr_i, size_t *ptr_j)
{
	size_t	i;
	size_t	j;

	i = *ptr_i;
	j = *ptr_j;
	if (next[i] == '\0' && prev[j] == '\0')
	{
		if (next[i - 1] != '1' || prev[i - 1] != '1')
			return (0);
		return (1);
	}
	else if (next[i] != '\0' && prev[j] != '\0')
		return (0);
	else if (next[i] == '\0' && prev[j] != '\0')
		return (ft_closed_map(prev, &j));
	else if (next[i] != '\0' && prev[j] == '\0')
		return (ft_closed_map(next, &i));
	else
		return (0);
}
