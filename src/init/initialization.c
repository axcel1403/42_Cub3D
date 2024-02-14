/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:06:13 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:15 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game **game)
{
	*game = calloc(1, sizeof(t_game));
	(*game)->assets = calloc(1, sizeof(t_assets));
	(*game)->map = calloc(1, sizeof(t_map));
	(*game)->player = calloc(1, sizeof(t_player));
	(*game)->win = calloc(1, sizeof(t_window));
	if (!*game || !(*game)->assets || !(*game)->map || !(*game)->player
		|| !(*game)->win)
	{
		error_exit(*game, "Malloc failed in init_game_struct\n");
	}
	init_map_assets_struct(*game);
}

void	init_map_assets_struct(t_game *g)
{
	g->assets->north_path = NULL;
	g->assets->south_path = NULL;
	g->assets->west_path = NULL;
	g->assets->east_path = NULL;
	g->map->map_array = NULL;
	g->map->file.filepath = NULL;
	return ;
}

void	init_mlx(t_game *g, int width, int height, char *title)
{
	mlx_t	*mlx;

	if (width < 0 || width > 5120 || height < 0 || height > 2880)
		error_exit(g, "Invalid resolution\n");
	mlx = mlx_init(width, height, title, 0);
	if (!mlx)
		error_exit(g, "Failed to initialize mlx\n");
	g->mlx = mlx;
	return ;
}
