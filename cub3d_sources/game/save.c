/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:41 by mabriand          #+#    #+#             */
/*   Updated: 2020/04/08 16:44:43 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Comms
*/
unsigned char	*ft_file_bmp(int size)
{
	unsigned char	*file;

	if (!(file = malloc(14 * sizeof(unsigned char))))
		exit(EXIT_FAILURE);
	ft_bzero(file, 14);
	file[0] = 'B';
	file[1] = 'M';
	file[2] = (unsigned char)(size);
	file[3] = (unsigned char)(size >> 8);
	file[4] = (unsigned char)(size >> 16);
	file[5] = (unsigned char)(size >> 24);
	file[10] = 54;
	return (file);
}

unsigned char	*ft_info_bmp(t_cub *cub)
{
	unsigned char	*info;

	if (!(info = malloc(40 * sizeof(unsigned char))))
		exit(EXIT_FAILURE);
	ft_bzero(info, 40);
	info[0] = 40;
	info[4] = (unsigned char)(cub->win.r.x);
	info[5] = (unsigned char)(cub->win.r.x >> 8);
	info[6] = (unsigned char)(cub->win.r.x >> 16);
	info[7] = (unsigned char)(cub->win.r.x >> 24);
	info[8] = (unsigned char)(cub->win.r.x);
	info[9] = (unsigned char)(cub->win.r.x >> 8);
	info[10] = (unsigned char)(cub->win.r.x >> 16);
	info[11] = (unsigned char)(cub->win.r.x >> 24);
	info[12] = 1;
	info[14] = 32;
	return (info);
}

void		ft_write_data(int file, char *data, t_cub *cub)
{
	int		line;
	int		pos;
	int		color;

	line = cub->win.r.y - 1;
	while (line >= 0)
	{
		pos = 0;
		while (pos < cub->win.r.x)
		{
			color = *(unsigned int*)(data +
									(line * cub->img.size_line + pos * 4));
			write(file, &color, 4);
			pos++;
		}
		line--;
	}
}

void		ft_save(t_cub *cub)
{
	int				size;
	int				fd;
	unsigned char	*file;
	unsigned char	*info;

	size = 54 + 4 * cub->win.r.x * cub->win.r.y;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
											O_TRUNC, 0755);
	file = ft_file_bmp(size);
	write(fd, file, 14);
	free(file);
	info = ft_info_bmp(cub);
	write(fd, info, 40);
	free(info);
	ft_write_data(fd, cub->img.addr, cub);
	if (cub->save == yes)
		exit(EXIT_SUCCESS);
}
