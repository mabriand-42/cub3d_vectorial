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
int    ft_get_img_data(t_image *img, void *mlx_ptr)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, img->path, &img->r.x, &img->r.y);
	if (img->img_ptr != NULL)
	{
    	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
		img->i_addr = (int*)img->addr;
		return (1);
	}
	else
		return (0);
    
}
void	ft_generate_texture(t_cub *cub)
{
	if (ft_get_img_data(&cub->texture.no_img, cub->mlx_ptr) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->texture.so_img, cub->mlx_ptr) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->texture.we_img, cub->mlx_ptr) == 0)
		ft_close_pgm(cub);
	if (ft_get_img_data(&cub->texture.ea_img, cub->mlx_ptr) == 0)
		ft_close_pgm(cub);
	/*if (ft_get_img_data(&cub->texture.s_img, cub->mlx_ptr) == 0)
		ft_close_pgm(cub);*/
}

void	ft_init_image(t_cub *cub)
{
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, cub->img.r.x,
					cub->img.r.y);
	cub->img.addr = mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp,
					&cub->img.size_line, &cub->img.endian);
	cub->img.i_addr = (int*)cub->img.addr;
}
