/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Vérifie que le format du fichier donné grâce à son
** chemin correspond à celui attendu.
** =========
** #1 : un format de fichier.
** #2 : le chemin vers le fichier donné.
** =========
** Retourne 1 si le format correspond, 0 sinon.
*/

int		ft_file_type(const char *type, const char *fd_path)
{
	size_t	i;
	size_t	j;

	if (type[0] != '.' || (type == NULL || fd_path == NULL))
		return (0);
	i = ft_strlen(type);
	j = ft_strlen(fd_path);
	if (i >= j)
		return (0);
	while (i > 0)
	{
		if (type[i] != fd_path[j])
			return (0);
		i--;
		j--;
	}
	if (type[i] == fd_path[j])
		return (1);
	return (0);
}

/*
** Vérifie que les arguments donnés à main()
** sont valides et actualise le statut du champ
** save du t_cub si besoin.
** =========
** #1 : (= argc)
** #2 : (= argv)
** #3 : un pointeur sur un t_cub.
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_check_arg(int ac, char **av, t_pars *ptr)
{
	if (ac < 2 || ac > 3 || ft_file_type(".cub", av[1]) == 0)
		return (0);
	if (ac == 3)
	{
		if (ft_strcmp("--save", av[2]) != 0)
			return (0);
		ptr->save = yes;
	}
	return (1);
}

/*
** Coms
*/

void	ft_equivalent_data(t_pars *pars, t_cub *cub)
{
	cub->win.r = pars->data.r;
	cub->img.r = pars->data.r;
	cub->draw.c_rgb = ft_create_rgb(pars->data.c.r,
					pars->data.c.g, pars->data.c.b);
	cub->draw.f_rgb = ft_create_rgb(pars->data.f.r,
					pars->data.f.g, pars->data.f.b);
	cub->box_map = pars->map.two_d;
	ft_get_orientation(pars->map.card, cub);
	cub->text.no_img.path = pars->data.t.path_no;
	cub->text.so_img.path = pars->data.t.path_so;
	cub->text.we_img.path = pars->data.t.path_we;
	cub->text.ea_img.path = pars->data.t.path_ea;
	cub->text.s_img.path = pars->data.t.path_s;
	cub->save = pars->save;
}

/*
** Coms
*/

int		ft_check_input(t_pars *pars, t_cub *cub, int ac, char **av)
{
	int	ret_check_arg;
	int	ret_parse;

	ft_init_pars_struct(pars);
	ft_init_cub(cub);
	ret_check_arg = ft_check_arg(ac, av, pars);
	if (ret_check_arg == 0)
	{
		ft_printf("Please check arguments! \n");
		return (0);
	}
	ret_parse = ft_parse_fd(av[1], pars);
	ft_equivalent_data(pars, cub);
	if (ret_parse == 0)
	{
		ft_free_tab(cub->box_map);
		ft_printf("Your file .cub seems invalid! \n");
		return (0);
	}
	return (1);
}
