/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Calcule la taille de la partie de la ligne
** de pixels correspondant au mur.
** =========
** #1 : un pointeur sur une t_cub.
** =========
** Retourne la taille calculée.
*/

void	ft_get_slice(t_cub *cub, double *dst, int index)
{
	if (cub->cast.wall == north || cub->cast.wall == south)
	{
		cub->cast.slice = (cub->cast.map.y - cub->player.pos.y +
				(1 - cub->cast.step.y) / 2) / cub->cast.ray_dir.y;
	}
	else
	{
		cub->cast.slice = (cub->cast.map.x - cub->player.pos.x +
				(1 - cub->cast.step.x) / 2) / cub->cast.ray_dir.x;
	}
	dst[index] = cub->cast.slice;
}

/*
** Calcule la position du pixel de départ
** du mur et celle du pixel de fin sur la
** colomne j et rentre ces infos dans les
** champs de la structure t_cub correspondants.
** =========
** #1 : un pointeur sur une t_cub.
** =========
*/

void	ft_get_wall(t_cub *cub, double *dst, int index)
{
	ft_get_slice(cub, dst, index);
	cub->cast.line_height = (int)(cub->img.r.y / cub->cast.slice);
	cub->draw.wall.x = -cub->cast.line_height / 2 + cub->img.r.y / 2;
	if (cub->draw.wall.x < 0)
		cub->draw.wall.x = 0;
	cub->draw.wall.y = cub->cast.line_height / 2 + cub->img.r.y / 2;
	if (cub->draw.wall.y >= cub->img.r.y)
		cub->draw.wall.y = cub->img.r.y - 1;
}

/*
** Coms
*/

void	ft_draw(t_cub *cub, int i)
{
	t_image	*texture;
	int		j;

	texture = ft_choose_text(cub);
	j = 0;
	while (j < cub->draw.wall.x)
	{
		if (cub->bool_img == 0)
			ft_my_mlx_pixel_put(&cub->img, i, j, cub->draw.c_rgb);
		else
			ft_my_mlx_pixel_put(&cub->img2, i, j, cub->draw.c_rgb);
		j++;
	}
	ft_mapping(cub, *texture, i, &j);
	while (j >= cub->draw.wall.y && j < cub->img.r.y)
	{
		if (cub->bool_img == 0)
			ft_my_mlx_pixel_put(&cub->img, i, j, cub->draw.f_rgb);
		else
			ft_my_mlx_pixel_put(&cub->img2, i, j, cub->draw.f_rgb);
		j++;
	}
}

/*
** Coms
*/

void	ft_my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_line + x * (image->bpp / 8));
	*(int*)dst = color;
}

/*
** Coms
*/

void	ft_print_s_color(t_cub *cub, int x, int y)
{
	cub->spr.color = cub->text.s_img.i_addr[cub->text.s_img.r.y
						* cub->cast.in_t.y + cub->cast.in_t.x];
	if ((cub->spr.color & 0x00FFFFFF) != 0)
	{
		if (cub->bool_img == 0)
			ft_my_mlx_pixel_put(&cub->img, x, y, cub->spr.color);
		else
			ft_my_mlx_pixel_put(&cub->img2, x, y, cub->spr.color);
	}
}
