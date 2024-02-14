/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:36 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 18:59:52 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_collision_ad(t_game *g, int *x, int *y)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_D) && !mlx_is_key_down(g->mlx,
			MLX_KEY_W) && !mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		*x = g->win->pos_x - cos(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP_V;
		*y = g->win->pos_y + sin(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP_V;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A) && !mlx_is_key_down(g->mlx,
			MLX_KEY_W) && !mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		*x = g->win->pos_x + cos(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP_V;
		*y = g->win->pos_y - sin(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP_V;
	}
}

static void	check_collision_ws(t_game *g, int *x, int *y)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
	{
		*x = g->win->pos_x + (cos(deg_to_rad(g->player->angle))
				* MOVE_STEP_V);
		*y = g->win->pos_y + (sin(deg_to_rad(g->player->angle))
				* MOVE_STEP_V);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
	{
		*x = g->win->pos_x - (cos(deg_to_rad(g->player->angle))
				* MOVE_STEP_V);
		*y = g->win->pos_y - (sin(deg_to_rad(g->player->angle))
				* MOVE_STEP_V);
	}
}

int	check_collision(t_game *g)
{
	int	x;
	int	y;

	check_collision_ws(g, &x, &y);
	check_collision_ad(g, &x, &y);
	if (g->map->map_array[(int)(y / g->win->shpsize)][(int)(x
			/ g->win->shpsize)] == '1' || (g->map->map_array[(int)(y
				/ g->win->shpsize)][(int)(g->win->pos_x
				/ g->win->shpsize)] == '1'
			&& g->map->map_array[(int)(g->win->pos_y
				/ g->win->shpsize)][(int)(x
				/ g->win->shpsize)] == '1'))
		return (0);
	return (1);
}
