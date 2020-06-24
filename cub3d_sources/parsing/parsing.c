/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Oriente le parsing en fonction de l'id donné.
** =========
** #1 : une chaîne de caractères correspondant
**		à l'id trouvée en début de ligne.
** #2 : la chaîne de caractères actuelle (lue par GNL).
** #3 : un pointeur sur la position actuelle dans la ligne.
** #4 : un pointeur sur une t_configuration.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int		ft_get_config(char *id, char *line, size_t *pos, t_data *c)
{
	if (ft_strcmp(id, "R") == 0)
		return (ft_r(line, pos, &(c->r), &(c->check.reso)));
	else if (ft_strcmp(id, "NO") == 0)
		return (ft_text(line, pos, &(c->t.path_no), &(c->check.no_text)));
	else if (ft_strcmp(id, "SO") == 0)
		return (ft_text(line, pos, &(c->t.path_so), &(c->check.so_text)));
	else if (ft_strcmp(id, "WE") == 0)
		return (ft_text(line, pos, &(c->t.path_we), &(c->check.we_text)));
	else if (ft_strcmp(id, "EA") == 0)
		return (ft_text(line, pos, &(c->t.path_ea), &(c->check.ea_text)));
	else if (ft_strcmp(id, "S") == 0)
	{
		(*pos)--;
		return (ft_text(line, pos, &(c->t.path_s), &(c->check.s_text)));
	}
	else if (ft_strcmp(id, "F") == 0)
		return (ft_cf(line, pos, &(c->f), &(c->check.f_color)));
	else if (ft_strcmp(id, "C") == 0)
		return (ft_cf(line, pos, &(c->c), &(c->check.c_color)));
	return (0);
}

/*
** Si un indentier est trouvé en début de ligne,
** la fonction le compare à ceux de la liste donnée et oriente
** la suite du parsing en fonction de la correspondance trouvée.
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : un pointeur vers une t_configuration.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int		ft_elem_parsing(char *line, t_data *c)
{
	t_data	c_2;
	size_t	pos;
	char	*id;
	int		ret;

	c_2 = *c;
	pos = 0;
	ret = -1;
	if (!(id = (char *)malloc(sizeof(char) * 3)))
		return (ret);
	if (ft_find_id(line, id, &pos) == 1)
		ret = ft_get_config(id, line, &pos, &c_2);
	else if (line[0] == '\0')
		ret = 1;
	free(id);
	*c = c_2;
	return (ret);
}

/*
** Vérifie la validité des lignes décrivant la map et crée
** une version 1D de celle-ci.
** =========
** #1 : le retour de GNL.
** #2 : un pointeur sur une t_map.
** #3 : un pointeur sur une t_configuration.
** #4 : la chaîne de caractères actuelle (lue par GNL).
** #5 : la chaîne de caractères précédente (lue par GNL).
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_orient_gnl(int ret_gnl, t_map *m, t_data *c, t_duo duo)
{
	char		*str;
	int			ret_ep;
	size_t		i;

	str = ft_strdup(duo.line);
	ret_ep = ft_elem_parsing(str, c);
	i = 0;
	
	printf("line = %s - prev = %s\n", duo.line, duo.prev);

	if (ret_gnl == 0)
	{
		if (ft_closed_map(str, &i) == 0 || ((ft_closed_map(str, &i) == 1)
		&& (ft_lines(str, duo.prev, m, c) == 0)))
		{
			return (0);
		}
		m->two_d = ft_split(m->map, '-');
	}
	else
	{
		if (ret_ep == 1)
			free(duo.prev);
		else if ((ret_ep == 0) || ((ret_ep == -1)
		&& (ft_lines(str, duo.prev, m, c) == 0)))
			return (0);
	}
	free(str);
	return (1);
}

/*
** Ouvre le fichier donné grâce à son chemin,
** le parcourt et remplis un t_cub pointé par ptr
** avec les informations trouvées.
** =========
** #1 : le chemin vers le fichier donné.
** #2 : un pointeur sur un t_cub.
** =========
** Retourne 1 si toutes les informations ont été trouvées
** et sont valides (sauf les chemins vers les textures qu'on
** ne peut pas vérifier tout de suite), 0 sinon.
*/

int		ft_parse_fd(char *fd_path, t_pars *ptr)
{
	int		fd;
	int		ret_gnl;
	t_duo	duo;

	fd = open(fd_path, O_RDONLY);
	ret_gnl = 1;
	duo.line = NULL;
	duo.prev = NULL;
	while (ret_gnl > 0)
	{
		ret_gnl = gnl(fd, &duo.line);
		if (ft_orient_gnl(ret_gnl, &(ptr->map), &(ptr->data), duo) == 0)
			return (0);
		if (ret_gnl != 0)
			duo.prev = ft_strdup(duo.line);
		free(duo.line);
	}
	if (&(ptr->map.card) == not_given)
		return (0);
	return (1);
}
