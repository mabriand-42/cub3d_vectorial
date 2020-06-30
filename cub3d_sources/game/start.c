/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
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

void	ft_check_screen(t_cub *cub)
{
	int width;
	int height;

	mlx_get_screen_size(cub->mlx_ptr, &width, &height);
	if (cub->win.r.x > width)
	{
		cub->win.r.x = width;
		cub->img.r.x = width;
	}
	if (cub->win.r.y > height)
	{
		cub->win.r.y = height;
		cub->img.r.y = height;
	}
}

/*
** Coms
*/

int		ft_start(t_cub *cub)
{
	cub->done = yes;
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (0);
	ft_check_screen(cub);
	if (cub->save == no)
	{
		if (ft_game_starter(cub) == 0)
			return (0);
	}
	else
	{
		cub->win.win_ptr = NULL;
		ft_init_image(cub);
		ft_generate_texture(cub);
		if (ft_raycast(cub) == 0)
		{
			printf("raycasting a un pb\n\n");
			return (0);
		}
		ft_save(cub);
	}
	return (1);
}

/*
** Coms
*/

int		ft_game_starter(t_cub *cub)
{
	if ((cub->win.win_ptr = mlx_new_window(cub->mlx_ptr,
		cub->win.r.x, cub->win.r.y, "test")) == NULL)
		return (0);
	ft_init_image(cub);
	ft_generate_texture(cub);
	if (ft_raycast(cub) == 0)
	{
		printf("raycasting a un pb\n\n");
		return (0);
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win.win_ptr,
							cub->img.img_ptr, 0, 0);
	ft_event(cub);
	mlx_loop(cub->mlx_ptr);
	return (1);
}
