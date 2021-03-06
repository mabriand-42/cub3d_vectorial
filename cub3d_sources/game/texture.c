/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

int		ft_get_img_data(t_image *img, void *mlx_ptr, t_cub *cub)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, img->path,
										&img->r.x, &img->r.y);
	if (img->img_ptr != NULL)
	{
		img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
									&img->size_line, &img->endian);
		img->i_addr = (int*)img->addr;
		return (1);
	}
	else
	{
		cub->start = no;
		cub->end = yes;
		return (0);
	}
}

/*
** Coms
*/

void	ft_generate_texture(t_cub *cub)
{
	cub->text.no_img.img_ptr = NULL;
	cub->text.so_img.img_ptr = NULL;
	cub->text.we_img.img_ptr = NULL;
	cub->text.ea_img.img_ptr = NULL;
	cub->text.s_img.img_ptr = NULL;
	if (ft_get_img_data(&cub->text.no_img, cub->mlx_ptr, cub) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->text.so_img, cub->mlx_ptr, cub) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->text.we_img, cub->mlx_ptr, cub) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->text.ea_img, cub->mlx_ptr, cub) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->text.s_img, cub->mlx_ptr, cub) == 0)
		ft_close_pgm(cub);
}

/*
** Coms
*/

void	ft_init_image(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, cub->img.r.x,
					cub->img.r.y);
	if (cub->img.img_ptr != NULL)
	{
		cub->img.addr = mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp,
						&cub->img.size_line, &cub->img.endian);
		cub->img.i_addr = (int*)cub->img.addr;
	}
	cub->img2.img_ptr = mlx_new_image(cub->mlx_ptr, cub->img.r.x,
					cub->img.r.y);
	if (cub->img2.img_ptr != NULL)
	{
		cub->img2.addr = mlx_get_data_addr(cub->img2.img_ptr, &cub->img2.bpp,
						&cub->img2.size_line, &cub->img2.endian);
		cub->img2.i_addr = (int*)cub->img2.addr;
	}
}
