/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:27:28 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:39 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_callbacks(mlx_key_data_t keydata, t_game *game)
{
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS))
		game->isgameover = true;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE
		&& keydata.modifier == MLX_CONTROL)
		game->isgameover = true;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE
		&& keydata.modifier == MLX_CONTROL)
		game->isgameover = true;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_RELEASE
		&& keydata.modifier == MLX_CONTROL)
		game->isgameover = true;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_callbacks(keydata, game);
}

void	loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->isgameover)
	{
		free_game_struct(game);
		exit(EXIT_SUCCESS);
	}
}

void	xclose_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game_struct(game);
	exit(EXIT_SUCCESS);
}

void	mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &draw_callbacks, game);
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_close_hook(game->mlx, &xclose_hook, game);
}
