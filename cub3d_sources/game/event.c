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

int		ft_close_pgm_bis(t_cub *cub)
{
	ft_free_img(cub);
	if (cub->img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	ft_free_mlx_ptr(cub->mlx_ptr);
	ft_free_path(cub);
	ft_free_sprite(cub);
	ft_free_tab(cub->box_map);
	ft_printf("Error : Texture\n");
	exit(EXIT_SUCCESS);
	return (0);
}


/*
** Coms
*/

int		ft_close_pgm(t_cub *cub)
{
	ft_free_img(cub);
	if (cub->img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	mlx_clear_window(cub->mlx_ptr, cub->win.win_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->win.win_ptr);
	ft_free_mlx_ptr(cub->mlx_ptr);
	ft_free_path(cub);
	ft_free_sprite(cub);
	ft_free_tab(cub->box_map);
	ft_printf("BYE !");
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** Coms
*/

int		ft_close_pgm_ter(t_cub *cub)
{
	return(ft_press_mana(K_ESC, cub));
}

/*
** Coms
*/

int		ft_press_mana(int keycode, t_cub *cub)
{
	if (keycode == K_ESC)
		return (ft_close_pgm(cub));
	if (keycode == K_W || keycode == K_A)
		ft_move_wa(keycode, cub);
	if (keycode == K_S || keycode == K_D)
		ft_move_sd(keycode, cub);
	if (keycode == K_AR_R || keycode == K_AR_L)
		ft_rotate(keycode, cub);
	ft_raycast(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win.win_ptr,
							cub->img.img_ptr, 0, 0);
	return (0);
}

/*
** Coms
*/

void	ft_event(t_cub *cub)
{
	mlx_hook(cub->win.win_ptr, 2, 1L << 0, ft_press_mana, cub);
	mlx_hook(cub->win.win_ptr, 17, 1L << 17, ft_close_pgm_ter, cub);
}
