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

void	ft_free_path_bis(t_data *c)
{
	if (c->t.path_no != NULL)
		free(c->t.path_no);
	if (c->t.path_so != NULL)
		free(c->t.path_so);
	if (c->t.path_we != NULL)
		free(c->t.path_we);
	if (c->t.path_ea != NULL)
		free(c->t.path_ea);
	if (c->t.path_s != NULL)
		free(c->t.path_s);
}

/*
** Coms
*/

void	ft_free_sprite(t_cub *cub)
{
	if (cub->spr.coor != NULL)
		free(cub->spr.coor);
	if (cub->spr.dist != NULL)
		free(cub->spr.dist);
	if (cub->spr.rank != NULL)
		free(cub->spr.rank);
}

/*
** Coms
*/

void	ft_free_img(t_cub *cub)
{
	if (cub->text.no_img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->text.no_img.img_ptr);
	if (cub->text.so_img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->text.so_img.img_ptr);
	if (cub->text.we_img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->text.we_img.img_ptr);
	if (cub->text.ea_img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->text.ea_img.img_ptr);
	if (cub->text.s_img.img_ptr != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->text.s_img.img_ptr);
}
