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

	sprite.x = cub->spr.coor[cub->spr.rank[i]].x - cub->player.pos.x;
	sprite.y = cub->spr.coor[cub->spr.rank[i]].y - cub->player.pos.y;
	matrix = 1.0 / (cub->player.plane.x * cub->player.dir.y -
					cub->player.dir.x * cub->player.plane.y);
	cub->spr.trans.x = matrix * (cub->player.dir.y * sprite.x -
									cub->player.dir.x * sprite.y);
	cub->spr.trans.y = matrix * (-cub->player.plane.y * sprite.x +
									cub->player.plane.x * sprite.y);
}

/*
** Coms
*/

void	ft_get_sprite(t_cub *cub, double *dst)
{
	t_box	s;

	cub->spr.s_cam = (int)((cub->img.r.x / 2) *
						(1 + cub->spr.trans.x / cub->spr.trans.y));
	s.y = abs((int)(cub->img.r.y / cub->spr.trans.y));
	s.x = abs((int)(cub->img.r.y / cub->spr.trans.y));
	cub->draw.spr_h.x = -s.y / 2 + cub->img.r.y / 2;
	if (cub->draw.spr_h.x < 0)
		cub->draw.spr_h.x = 0;
	cub->draw.spr_h.y = s.y / 2 + cub->img.r.y / 2;
	if (cub->draw.spr_h.y >= cub->img.r.y)
		cub->draw.spr_h.y = cub->img.r.y - 1;
	cub->draw.spr_w.x = -s.x / 2 + cub->spr.s_cam;
	if (cub->draw.spr_w.x < 0)
		cub->draw.spr_w.x = 0;
	cub->draw.spr_w.y = s.x / 2 + cub->spr.s_cam;
	if (cub->draw.spr_w.y >= cub->img.r.x)
		cub->draw.spr_w.y = cub->img.r.x - 1;
	ft_loop(cub, s, dst);
}

/*
** Coms
*/

void	ft_loop(t_cub *cub, t_box s, double *dst)
{
	int	h;
	int	d;

	while (cub->draw.spr_w.x < cub->draw.spr_w.y)
	{
		h = cub->draw.spr_h.x;
		cub->cast.in_t.x = (int)(256 * (cub->draw.spr_w.x - (-s.x / 2 +
					cub->spr.s_cam)) * cub->text.s_img.r.x) / s.x / 256;
		if (cub->cast.in_t.x < 0)
			cub->cast.in_t.x = 0;
		if (cub->spr.trans.y > 0 && cub->draw.spr_w.x > 0 && cub->spr.trans.y
				< dst[cub->draw.spr_w.x] && cub->draw.spr_w.x < cub->img.r.x)
		{
			while (h < cub->draw.spr_h.y)
			{
				d = h * 256 - cub->img.r.y * 128 + s.y * 128;
				cub->cast.in_t.y = ((d * cub->text.s_img.r.y) / s.y) / 256;
				if (cub->cast.in_t.y < 0)
					cub->cast.in_t.y = 0;
				ft_print_s_color(cub, cub->draw.spr_w.x, h);
				h++;
			}
		}
		cub->draw.spr_w.x++;
	}
}

/*
** Coms
*/

void	ft_print_sprite(t_cub *cub, double *dst)
{
	size_t i;

	i = 0;
	while (i < cub->spr.count)
	{
		ft_transform_sprite(cub, i);
		ft_get_sprite(cub, dst);
		i++;
	}
}
