/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:33:01 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:00 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_image_t	*load_and_convert_texture(t_game *g, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		error_exit(g, "Wasn't able to initialize the textures\n");
	image = mlx_texture_to_image(g->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	init_textures(t_game *g)
{
	g->assets->north_texture = load_and_convert_texture(g,
			g->assets->north_path);
	g->assets->south_texture = load_and_convert_texture(g,
			g->assets->south_path);
	g->assets->east_texture = load_and_convert_texture(g, g->assets->east_path);
	g->assets->west_texture = load_and_convert_texture(g, g->assets->west_path);
}

void	init_player(t_game *g)
{
	if (g->player->playerdirection == 'N')
		g->player->angle = 270;
	else if (g->player->playerdirection == 'S')
		g->player->angle = 90;
	else if (g->player->playerdirection == 'W')
		g->player->angle = 180;
	else
		g->player->angle = 0;
	g->win->raycnt = WINDOW_WIDTH;
	if (WINDOW_WIDTH / 9 > WINDOW_HEIGHT / 9)
		g->map->size_map = WINDOW_WIDTH / 9;
	else
		g->map->size_map = WINDOW_HEIGHT / 9;
	if (g->map->height > g->map->width)
		g->win->shpsize = g->map->size_map / g->map->height;
	else
		g->win->shpsize = g->map->size_map / g->map->width;
	g->win->oldx = WINDOW_WIDTH;
}
