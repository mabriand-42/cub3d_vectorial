#include "../../cub3d_header/cub3d.h"

int     main(int argc, char **argv)
{
    t_pars pars;
    t_cub  cub;
	int ret_input = ft_check_input(&pars, &cub, argc, argv);
    if( ret_input == 0)
    {
        printf("ERROR : inputs!\n\n");
        return(0);
    }

	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\nS: %s\n", pars.data.t.path_no, pars.data.t.path_so, pars.data.t.path_we, pars.data.t.path_ea, pars.data.t.path_s);
	int	ret_player = ft_get_player_data(&cub);
	if (ret_player == 0)
	{
        printf("ERROR : player!\n\n");
        return(0);
    }
	ft_gather_sprite(&cub);
	printf("nbr sprite : %zu\n", cub.sprite.count);
	int ret_start = ft_start(&cub);
    if (ret_start == 0)
    {
        printf("ERROR : start!\n\n");
        return (0);
    }

    system("leaks a.out");
    return(0);
}