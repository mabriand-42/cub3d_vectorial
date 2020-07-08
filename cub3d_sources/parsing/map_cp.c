/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:13:57 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 09:56:57 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

int		ft_index_zero(char c1, char *line)
{
	char	c2;
	char	c3;

	c2 = line[0];
	c3 = line[1];
	if (c1 != ' ' && c1 != '1')
		return (0);
	if (c2 != ' ' && c2 != '1')
		return (0);
	if (c1 == ' ' && (c3 == '0' || c3 == '2' || ft_iscardinal(c2) == 1))
		return (0);
	return (1);
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
		return (ft_check_end(prev, &j));
	else if (next[i] != '\0' && prev[j] == '\0')
		return (ft_check_end(next, &i));
	else
		return (0);
}

/*
** Coms
** else if (m->end == no && ft_closed_map(str, &i) == 1)
** {
** free(str);
** return (0);
** }
*/

int		ft_zero_gnl(t_map *m, char *str, t_duo duo, t_data *c)
{
	size_t	i;

	i = 0;
	if (m->first == yes && m->end == no && ft_closed_map(str, &i) == 1)
	{
		if (ft_lines(str, duo.prev, m, c) == 0)
		{
			free(str);
			return (0);
		}
		m->end = yes;
		m->two_d = ft_split(m->map, '-');
		return (1);
	}
	else if (m->end == yes && ft_is_empty_string(str) == 1)
	{
		m->two_d = ft_split(m->map, '-');
		return (1);
	}
	else
	{
		free(str);
		return (0);
	}
}

/*
** Coms
*/

int		ft_past_gnl(int fd, t_pars *ptr)
{
	close(fd);
	if (ptr->map.card == not_given || ptr->map.end == no)
	{
		ft_printf("Error\nAre you sure your player is valid? \n");
		ft_free_path_bis(&(ptr->data));
		free(ptr->map.map);
		return (0);
	}
	free(ptr->map.map);
	return (1);
}

/*
** Coms
*/

int		ft_nz_gnl(t_map *m, char *str, t_duo duo, t_data *c)
{
	int			ret_ep;

	ret_ep = ft_elem_parsing(str, c);
	if ((ret_ep == -1 && ft_lines(str, duo.prev, m, c) == 0) ||
		(ret_ep == 1 && m->end == yes && ft_lines(str, duo.prev, m, c) == 0)
		|| (ret_ep == 1 && m->first == yes && m->end == no &&
		ft_lines(str, duo.prev, m, c) == 0) || (ret_ep == 0))
	{
		if (ret_ep == 0 || ret_ep == -1)
			ft_printf("Your file .cub is invalid\n");
		free(str);
		ft_free_path_bis(c);
		return (0);
	}
	return (1);
}
