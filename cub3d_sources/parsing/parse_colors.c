/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:51:47 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/04 16:24:08 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Convertit une partie d'une chaîne de caractères
** afin de récupèrer une intensité colorimétrique.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** =========
** Retourne un entier positif compris entre 0 et 255,
** -1 en cas d'erreur.
*/

int	ft_color(char *line, size_t *pos)
{
	int param;
	int ret;

	param = 0;
	ret = -1;
	if (ft_isdigit(line[*pos]))
	{
		while (ft_isdigit(line[*pos]) == 1)
		{
			param = (param * 10) + line[*pos] - 48;
			(*pos)++;
		}
		if (param >= 0 && param <= 255)
			ret = param;
	}
	return (ret);
}

/*
** Récupère, à l'aide de ft_color(2) les valeurs RGB
** d'une couleur, vérifie qu'elles sont correctement
** séparées, et les affecte aux champs correspondant
** d'une stucture c de type t_color.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_color.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_rgb(char *line, size_t *pos, t_color *c)
{
	int		ret;

	ret = 0;
	if (ft_isspace(line[*pos]) == 1 || line[*pos] == '\t')
		ft_skip_spaces(line, pos);
	else
		return (ret);
	if ((c->r = ft_color(line, pos)) != -1)
	{
		if ((line[(*pos)++] == ',') && (c->g = ft_color(line, pos)) != -1)
		{
			if ((line[(*pos)++] == ',') && (c->b = ft_color(line, pos)) != -1)
			{
				if (ft_isspace(line[*pos]) == 1 || line[*pos] == '\t')
					ft_skip_spaces(line, pos);
				if (line[*pos] == '\0')
					ret = 1;
				else
					ret = 0;
			}
		}
	}
	return (ret);
}

/*
** Récupère les valeurs RGB d'une couleur
** puis vérifie leur validité ainsi que celle
** du check correspondant et actualise ce dernier
** en "yes" si tout est OK.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_color.
** #4 : un pointeur sur un t_bool.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_cf(char *line, size_t *pos, t_color *color, t_bool *check)
{
	if ((ft_rgb(line, pos, color) == 1) && (*check == no))
	{
		*check = yes;
		return (1);
	}
	ft_printf("Please make sure you put valid RGB colors... \n");
	return (0);
}
