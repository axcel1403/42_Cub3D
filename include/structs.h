/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:19:25 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:39 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>

# define WINDOW_TITLE "Cub3D"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define SPEED_ROTATE 2
# define MOVE_STEP 1
# define MOVE_STEP_V 3
# define VIEW_ANGLE 60
# define ALPHA_CHANNEL 255

typedef struct s_mapfile
{
	char			*filepath;
	int				fd;
}					t_mapfile;

typedef struct s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef struct s_map
{
	t_mapfile		file;
	char			**map_array;
	int				width;
	int				height;
	int				spawnx;
	int				spawny;
	int				size_map;
}					t_map;

typedef struct s_assets
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	mlx_image_t		*north_texture;
	mlx_image_t		*south_texture;
	mlx_image_t		*west_texture;
	mlx_image_t		*east_texture;
	t_rgb			floor_rgb;
	uint32_t		floor_hex;
	t_rgb			ceiling_rgb;
	uint32_t		ceiling_hex;
}					t_assets;

# define FLAG_ISMAP 0b00000001
# define FLAG_HASNORTH 0b00000010
# define FLAG_HASSOUTH 0b00000100
# define FLAG_HASWEST 0b00001000
# define FLAG_HASEAST 0b00010000
# define FLAG_HASFLOOR 0b00100000
# define FLAG_HASCEILING 0b01000000
# define FLAG_MAPCLOSED 0b10000000

typedef struct s_player
{
	char	playerdirection;
	float	angle;
}					t_player;

typedef struct s_window
{
	float			raycnt;
	int				shpsize;
	double			oldx;
	float			hor_inter_x;
	float			hor_inter_y;
	float			nxt_hor_inter_x;
	float			nxt_hor_inter_y;
	float			pos_x;
	float			pos_y;
	float			hor_step_x;
	float			hor_step_y;
	float			hor_dist;
	float			vert_dist;
	float			total_dist;
	float			vert_inter_x;
	float			vert_inter_y;
	float			nxt_vert_inter_x;
	float			nxt_vert_inter_y;
	float			vert_step_x;
	float			vert_step_y;
	float			current_texture;
	int				texture_offset_x;
	float			texture_offset_y;
	int				wallstart_pos;

}					t_window;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			*map;
	t_window		*win;
	unsigned int	mapflags;
	t_assets		*assets;
	t_player		*player;

	bool			isgameover;
}					t_game;

#endif