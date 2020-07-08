/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
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

int		ft_close_pgm(t_cub *cub)
{
	ft_free_img(cub);
	if (cub->img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	if (cub->img2.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img2.img_ptr);
	if (cub->start == yes)
	{
		mlx_clear_window(cub->mlx_ptr, cub->win.win_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win.win_ptr);
	}
	else
		ft_printf("Error\nPlease check the path of your textures! \n");
	if (cub->end == yes && cub->cross == no)
		ft_free_mlx_ptr(cub->mlx_ptr);
	ft_free_path(cub);
	ft_free_sprite(cub);
	ft_free_tab(cub->box_map);
	if (cub->start == yes && cub->end == yes && cub->cross == yes)
		ft_printf("BYE !\n\n");
	if (cub->start == yes && cub->end == no && cub->cross == yes)
		ft_printf("BYE !\n\n");	
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** Coms
*/

int		ft_press_mana(int keycode, t_cub *cub)
{
	ft_key_push(keycode, &cub->move);
	if (keycode == K_ESC)
	{
		cub->end = yes;
		return (ft_close_pgm(cub));
	}
	return (0);
}

/*
** Coms
*/

void		ft_check_key_on(t_cub *cub)
{
	if (cub->move.w_on == 1)
		ft_move_ws(K_W, cub);
	if (cub->move.s_on == 1)
		ft_move_ws(K_S, cub);
	if (cub->move.a_on == 1)
		ft_move_ad(K_A, cub);
	if (cub->move.d_on == 1)
		ft_move_ad(K_D, cub);
	if (cub->move.ar_r_on == 1)
		ft_rotate(K_AR_R, cub);
	if (cub->move.ar_l_on == 1)
		ft_rotate(K_AR_L, cub);
}

/*
** Coms
*/

int			ft_refresh(t_cub *cub)
{
	ft_check_key_on(cub);
	ft_raycast(cub);
	if (cub->bool_img == 0)
	{
		mlx_put_image_to_window(cub->mlx_ptr, cub->win.win_ptr,
							cub->img.img_ptr, 0, 0);
		cub->bool_img = 1;
	}
	else if (cub->bool_img == 1)
	{
		mlx_put_image_to_window(cub->mlx_ptr, cub->win.win_ptr,
							cub->img2.img_ptr, 0, 0);
		cub->bool_img = 0;
	}
	return (0);
}

/*
** Coms
*/

void	ft_event(t_cub *cub)
{
	cub->cross = yes;
	mlx_hook(cub->win.win_ptr, 3, 1L << 1, ft_key_release, &cub->move);
	mlx_hook(cub->win.win_ptr, 2, 1L << 0, ft_press_mana, cub);
	mlx_hook(cub->win.win_ptr, 17, 1L << 17, ft_close_pgm, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_refresh, cub);
}
