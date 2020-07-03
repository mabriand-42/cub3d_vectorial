/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_header/cub3d.h"

int	main(int argc, char **argv)
{
	t_pars	pars;
	t_cub	cub;

	if (ft_check_input(&pars, &cub, argc, argv) == 0)
	{	
		return (0);
	}
	if (ft_get_player_data(&cub) == 0)
	{
		ft_printf("ERROR : player!\n\n");
		return (0);
	}
	ft_gather_sprite(&cub);
	if (ft_start(&cub) == 0)
	{
		ft_printf("ERROR : start!\n\n");
		return (0);
	}
	return (0);
}
