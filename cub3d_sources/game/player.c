/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
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

void	ft_get_orientation(t_card card, t_cub *cub)
{
	if (card == north)
	{
		cub->player.dir.x = 0;
		cub->player.dir.y = -1;
	}
	if (card == south)
	{
		cub->player.dir.x = 0;
		cub->player.dir.y = 1;
	}
	if (card == west)
	{
		cub->player.dir.x = -1;
		cub->player.dir.y = 0;
	}
	if (card == east)
	{
		cub->player.dir.x = 1;
		cub->player.dir.y = 0;
	}
}

/*
** Coms
*/

int		ft_get_player_pos(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->box_map[i] != NULL)
	{
		j = 0;
		while (cub->box_map[i][j] != '\0')
		{
			if (ft_iscardinal(cub->box_map[i][j]) == 1)
			{
				cub->player.pos.x = (double)j + 0.5;
				cub->player.pos.y = (double)i + 0.5;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Coms
*/

void	ft_get_plane(t_cub *cub)
{
	double	radian;
	double	half_fov;

	radian = ft_deg_to_rad(FOV);
	half_fov = radian / 2.0;
	cub->player.plane.x = -(cub->player.dir.y * tan(half_fov));
	cub->player.plane.y = (cub->player.dir.x * tan(half_fov));
}

/*
** Coms
*/

int		ft_get_player_data(t_cub *cub)
{
	if (ft_get_player_pos(cub) == 0)
	{
		ft_printf("Error\nAre you sure your player is valid? \n");
		return (0);
	}
	ft_get_plane(cub);
	return (1);
}
