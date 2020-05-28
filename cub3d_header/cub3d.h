/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft_header/libft.h"
# include "cub3d_parse_struct.h"
# include "cub3d_game_struct.h"
# include "cub3d_macro.h"


/*
** -------------------------------------------------------------------PARSING---
*/

/*
** Basic
*/
void	ft_skip_spaces(char *str, size_t *pos);
int		ft_find_char(char c, char *str);
int		ft_isvalidchar(char c);
int		ft_iscardinal(char c);
char	*ft_join_bis(char *s1, char *s2);
char	*ft_str_null_bis(char *s1, char *s2);
int		gnl(int fd, char **line);
/*
** Config
*/
int		ft_check_id(char c1, char c2);
int		ft_find_id(char *line, char *id, size_t *pos);
int		ft_id_s(size_t *pos, char *line, char *id);
int		ft_id_rfc(size_t *pos, char *line, char *id);
int		ft_id_nwe(size_t *pos, char *line, char *id);
int		ft_check_config(t_check check);
int		ft_update_player(char c, t_map *m);
/*
** Init
*/
void	ft_init_config(t_data *data);
void	ft_init_check(t_check *check);
void	ft_init_map(t_map *map);
/*
** Resolution
*/
size_t	ft_axis(char *line, size_t *pos);
int		ft_r(char *line, size_t *pos, t_reso *resolution, t_bool *check);
int		ft_xy(char *line, size_t *pos, t_reso *r);
/*
** Color
*/
int		ft_color(char *line, size_t *pos);
int		ft_rgb(char *line, size_t *pos, t_color *c);
int		ft_cf(char *line, size_t *pos, t_color *color, t_bool *check);
/*
** Texture
*/
int		ft_path(char *line, size_t *pos, size_t save_pos, char **path);
int		ft_text(char *line, size_t *pos, char **path, t_bool *check);
/*
** Map
*/
int		ft_closed_map(char *line, size_t *pos);
int		ft_cmp_char(char c1, char c2, t_map *map);
int		ft_cmp_prev_next(char c1, char *line, size_t index);
int		ft_duo_line(char *prev, char *next, t_map *map);
int		ft_duo_line_cp(char *prev, char *next, size_t *ptr_i, size_t *ptr_j);
void	ft_create_map(t_map *map, char *next, int *ret);
int		ft_lines(char *line, char *next, t_map *map, t_data *data);
/*
** Parsing
*/
int		ft_elem_parsing(char *line, t_data *data);
int		ft_orient_gnl(int ret_gnl, t_map *map, t_data *data, t_duo duo);
int		ft_get_config(char *id, char *line, size_t *pos, t_data *c);

/*
** ---------------------------------------------------------------RAY CASINTG---
*/

/*
** Utils
*/
int		ft_create_rgb(int r, int g, int b);
double	ft_deg_to_rad(double degree);
/*
** Player
*/
void	ft_init_player(t_player *player);
int		ft_get_player_pos(t_cub *cub);
int		ft_get_player_data(t_cub *cub);
void	ft_get_orientation(t_card card, t_cub *cub);
void	ft_get_plane(t_cub *cub);
/*
** Wall search
*/
void	ft_side_x(t_cub *cub);
void	ft_side_y(t_cub *cub);
void	ft_wall_search(t_cub *cub);
/*
** Raycasting
*/
void	ft_init_cast(t_cast *cast);
int		ft_raycast(t_cub *cub);
void	ft_get_sides(t_cub *cub);

/*
** Draw
*/
void	ft_init_draw(t_draw *draw);
void	ft_draw(t_cub *cub, int i);
void	ft_get_wall(t_cub *cub);
void	ft_get_slice(t_cub *cub);
void	ft_we_wall(t_cub *cub);
void	ft_ns_wall(t_cub *cub);
/*
** Hook
*/
void	ft_close_pgm(t_cub *cub);
int		ft_press_mana(int keycode, t_cub *cub);
void	ft_move_wa(int keycode, t_cub *cub);
void	ft_move_sd(int keycode, t_cub *cub);
void	ft_event(t_cub *cub);
void	ft_rotate(int keycode, t_cub *cub);
void	ft_rotate_right(t_cub *cub);
void	ft_rotate_left(t_cub *cub);
int		ft_iswalkable(char c);





t_image	*ft_choose_text(t_cub *cub);
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	ft_mapping(t_cub *cub, t_image texture, int  *i, int *j);
void	ft_init_image(t_cub *cub);
/*
** -------------------------------------------------------------------PROGRAM---
*/

/*
** Argument
*/
int		ft_file_type(const char *type, const char *fd_path);
int    	ft_check_arg(int ac, char **av, t_pars  *ptr);
void	ft_equivalent_data(t_pars *pars_data, t_cub *cub);
int		ft_check_input(t_pars *pars, t_cub *cub, int ac, char **av);
/*
** Init
*/

/*
** Run
*/
void	ft_init_pars_struct(t_pars *ptr);
int		ft_parse_fd(char *fd_path, t_pars *cub);
int		ft_start(t_cub *cub);
void	ft_init_cub(t_cub *cub);






#endif