/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:39:14 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 21:23:37 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_mouse(double xp, double yp, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (xp >= 0 && xp <= WINDOW_WIDTH && yp >= 0 && yp <= WINDOW_HEIGHT)
	{
		if (xp > g->win->oldx)
		{
			g->player->angle += (SPEED_ROTATE + 0.1);
			if (g->player->angle >= 360)
				g->player->angle -= 360;
		}
		else
		{
			g->player->angle -= SPEED_ROTATE;
			if (g->player->angle <= 0)
				g->player->angle += 360;
		}
		g->win->oldx = xp;
	}
}

void	init_draw(t_game *g, int mode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < g->map->height)
	{
		i = 0;
		while (i < g->map->width)
		{
			if (g->map->map_array[j][i] == 'P' && mode)
			{
				mlx_put_pixel(g->img, g->win->pos_x = (i
						* g->win->shpsize) + (g->win->shpsize / 2),
					g->win->pos_y = (j * g->win->shpsize)
					+ (g->win->shpsize / 2), 0xFF0000FF);
			}
			i++;
		}
		j++;
	}
}

static void	draw_ceil_floor(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			if (j < WINDOW_HEIGHT / 2)
				mlx_put_pixel(game->img, i, j, game->assets->ceiling_hex);
			else
				mlx_put_pixel(game->img, i, j, game->assets->floor_hex);
			i++;
		}
		j++;
	}
}

void	angle_control(t_game *g)
{
	mlx_cursor_hook(g->mlx, move_mouse, (void *)g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
	{
		g->player->angle += SPEED_ROTATE;
		if (g->player->angle >= 360)
			g->player->angle -= 360;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
	{
		g->player->angle -= SPEED_ROTATE;
		if (g->player->angle <= 0)
			g->player->angle += 360;
	}
}

void	draw_callbacks(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	angle_control(game);
	player_movement_control(game);
	draw_ceil_floor(game);
	draw_view_angle(game);
}
