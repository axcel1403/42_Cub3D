/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:54:12 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 21:19:38 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_array(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map_array)
	{
		while (game->map->map_array[i])
		{
			free(game->map->map_array[i]);
			game->map->map_array[i] = NULL;
			i++;
		}
		free(game->map->map_array);
		game->map->map_array = NULL;
	}
}

static void	free_and_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_game_struct(t_game *game)
{
	if (game)
	{
		if (game->assets)
		{
			free_and_null(game->assets->north_path);
			free_and_null(game->assets->south_path);
			free_and_null(game->assets->west_path);
			free_and_null(game->assets->east_path);
			free(game->assets);
		}
		if (game->map)
		{
			if (game->map->map_array)
				free_map_array(game);
			free_and_null(game->map);
		}
		if (game->player)
			free_and_null(game->player);
		if (game->win)
			free_and_null(game->win);
		if (game->mlx)
			mlx_terminate(game->mlx);
		close(game->map->file.fd);
		free(game);
	}
}

void	error_exit(t_game *g, char *errmsg)
{
	ft_putstr_fd(HERE RED "ERROR\n" RESET, STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	free_game_struct(g);
	exit(EXIT_FAILURE);
}
