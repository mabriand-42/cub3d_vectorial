/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

int		ft_create_rgb(int r, int g, int b)
{
	return ((256 * 256 * r) + (256 * g) + b);
}

/*
** Coms
*/

double	ft_deg_to_rad(double degree)
{
	double	radian;

	radian = (degree / 2) * (PI / 180);
	return (radian);
}

/*
** Coms
*/

int		ft_iswalkable(char c)
{
	if (c == '0' || ft_iscardinal(c) == 1)
		return (1);
	return (0);
}

/*
** Coms
*/

double	ft_hypothenuse(int side1, int side2)
{
	double	side3;

	side3 = (side1 * side1) + (side2 * side2);
	side3 = sqrt(side3);
	return (side3);
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
