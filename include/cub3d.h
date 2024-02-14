/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:44:24 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 21:56:23 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "colors.h"
# include "libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// utils/file_utils.c
int			cub_file_open(t_game *g);
bool		file_exists(char *filename);
bool		is_cub_file(char *filename);
void		cub_config_color2(char **elems, t_game *g, int *color);

// init/initialization.c
void		init_game_struct(t_game **game);
void		init_map_assets_struct(t_game *g);
void		init_mlx(t_game *g, int width, int height, char *title);

// init/initialization_2.c
void		init_textures(t_game *g);
void		init_player(t_game *g);

// error/error_management.c
void		free_game_struct(t_game *game);
void		error_exit(t_game *g, char *errmsg);
void		parse_file(char *filename);

// parser/parsing.c
int			cub_main_parser(t_game *g);

// parser/parsing_color.c
bool		cub_config_color(char **elems, t_game *g);
t_rgb		cub_get_color(int *arr);

// parser/parsing_map.c
int			cub_parse_map(t_game *g);

// parser/parsing_map_2.c
bool		is_valid_map_format(t_game *g);
bool		is_player_on_edge(t_game *g);
uint32_t	cub_get_hex_color(t_rgb rgb);

// parser/parsing_utils.c
int			strreps(char *line, char c);
char		*remove_newline(char *line);
bool		is_singleplayer(t_game *g);
bool		is_valid_map_char(char c);
bool		is_valid_but_not_for_wall(char c);

// mlx/callbacks.c
void		keyhook(mlx_key_data_t keydata, void *param);
void		loop_hook(void *param);
void		xclose_hook(void *param);
void		mlx_hooks(t_game *game);

// render/rendering.c
void		draw_callbacks(void *param);
void		draw_map(t_game *g, int mode);
void		init_draw(t_game *g, int mode);

// render/raycasting.c
void		draw_view_angle(t_game *g);
void		ray_casting(t_game *g, float ray_angle, int id_ray,
				mlx_image_t *img);
void		call_raycasting(t_game *g, float ray_angle, int id_ray);

// render/raycastupdownleftright.c
void		check_raycast_down(t_game *g, float ray_angle);
void		check_raycast_up(t_game *g, float ray_angle);
void		check_raycast_right(t_game *g, float ray_angle);
void		check_raycast_left(t_game *g, float ray_angle);

// render/raycastutils.c
void		calcul_distance(t_game *g);
void		check_ray_draw(t_game *g, float ray_angle, int id_ray);
uint32_t	get_texel(mlx_image_t *img, int x, int y);

// IHATEMATHS/IHATEMATHS.c
float		deg_to_rad(float deg);
float		distance_between_points(float x1, float y1, float x2, float y2);

// movement/movement.c
void		player_movement_control(t_game *g);

// movement/collision.c
int			check_collision(t_game *g);

#endif