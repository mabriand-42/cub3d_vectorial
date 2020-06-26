#include "../../cub3d_header/cub3d.h"

int		ft_is_empty_string(char *str)
{
	int i;

	i = 0;
	ft_skip_spaces(str, &i);
	if (str[i] = '\0')
		return (1);
	else
		return (0);
}

void	ft_check_end(char *line, char *prev, t_map *map)
{
	if (map->last == no && ft_is_empty_string(line) == 1)
	{
		map->last == yes;

	}
	else if (map->last == yes && ft_is_empty_string(line) == 1)
	

}

void	ft_check_