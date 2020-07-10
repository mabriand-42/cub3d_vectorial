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
# include "../libft/libft_header/libft.h"
# include "cub3d_parse_struct.h"
# include "cub3d_game_struct.h"
# include "cub3d_macro.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*
** -------------------------------------------------------------------PARSING---
*/

/*
** Basic
*/
void			ft_skip_spaces(char *str, size_t *pos);
int				ft_find_char(char c, char *str);
int				ft_isvalidchar(char c);
int				ft_iscardinal(char c);
char			*ft_join_bis(char *s1, char *s2);
char			*ft_str_null_bis(char *s1, char *s2);
int				gnl(int fd, char **line);
int				ft_is_empty_string(char *str);
/*
** Config
*/
int				ft_check_id(char c1, char c2);
int				ft_find_id(char *line, char *id, size_t *pos);
int				ft_id_s(size_t *pos, char *line, char *id);
int				ft_id_rfc(size_t *pos, char *line, char *id);
int				ft_id_nwe(size_t *pos, char *line, char *id);
int				ft_check_config(t_check check);
int				ft_update_player(char c, t_map *m);
/*
** Init
*/
void			ft_init_config(t_data *data);
void			ft_init_check(t_check *check);
void			ft_init_map(t_map *map);
/*
** Resolution
*/
unsigned int	ft_axis(char *line, size_t *pos);
int				ft_r(char *line, size_t *pos, t_reso *reso, t_bool *check);
int				ft_xy(char *l, size_t *p, unsigned int *x, unsigned int *y);
/*
** Color
*/
int				ft_color(char *line, size_t *pos);
int				ft_rgb(char *line, size_t *pos, t_color *c);
int				ft_cf(char *line, size_t *pos, t_color *color, t_bool *check);
/*
** Texture
*/
int				ft_path(char *line, size_t *pos, size_t save_pos, char **path);
int				ft_text(char *line, size_t *pos, char **path, t_bool *check);
/*
** Map
*/
int				ft_closed_map(char *str1, size_t *pos);
int				ft_cmp_char(char c1, char c2, t_map *map);
int				ft_cmp_prev_next(char c1, char *line, size_t index);
int				ft_duo_line(char *prev, char *next, t_map *map);
int				ft_duo_line_cp(char *prev, char *next, size_t *i, size_t *j);
void			ft_create_map(t_map *map, char *next, int *ret);
int				ft_lines(char *line, char *next, t_map *map, t_data *data);
int				ft_check_end(char *str, size_t *pos);
int				ft_index_zero(char c1, char *line);
int				ft_is_map_line(char *str);
/*
** Parsing
*/
int				ft_elem_parsing(char *line, t_data *data);
int				ft_orient_gnl(int ret_gnl, t_map *map, t_data *data, t_duo duo);
int				ft_get_config(char *id, char *line, size_t *pos, t_data *c);
int				ft_zero_gnl(t_map *m, char *str, t_duo duo, t_data *c);
int				ft_past_gnl(int	fd, t_pars *ptr);
int				ft_nz_gnl(t_map *m, char *str, t_duo duo, t_data *c);

/*
** ---------------------------------------------------------------RAY CASINTG---
*/

/*
** Utils
*/
int				ft_create_rgb(int r, int g, int b);
double			ft_deg_to_rad(double degree);
double			ft_hypothenuse(int side1, int side2);
void			ft_init_image(t_cub *cub);
/*
** Player
*/
void			ft_init_player(t_player *player);
int				ft_get_player_pos(t_cub *cub);
int				ft_get_player_data(t_cub *cub);
void			ft_get_orientation(t_card card, t_cub *cub);
void			ft_get_plane(t_cub *cub);
/*
** Wall search
*/
void			ft_side_x(t_cub *cub);
void			ft_side_y(t_cub *cub);
void			ft_wall_search(t_cub *cub);
/*
** Raycasting
*/
void			ft_init_cast(t_cast *cast);
int				ft_raycast(t_cub *cub);
void			ft_get_sides(t_cub *cub);
/*
** Draw
*/
void			ft_init_draw(t_draw *draw);
void			ft_draw(t_cub *cub, int i);
void			ft_get_wall(t_cub *cub, double *dst, int index);
void			ft_get_slice(t_cub *cub, double *dst, int index);
void			ft_we_wall(t_cub *cub);
void			ft_ns_wall(t_cub *cub);
void			ft_my_mlx_pixel_put(t_image *image, int x, int y, int color);
/*
** Hook
*/
int				ft_close_pgm(t_cub *cub);
int				ft_close_pgm_cross(t_cub *cub);
int				ft_press_mana(int keycode, t_cub *cub);
void			ft_move_ws(int keycode, t_cub *cub);
void			ft_move_ad(int keycode, t_cub *cub);
void			ft_event(t_cub *cub);
void			ft_rotate(int keycode, t_cub *cub);
void			ft_rotate_right(t_cub *cub);
void			ft_rotate_left(t_cub *cub);
int				ft_iswalkable(char c);
int				ft_key_release(int keycode, t_move *move);
int				ft_key_push(int keycode, t_move *move);
void			ft_check_key_on(t_cub *cub);
/*
** Texture
*/
t_image			*ft_choose_text(t_cub *cub);
void			ft_mapping(t_cub *cub, t_image texture, int i, int *j);
void			ft_generate_texture(t_cub *cub);
/*
** Sprite
*/
void			ft_print_sprite(t_cub *cub, double *dst);
void			ft_print_s_color(t_cub *cub, int x, int y);
void			ft_sort_sprite(t_cub *cub);
void			ft_sprite_dist(t_cub *cub);
void			ft_sprite_stock(int nbr, char **map, t_cub *cub);
size_t			ft_sprite_count(char **map);
void			ft_gather_sprite(t_cub *cub);
void			ft_transform_sprite(t_cub *cub, int i);
void			ft_get_sprite(t_cub *cub, double *dst);
void			ft_s_color(t_cub *cub, double *dst, t_box s, int d, t_box size);
void			ft_loop(t_cub *cub, t_box sprite, double *dst);

/*
** -------------------------------------------------------------------PROGRAM---
*/

/*
** Argument
*/
int				ft_file_type(const char *type, const char *fd_path);
int				ft_check_arg(int ac, char **av, t_pars *ptr);
void			ft_equivalent_data(t_pars *pars_data, t_cub *cub);
int				ft_check_input(t_pars *pars, t_cub *cub, int ac, char **av);
void			ft_save(t_cub *cub);
/*
** Run
*/
void			ft_init_pars_struct(t_pars *ptr);
int				ft_parse_fd(char *fd_path, t_pars *cub);
int				ft_open(char *fd_path, int *fd, t_duo *duo);
int				ft_start(t_cub *cub);
void			ft_init_cub(t_cub *cub);
int				ft_game_starter(t_cub *cub);
/*
** Free
*/
void			ft_free_path(t_cub *cub);
void			ft_free_mlx_ptr(void *mlx_ptr);
void			ft_free_sprite(t_cub *cub);
void			ft_free_tab(char **tab);
void			ft_free_img(t_cub *cub);
void			ft_free_path_bis(t_data *c);

#endif
