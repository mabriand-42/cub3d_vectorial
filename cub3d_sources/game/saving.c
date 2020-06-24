/*int	ft_start(t_cub *cub)
{
	int ret_ray;

	cub->done = yes;
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((cub->win.win_ptr = mlx_new_window(cub->mlx_ptr,
		cub->win.r.x, cub->win.r.y, "test")) == NULL)
		return (0);
	ft_init_image(cub);
	ft_generate_texture(cub);
	ret_ray = ft_raycast(cub);
    if (ret_ray == 0)
    {
        printf("raycasting a un pb\n\n");
        return (0);
    }
	mlx_put_image_to_window(cub->mlx_ptr, cub->win.win_ptr, cub->img.img_ptr, 0, 0);
	ft_event(cub);
	mlx_loop(cub->mlx_ptr);
	return (1);
}*/