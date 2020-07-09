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

size_t	ft_sprite_count(char **map)
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
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	cub->spr.coor = (t_vect *)malloc(sizeof(t_vect) * nbr);

	if (cub->spr.coor == NULL)
		return ;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '2')
			{
				cub->spr.coor[i].x = (double)x + 0.5;
				cub->spr.coor[i].y = (double)y + 0.5;
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

void	ft_sprite_dist(t_cub *cub)
{
	size_t	i;

	i = 0;
	cub->spr.rank = malloc(sizeof(size_t) * cub->spr.count);
	if (cub->spr.rank == NULL)
		return ;
	cub->spr.dist = malloc(sizeof(double) * cub->spr.count);
	if (cub->spr.dist == NULL)
		return ;
	while (i < cub->spr.count)
	{
		cub->spr.rank[i] = i;
		cub->spr.dist[i] = ((cub->player.pos.x - cub->spr.coor[i].x) *
					(cub->player.pos.x - cub->spr.coor[i].x) +
					(cub->player.pos.y - cub->spr.coor[i].y) *
					(cub->player.pos.y - cub->spr.coor[i].y));
		//printf("pos.x = %f, pos.y = %f\n sprite.x = %f, sprite.y = %f\n", cub->player.pos.x, cub->player.pos.y, cub->spr.coor[i].x, cub->spr.coor[i].y);
		//printf("distance calculée au rang %zu = %f\n", i, cub->spr.dist[i]);
		i++;
	}
}

/*
** Coms
*/

void	ft_sort_sprite(t_cub *cub)
{
	size_t		i;
	int		swap_rank;
	double	swap_dist;

	i = 0;
	while (i < cub->spr.count)
	{
		if (i + 1 < cub->spr.count &&
			cub->spr.dist[i] < cub->spr.dist[i + 1])
		{
			swap_rank = cub->spr.rank[i + 1];
			swap_dist = cub->spr.dist[i + 1];
			cub->spr.rank[i + 1] = cub->spr.rank[i];
			cub->spr.dist[i + 1] = cub->spr.dist[i];
			cub->spr.rank[i] = swap_rank;
			cub->spr.dist[i] = swap_dist;
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
	cub->spr.count = ft_sprite_count(cub->box_map);
	ft_sprite_stock(cub->spr.count, cub->box_map, cub);
	ft_sprite_dist(cub);
	ft_sort_sprite(cub);
	/*size_t i = 0;
	while (i < cub->spr.count)
	{
		printf("sprite n°%zu, coor = [%f,%f], dist = %f\n", i, cub->spr.coor[i].x, cub->spr.coor[i].y, cub->spr.dist[i]);
		i++;
	}*/

}
