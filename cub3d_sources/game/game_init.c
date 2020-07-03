/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
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

void	ft_init_cub(t_cub *cub)
{
	cub->mlx_ptr = NULL;
	ft_init_player(&(cub->player));
	ft_init_cast(&(cub->cast));
	ft_init_draw(&(cub->draw));
}

/*
** Coms
*/

void	ft_init_player(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.x = 0;
	player->box.x = 0;
	player->box.y = 0;
}

/*
** Coms
*/

void	ft_init_cast(t_cast *cast)
{
	cast->cam = 0;
	cast->ray_dir.x = 0;
	cast->ray_dir.y = 0;
	cast->delta_dist.x = 0;
	cast->delta_dist.y = 0;
	cast->side_dist.x = 0;
	cast->side_dist.y = 0;
	cast->step.x = 0;
	cast->step.y = 0;
	cast->map.x = 0;
	cast->map.y = 0;
	cast->wall = not_given;
	cast->line_height = 0;
	cast->slice = 0;
	cast->in_w = 0;
	cast->in_t.x = 0;
	cast->in_t.y = 0;
}

/*
** Coms
*/

void	ft_init_draw(t_draw *draw)
{
	draw->c_rgb = 0;
	draw->f_rgb = 0;
	draw->ceiling.x = 0;
	draw->ceiling.y = 0;
	draw->floor.x = 0;
	draw->floor.y = 0;
	draw->wall.x = 0;
	draw->wall.y = 0;
	draw->spr_h.x = 0;
	draw->spr_h.y = 0;
	draw->spr_w.x = 0;
	draw->spr_w.y = 0;
}
