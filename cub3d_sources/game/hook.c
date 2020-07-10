/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
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

int			ft_key_release(int keycode, t_move *move)
{
	if (keycode == K_W)
		move->w_on = 0;
	if (keycode == K_S)
		move->s_on = 0;
	if (keycode == K_A)
		move->a_on = 0;
	if (keycode == K_D)
		move->d_on = 0;
	if (keycode == K_AR_R)
		move->ar_r_on = 0;
	if (keycode == K_AR_L)
		move->ar_l_on = 0;
	return (0);
}

int			ft_key_push(int keycode, t_move *move)
{
	if (keycode == K_W)
		move->w_on = 1;
	if (keycode == K_S)
		move->s_on = 1;
	if (keycode == K_A)
		move->a_on = 1;
	if (keycode == K_D)
		move->d_on = 1;
	if (keycode == K_AR_R)
		move->ar_r_on = 1;
	if (keycode == K_AR_L)
		move->ar_l_on = 1;
	return (0);
}
