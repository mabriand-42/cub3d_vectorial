/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
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

void	ft_transform_sprite(t_cub *cub, int i)
{
	t_vect	sprite;
	double	matrix;

	sprite.x = cub->sprite.coor[cub->sprite.rank[i]].x - cub->player.pos.x;
	sprite.y = cub->sprite.coor[cub->sprite.rank[i]].y - cub->player.pos.y;
	matrix = 1.0 / (cub->player.plane.x * cub->player.dir.y -
					cub->player.plane.y * cub->player.dir.x);
	cub->sprite.trans.x = matrix * (cub->player.dir.y * sprite.x -
									cub->player.dir.x * sprite.y);	
	cub->sprite.trans.y = matrix * (-cub->player.plane.y * sprite.x +
									cub->player.plane.x * sprite.y);
	cub->sprite.s_cam = (int)((cub->img.r.x / 2) * (1 + cub->sprite.trans.x / cub->sprite.trans.y));
}

/*
** Coms
*/

void	ft_get_sprite(t_cub *cub, double *dst)
{
	t_box	s;
	
	s.y = abs((int)(cub->img.r.y / cub->sprite.trans.y));
	s.x = abs((int)(cub->img.r.y / cub->sprite.trans.y));

	cub->draw.sprite_h.x = -s.y / 2 + cub->img.r.y / 2;
	if (cub->draw.sprite_h.x < 0)
		cub->draw.sprite_h.x = 0;
	cub->draw.sprite_h.y = s.y / 2 + cub->img.r.y / 2;
	if (cub->draw.sprite_h.y >= cub->img.r.y)
		cub->draw.sprite_h.y = cub->img.r.y - 1;

	cub->draw.sprite_w.x = -s.x / 2 + cub->sprite.s_cam;
	if (cub->draw.sprite_w.x < 0)
		cub->draw.sprite_w.x = 0;
	cub->draw.sprite_w.y = s.x / 2 + cub->sprite.s_cam;
	if (cub->draw.sprite_w.y >= cub->img.r.x)
		cub->draw.sprite_w.y = cub->img.r.x - 1;
	ft_loop(cub, s, dst);
}

/*
** Coms
*/

void	ft_loop(t_cub *cub, t_box sprite, double *dst)
{
	t_box	loop;
	int		d;

	loop.x = cub->draw.sprite_w.x;
	while (loop.x < cub->draw.sprite_w.y)
	{
		loop.y = cub->draw.sprite_h.x;
		cub->cast.in_t.x = (int)(256 * (loop.x - (-sprite.x / 2 + cub->sprite.s_cam))
							* cub->texture.s_img.r.x) / sprite.x / 256;
		if (cub->sprite.trans.y > 0 && loop.x > 0 &&
			cub->sprite.trans.y	< dst[cub->draw.sprite_w.x] && loop.x < cub->img.r.x)
		{
			while (loop.y < cub->draw.sprite_h.y)
			{
				d = loop.y * 256 - cub->img.r.y * 128 + sprite.y * 128;
				ft_find_s_color(cub, dst, sprite, d, loop);
				ft_print_s_color(cub, loop.x, loop.y);
				loop.y++;
			}
		}
		loop.x++;
	}
}

/*
** Coms
*/

void	ft_find_s_color(t_cub *cub, double *dst, t_box sprite, int d, t_box size)
{
	cub->cast.in_t.y = ((d * cub->texture.s_img.r.y) / sprite.y) / 256;
	cub->sprite.color = cub->texture.s_img.i_addr
						[cub->texture.s_img.r.y * cub->cast.in_t.y + cub->cast.in_t.x];
}

void	ft_print_sprite(t_cub *cub, double *dst)
{
	int i;

	i = 0;
	while (i < cub->sprite.count)
	{
		ft_transform_sprite(cub, i);
		ft_get_sprite(cub, dst);
		i++;
	}
}