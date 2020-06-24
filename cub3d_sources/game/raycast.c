/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

void	ft_init_camera(t_cub *cub, int x, int width)
{
	cub->cast.cam = 2 * x / (double)width - 1;
	cub->cast.ray_dir.x = cub->player.dir.x
						+ cub->player.plane.x * cub->cast.cam;
	cub->cast.ray_dir.y = cub->player.dir.y
						+ cub->player.plane.y * cub->cast.cam;
}

/*
** Coms
*/

void	ft_wall_search(t_cub *cub)
{
	int h;

	h = 0;
	while (h == 0)
	{
		if (cub->cast.side_dist.x > cub->cast.side_dist.y)
		{
			cub->cast.side_dist.y += cub->cast.delta_dist.y;
			cub->cast.map.y += cub->cast.step.y;
			ft_ns_wall(cub);
		}
		else
		{
			cub->cast.side_dist.x += cub->cast.delta_dist.x;
			cub->cast.map.x += cub->cast.step.x;
			ft_we_wall(cub);
		}
		if (cub->box_map[cub->cast.map.y][cub->cast.map.x] == '1')
			h = 1;
	}
}

/*
** Coms
*/

int		ft_raycast(t_cub *cub)
{
	int		x;
	int		width;
	double	buffer[cub->img.r.x];

	x = 0;
	width = cub->img.r.x;
	while (x < width)
	{
		cub->cast.map.x = (int)cub->player.pos.x;
		cub->cast.map.y = (int)cub->player.pos.y;
		ft_init_camera(cub, x, width);
		ft_get_sides(cub);
		ft_wall_search(cub);
		ft_get_wall(cub, buffer, x);
		ft_draw(cub, x);
		x++;
	}
	ft_gather_sprite(cub);
	ft_print_sprite(cub, buffer);
	return (1);
}
