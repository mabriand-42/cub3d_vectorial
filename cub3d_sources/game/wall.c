/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
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

void	ft_get_sides(t_cub *cub)
{
	cub->cast.delta_dist.x = fabs(1 / cub->cast.ray_dir.x);
	cub->cast.delta_dist.y = fabs(1 / cub->cast.ray_dir.y);
	ft_side_x(cub);
	ft_side_y(cub);
}

/*
** Coms
*/

void	ft_side_x(t_cub *cub)
{
	if (cub->cast.ray_dir.x < 0)
	{
		cub->cast.step.x = -1;
		cub->cast.side_dist.x = (cub->player.pos.x
			- cub->cast.map.x) * cub->cast.delta_dist.x;
	}
	else
	{
		cub->cast.step.x = 1;
		cub->cast.side_dist.x = (cub->cast.map.x + 1.0
			- cub->player.pos.x) * cub->cast.delta_dist.x;
	}
}

/*
** Coms
*/

void	ft_side_y(t_cub *cub)
{
	if (cub->cast.ray_dir.y < 0)
	{
		cub->cast.step.y = -1;
		cub->cast.side_dist.y = (cub->player.pos.y
			- cub->cast.map.y) * cub->cast.delta_dist.y;
	}
	else
	{
		cub->cast.step.y = 1;
		cub->cast.side_dist.y = (cub->cast.map.y + 1.0
			- cub->player.pos.y) * cub->cast.delta_dist.y;
	}
}

/*
** Coms
*/

void	ft_we_wall(t_cub *cub)
{
	if (cub->cast.ray_dir.x < 0)
		cub->cast.wall = west;
	else
		cub->cast.wall = east;
}

/*
** Coms
*/

void	ft_ns_wall(t_cub *cub)
{
	if (cub->cast.ray_dir.y < 0)
		cub->cast.wall = north;
	else
		cub->cast.wall = south;
}
