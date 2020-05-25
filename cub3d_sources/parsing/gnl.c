/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Renvoie une ligne lue depuis un descripteur de fichier,
** sans le retour à la ligne. Le buffer a une taille défaut.
** =========
** #1 : le fd donné par open().
** #2 : un pointeur sur une chaîne de caractères.
** =========
** Retourne 1 si une ligne a été lue, 0 si l'EOF a été atteint,
** -1 si une erreur est survenue.
*/

int		gnl(int fd, char **line)
{
	static char	buffer[4096];
	ssize_t		ret_read;
	ssize_t		ret_search;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strdup(buffer);
	if ((ret_search = ft_search_line(buffer)) >= 0)
	{
		free(*line);
		(*line) = ft_strndup(buffer, ret_search);
		ft_reinit_buffer(ret_search, buffer);
		return (1);
	}
	while ((ret_read = read(fd, buffer, 4096)) > 0)
	{
		ret_search = ft_search_line(buffer);
		if (ft_get_line(line, buffer, ret_search, ret_read) == 1)
			return (1);
	}
	if (ret_read == 0)
		return (0);
	return (-1);
}
