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
** #1 : un pointeur sur un t_cub.
** =========
** Retourne la taille calculée.
*/

double	ft_get_slice(t_cub *cub)
{
	double	slice;

	slice = 0;
	if (cub->cast.wall == north || cub->cast.wall == south)
	{
		slice = (cub->cast.map.y - cub->player.pos.y +
				(1 - cub->cast.step.y) / 2) / cub->cast.ray_dir.y;
	}
	else
	{
		slice = (cub->cast.map.x - cub->player.pos.x +
				(1 - cub->cast.step.x) / 2) / cub->cast.ray_dir.x;
	}
	return (slice);
}

/*
** Calcule la position du pixel de départ
** du mur et celle du pixel de fin sur la
** colomne j et rentre ces infos dans les
** champs de cub correspondants.
** =========
** #1 : un pointeur sur un t_cub.
** =========
*/

void	ft_draw_wall(t_cub *cub)
{
	double	height;
	double	slice;
	int		line_height;

	height = (double)cub->img.r.y;
	slice = ft_get_slice(cub);
	line_height = (int)(height / slice);

	cub->draw.wall.x = -line_height / 2 + height / 2;
	if (cub->draw.wall.x < 0)
		cub->draw.wall.x = 0;
	cub->draw.wall.y = line_height / 2 + height / 2;
	if (cub->draw.wall.y >= height)
		cub->draw.wall.y = height - 1;
}

/*
** Coms
*/

void	ft_draw(t_cub *cub, int i)
{
	int couleur_mur;
	int j;
	if (cub->cast.wall == north)
		couleur_mur = ft_create_rgb(103,231,69);
	else if (cub->cast.wall == south)
		couleur_mur = ft_create_rgb(231,69,69);
	else if (cub->cast.wall == west)
		couleur_mur = ft_create_rgb(175,69,231);
	else if (cub->cast.wall == east)
		couleur_mur = ft_create_rgb(231,216,69);

	j = 0;
	while (j < cub->draw.wall.x)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, cub->draw.c_rgb);
		j++;
	}
	while (j >= cub->draw.wall.x && j < cub->draw.wall.y)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, couleur_mur);
		j++;
	}
	while (j >= cub->draw.wall.y && j < cub->img.r.y)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, cub->draw.f_rgb);
		j++;
	}
}







/*void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}*/