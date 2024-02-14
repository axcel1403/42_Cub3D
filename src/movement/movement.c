/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:28:43 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 18:59:52 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_movement_control_2(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W) && check_collision(g))
	{
		g->win->pos_x = g->win->pos_x + (cos(deg_to_rad(g->player->angle))
				* MOVE_STEP);
		g->win->pos_y = g->win->pos_y + (sin(deg_to_rad(g->player->angle))
				* MOVE_STEP);
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S) && check_collision(g))
	{
		g->win->pos_x = g->win->pos_x - (cos(deg_to_rad(g->player->angle))
				* MOVE_STEP);
		g->win->pos_y = g->win->pos_y - (sin(deg_to_rad(g->player->angle))
				* MOVE_STEP);
	}
}

void	player_movement_control(t_game *g)
{
	player_movement_control_2(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D) && check_collision(g))
	{
		g->win->pos_x = g->win->pos_x - cos(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP;
		g->win->pos_y = g->win->pos_y + sin(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP;
	}
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A) && check_collision(g))
	{
		g->win->pos_x = g->win->pos_x + cos(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP;
		g->win->pos_y = g->win->pos_y - sin(deg_to_rad(90)
				- deg_to_rad(g->player->angle)) * MOVE_STEP;
	}
}
