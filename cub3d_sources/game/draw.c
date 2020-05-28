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

void	ft_get_slice(t_cub *cub)
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

void	ft_get_wall(t_cub *cub)
{
	ft_get_slice(cub);
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
	//t_image *texture;
	int couleur_mur;
	int j;
	ft_init_image(cub);
	//texture = ft_choose_text(cub);
	//printf("texture choisie : %s\n", texture->path);
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
		my_mlx_pixel_put(&cub->img, i, j, cub->draw.c_rgb);
		j++;
	}
	while (j >= cub->draw.wall.x && j < cub->draw.wall.y)
	{
		my_mlx_pixel_put(&cub->img, i, j, couleur_mur);
		j++;
	}
	while (j >= cub->draw.wall.y && j < cub->img.r.y)
	{
		my_mlx_pixel_put(&cub->img, i, j, cub->draw.f_rgb);
		j++;
	}
}



/*
** Coms
*/

/*void	ft_draw(t_cub *cub, int i)
{
	t_image *texture;
	int j;

	texture = ft_choose_text(cub);
	printf("texture choisie : %s\n", texture->path);
	j = 0;
	while (j < cub->draw.wall.x)
	{
		my_mlx_pixel_put(&cub->img, i, j, cub->draw.c_rgb);
		j++;
	}
	printf("first color is ok\n");
	ft_mapping(cub, *texture, &i, &j);
	while (j >= cub->draw.wall.y && j < cub->img.r.y)
	{
		my_mlx_pixel_put(&cub->img, i, j, cub->draw.f_rgb);
		j++;
	}
}*/


/*
** Coms
*/


void		my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;
	
	dst = image->addr + (y * image->size_line + x * (image->bpp / 8));
	*(int*)dst = color;
}