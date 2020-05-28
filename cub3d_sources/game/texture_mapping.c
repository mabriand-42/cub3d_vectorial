/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c.                                 :+:      :+:    :+:   */
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

void	ft_pos_in_wall(t_cub *cub)
{
	if (cub->cast.wall == north  || cub->cast.wall == south)
		cub->cast.in_w = cub->player.pos.x + cub->cast.slice * cub->cast.ray_dir.x;
	if (cub->cast.wall == west  || cub->cast.wall == east)
		cub->cast.in_w = cub->player.pos.y + cub->cast.slice * cub->cast.ray_dir.y;
	cub->cast.in_w -= floor(cub->cast.in_w);
}

/*
** Coms
*/

void	ft_pos_in_text(t_cub *cub, t_image texture)
{
	cub->cast.in_t.x = (int)(cub->cast.in_w * (double)texture.r.x);
	if ((cub->cast.wall == north  || cub->cast.wall == south) && cub->cast.ray_dir.x > 0)
		cub->cast.in_t.x = texture.r.x - cub->cast.in_t.x - 1;
	if ((cub->cast.wall == west  || cub->cast.wall == east) && cub->cast.ray_dir.y < 0)
		cub->cast.in_t.x = texture.r.x - cub->cast.in_t.x - 1;
}

/*
** Coms
*/

void	ft_mapping(t_cub *cub, t_image texture, int  *i, int *j)
{
	double	step;
	double	text;
	int		color;
	int		pos;
	
	step = texture.r.x / cub->cast.line_height;
	text = (cub->draw.wall.x - cub->img.r.y / 2 + cub->cast.line_height / 2) * step;
	while (*j >= cub->draw.wall.x && *j < cub->draw.wall.y)
	{
		cub->cast.in_t.y = (int)text & texture.r.y;
		text += step;
		pos = texture.r.y * cub->cast.in_t.y + cub->cast.in_t.x;
		color = mlx_get_color_value(cub->mlx_ptr, texture.i_addr[pos]);
		my_mlx_pixel_put(&cub->img, *i, *j, color);
		(*j)++;
	}
}

/*
** Coms
*/

t_image		*ft_choose_text(t_cub *cub)
{
	if (cub->cast.wall == north)
		return (&cub->texture.no_img);
	if (cub->cast.wall == south)
		return (&cub->texture.so_img);
	if (cub->cast.wall == east)
		return (&cub->texture.ea_img);
	if (cub->cast.wall == west)
		return (&cub->texture.we_img);
	return(NULL);
}
