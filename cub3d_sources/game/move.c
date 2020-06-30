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
** Coms
*/

void	ft_move_wa(int keycode, t_cub *cub)
{
	if (keycode == K_W)
	{
		if (ft_iswalkable(cub->box_map[(int)(cub->player.pos.y
						+ cub->player.dir.y * STEP_MOV)]
						[(int)cub->player.pos.x]) == 1)
			cub->player.pos.y += cub->player.dir.y * STEP_MOV;
		if (ft_iswalkable(cub->box_map[(int)cub->player.pos.y]
						[(int)(cub->player.pos.x
						+ cub->player.dir.x * STEP_MOV)]) == 1)
			cub->player.pos.x += cub->player.dir.x * STEP_MOV;
	}
	if (keycode == K_A)
	{
		if (ft_iswalkable(cub->box_map[(int)(cub->player.pos.y
						- cub->player.dir.y * STEP_MOV)]
						[(int)cub->player.pos.x]) == 1)
			cub->player.pos.y -= cub->player.dir.y * STEP_MOV;
		if (ft_iswalkable(cub->box_map[(int)cub->player.pos.y]
						[(int)(cub->player.pos.x
						- cub->player.dir.x * STEP_MOV)]) == 1)
			cub->player.pos.x -= cub->player.dir.x * STEP_MOV;
	}
}

/*
** Coms
*/

void	ft_move_sd(int keycode, t_cub *cub)
{
	if (keycode == K_D)
	{
		if (ft_iswalkable(cub->box_map[(int)(cub->player.pos.y
						+ cub->player.plane.y * STEP_MOV)]
						[(int)cub->player.pos.x]) == 1)
			cub->player.pos.y += cub->player.plane.y * STEP_MOV;
		if (ft_iswalkable(cub->box_map[(int)cub->player.pos.y]
						[(int)(cub->player.pos.x
						+ cub->player.plane.x * STEP_MOV)]) == 1)
			cub->player.pos.x += cub->player.plane.x * STEP_MOV;
	}
	if (keycode == K_S)
	{
		if (ft_iswalkable(cub->box_map[(int)(cub->player.pos.y
						- cub->player.plane.y * STEP_MOV)]
						[(int)cub->player.pos.x]) == 1)
			cub->player.pos.y -= cub->player.plane.y * STEP_MOV;
		if (ft_iswalkable(cub->box_map[(int)cub->player.pos.y]
						[(int)(cub->player.pos.x
						- cub->player.plane.x * STEP_MOV)]) == 1)
			cub->player.pos.x -= cub->player.plane.x * STEP_MOV;
	}
}
