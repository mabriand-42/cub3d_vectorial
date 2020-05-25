/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Comms
*/

void	ft_rotate(int keycode, t_cub *cub)
{
	if (keycode == K_AR_R)
		ft_rotate_right(cub);
	if (keycode == K_AR_L)
		ft_rotate_left(cub);
}

/*
** Coms
*/

void	ft_rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir.x;
	old_plane_x = cub->player.plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(-STEP_ROT)
						- cub->player.dir.y * sin(-STEP_ROT);
	cub->player.dir.y = old_dir_x * sin(-STEP_ROT)
						+ cub->player.dir.y * cos(-STEP_ROT);
	cub->player.plane.x = cub->player.plane.x * cos(-STEP_ROT)
						- cub->player.plane.y * sin(-STEP_ROT);
	cub->player.plane.y = old_plane_x * sin(-STEP_ROT)
						+ cub->player.plane.y * cos(-STEP_ROT);
}

/*
** Coms
*/


void	ft_rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir.x;
	old_plane_x = cub->player.plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(STEP_ROT)
						- cub->player.dir.y * sin(STEP_ROT);
	cub->player.dir.y = old_dir_x * sin(STEP_ROT)
						+ cub->player.dir.y * cos(STEP_ROT);
	cub->player.plane.x = cub->player.plane.x * cos(STEP_ROT)
						- cub->player.plane.y * sin(STEP_ROT);
	cub->player.plane.y = old_plane_x * sin(STEP_ROT)
						+ cub->player.plane.y * cos(STEP_ROT);
}
