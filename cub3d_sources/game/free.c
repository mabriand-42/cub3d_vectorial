/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_header/cub3d.h"

/*
** Coms
*/

void	ft_free_all(t_cub *cub)
{
	ft_free_path(cub);
	ft_free_sprite(cub);
	ft_free_tab(cub->box_map);
}

void	ft_free_tab(char **tab)
{
	size_t i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

/*
** Coms
*/

void	ft_free_path(t_cub *cub)
{
	if (cub->text.no_img.path != NULL)
		free(cub->text.no_img.path);
	if (cub->text.so_img.path != NULL)
		free(cub->text.so_img.path);
	if (cub->text.we_img.path != NULL)
		free(cub->text.we_img.path);
	if (cub->text.ea_img.path != NULL)
		free(cub->text.ea_img.path);
	if (cub->text.s_img.path != NULL)
		free(cub->text.s_img.path);
}

/*
** Coms
*/

void	ft_free_sprite(t_cub *cub)
{
	free(cub->spr.coor);
	free(cub->spr.dist);
	free(cub->spr.rank);
}

/*
** Coms
*/

void	ft_free_mlx_ptr(void *mlx_ptr)
{
	struct s_xvar	*xvar;

	xvar = mlx_ptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}

/*
** Coms
*/

void	ft_free_img(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->text.no_img.img_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->text.so_img.img_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->text.we_img.img_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->text.ea_img.img_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->text.s_img.img_ptr);
}
