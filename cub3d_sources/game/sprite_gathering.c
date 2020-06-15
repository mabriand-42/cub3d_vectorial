/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_gathering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

size_t		ft_sprite_count(char **map)
{
	int x;
	int y;
	int	sprite;

	y = 0;
	sprite = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
				sprite++;
			x++;
		}
		y++;
	}
	return (sprite);
}

/*
** Coms
*/

void	ft_sprite_stock(int nbr, char **map, t_cub *cub)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	cub->sprite.coor = (t_box *)malloc(sizeof(t_box) * nbr);
	if (cub->sprite.coor == NULL)
		return;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
			{
				cub->sprite.coor[i].x = x;
				cub->sprite.coor[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}	
}

/*
** Coms
*/

void		ft_sprite_dist(t_cub *cub)
{
	int i;
	int	side1;
	int	side2;

	i = 0;
	cub->sprite.rank = malloc(sizeof(size_t) * cub->sprite.count);
	if 	(cub->sprite.rank == NULL)
		return;
	cub->sprite.dist = malloc(sizeof(double) * cub->sprite.count);
	if 	(cub->sprite.dist == NULL)
		return;
	while (i < cub->sprite.count)
	{
		side1 = (cub->player.pos.x - cub->sprite.coor[i].x);
		side2 = (cub->player.pos.y - cub->sprite.coor[i].y);
		cub->sprite.rank[i] = i;
		cub->sprite.dist[i] = ft_hypothenuse(side1, side2);
		i++;
	}
}

/*
** Coms
*/

void	ft_sort_sprite(t_cub *cub)
{
	int		i;
	size_t	swap_rank;
	double	swap_dist;

	i = 0;
	while (i < cub->sprite.count)
	{
		if (i + 1 < cub->sprite.count && cub->sprite.dist[i] < cub->sprite.dist[i + 1])
		{
			swap_rank = cub->sprite.rank[i + 1];
			swap_dist = cub->sprite.dist[i + 1];
			cub->sprite.rank[i + 1] = cub->sprite.rank[i];
			cub->sprite.dist[i + 1] = cub->sprite.dist[i];
			cub->sprite.rank[i] = swap_rank;
			cub->sprite.dist[i] = swap_dist;
			i = -1;
		}
		i++;
	}
}

/*
** Coms
*/

void	ft_gather_sprite(t_cub *cub)
{
	cub->sprite.count = ft_sprite_count(cub->box_map);
	ft_sprite_stock(cub->sprite.count, cub->box_map, cub);
	ft_sprite_dist(cub);
	ft_sort_sprite(cub);
}
