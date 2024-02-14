/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastupdownleftright.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:17:23 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 18:59:52 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_raycast_left(t_game *g, float ray_angle)
{
	g->win->vert_inter_x = floor((g->win->pos_x / g->win->shpsize))
		* g->win->shpsize;
	g->win->vert_inter_y = g->win->pos_y - ((g->win->pos_x
				- g->win->vert_inter_x) * tan(deg_to_rad(ray_angle)));
	g->win->nxt_vert_inter_x = g->win->vert_inter_x - g->win->shpsize;
	g->win->nxt_vert_inter_y = g->win->vert_inter_y
		- ((g->win->vert_inter_x - g->win->nxt_vert_inter_x)
			* tan(deg_to_rad(ray_angle)));
	g->win->vert_step_x = g->win->shpsize;
	g->win->vert_step_y = g->win->nxt_vert_inter_y
		- g->win->vert_inter_y;
	while (((int)((g->win->vert_inter_x - 1)
			/ g->win->shpsize)) < g->map->width
		&& ((int)(g->win->vert_inter_y
			/ g->win->shpsize)) < g->map->height
		&& g->win->vert_inter_x >= 0 && g->win->vert_inter_y >= 0
		&& g->map->map_array[(int)(g->win->vert_inter_y
			/ g->win->shpsize)][(int)((g->win->vert_inter_x - 1)
			/ g->win->shpsize)] != '1')
	{
		g->win->vert_inter_x -= g->win->vert_step_x;
		g->win->vert_inter_y += g->win->vert_step_y;
	}
}

void	check_raycast_right(t_game *g, float ray_angle)
{
	g->win->vert_inter_x = floor((g->win->pos_x / g->win->shpsize) + 1)
		* g->win->shpsize;
	g->win->vert_inter_y = g->win->pos_y - ((g->win->pos_x
				- g->win->vert_inter_x) * tan(deg_to_rad(ray_angle)));
	g->win->nxt_vert_inter_x = g->win->vert_inter_x + g->win->shpsize;
	g->win->nxt_vert_inter_y = g->win->vert_inter_y
		- ((g->win->vert_inter_x - g->win->nxt_vert_inter_x)
			* tan(deg_to_rad(ray_angle)));
	g->win->vert_step_x = g->win->shpsize;
	g->win->vert_step_y = g->win->nxt_vert_inter_y
		- g->win->vert_inter_y;
	while (((int)((g->win->vert_inter_x + 1)
			/ g->win->shpsize)) < g->map->width
		&& ((int)(g->win->vert_inter_y
			/ g->win->shpsize)) < g->map->height
		&& g->win->vert_inter_x >= 0 && g->win->vert_inter_y >= 0
		&& g->map->map_array[(int)(g->win->vert_inter_y
			/ g->win->shpsize)][(int)((g->win->vert_inter_x + 1)
			/ g->win->shpsize)] != '1')
	{
		g->win->vert_inter_y += g->win->vert_step_y;
		g->win->vert_inter_x += g->win->vert_step_x;
	}
}

void	check_raycast_up(t_game *g, float ray_angle)
{
	g->win->hor_inter_y = floor((g->win->pos_y / g->win->shpsize))
		* g->win->shpsize;
	g->win->hor_inter_x = g->win->pos_x - ((g->win->pos_y
				- g->win->hor_inter_y) / tan(deg_to_rad(ray_angle)));
	g->win->nxt_hor_inter_y = g->win->hor_inter_y - g->win->shpsize;
	g->win->nxt_hor_inter_x = g->win->hor_inter_x
		- ((g->win->hor_inter_y - g->win->nxt_hor_inter_y)
			/ tan(deg_to_rad(ray_angle)));
	g->win->hor_step_y = g->win->shpsize;
	g->win->hor_step_x = g->win->nxt_hor_inter_x - g->win->hor_inter_x;
	while ((int)((g->win->hor_inter_x / g->win->shpsize)) < g->map->width
		&& ((int)((g->win->hor_inter_y - 1)
				/ g->win->shpsize)) < g->map->height
		&& g->win->hor_inter_x >= 0 && g->win->hor_inter_y >= 0
		&& g->map->map_array[(int)((g->win->hor_inter_y - 1)
			/ g->win->shpsize)][(int)((g->win->hor_inter_x)
			/ g->win->shpsize)] != '1')
	{
		g->win->hor_inter_y -= g->win->hor_step_y;
		g->win->hor_inter_x += g->win->hor_step_x;
	}
}

void	check_raycast_down(t_game *g, float ray_angle)
{
	g->win->hor_inter_y = floor((g->win->pos_y / g->win->shpsize) + 1)
		* g->win->shpsize;
	g->win->hor_inter_x = g->win->pos_x + (g->win->hor_inter_y
			- g->win->pos_y) / tan(deg_to_rad(ray_angle));
	g->win->nxt_hor_inter_y = g->win->hor_inter_y + g->win->shpsize;
	g->win->nxt_hor_inter_x = g->win->hor_inter_x
		+ ((g->win->nxt_hor_inter_y - g->win->hor_inter_y)
			/ tan(deg_to_rad(ray_angle)));
	g->win->hor_step_y = g->win->shpsize;
	g->win->hor_step_x = g->win->nxt_hor_inter_x - g->win->hor_inter_x;
	while (((int)(g->win->hor_inter_x / g->win->shpsize)) < g->map->width
		&& ((int)(g->win->hor_inter_y / g->win->shpsize)) < g->map->height
		&& g->win->hor_inter_x >= 0 && g->win->hor_inter_y >= 0
		&& g->map->map_array[(int)((g->win->hor_inter_y)
			/ g->win->shpsize)][(int)((g->win->hor_inter_x)
			/ g->win->shpsize)] != '1')
	{
		g->win->hor_inter_y += g->win->hor_step_y;
		g->win->hor_inter_x += g->win->hor_step_x;
	}
}
