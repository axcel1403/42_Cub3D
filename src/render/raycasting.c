/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:49:21 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 19:00:01 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_view_angle(t_game *g)
{
	int		i;
	float	ray_angle;
	int		id_ray;

	i = 0;
	ray_angle = g->player->angle - (VIEW_ANGLE / 2);
	if (ray_angle < 0)
		ray_angle = 360 + ray_angle;
	id_ray = 0;
	while (i < g->win->raycnt)
	{
		if (ray_angle >= 360)
			ray_angle -= 360;
		check_ray_draw(g, ray_angle, id_ray);
		id_ray++;
		ray_angle += (VIEW_ANGLE / g->win->raycnt);
		i++;
	}
}

void	ray_casting(t_game *g, float ray_angle, int id_ray, mlx_image_t *img)
{
	double	height_wall;
	int		xstart;
	int		ystart;
	int		xend;
	int		yend;

	g->win->total_dist = g->win->total_dist * cos(deg_to_rad(ray_angle)
			- deg_to_rad(g->player->angle));
	height_wall = ((g->win->shpsize) * WINDOW_HEIGHT) / g->win->total_dist;
	xstart = id_ray;
	xend = id_ray;
	ystart = (WINDOW_HEIGHT / 2) - (height_wall / 2);
	yend = (WINDOW_HEIGHT / 2) + (height_wall / 2);
	g->win->texture_offset_x = g->win->current_texture * img->width;
	g->win->wallstart_pos = ystart;
	while (ystart < yend)
	{
		g->win->texture_offset_y = (((float)ystart
					- (float)g->win->wallstart_pos) / (float)height_wall)
			* img->height;
		if (ystart >= 0 && ystart < WINDOW_HEIGHT)
			mlx_put_pixel(g->img, xstart, (int)ystart, get_texel(img,
					g->win->texture_offset_x, g->win->texture_offset_y));
		ystart += 1;
	}
}

void	call_raycasting(t_game *g, float ray_angle, int id_ray)
{
	if (g->win->hor_dist < g->win->vert_dist)
	{
		g->win->total_dist = g->win->hor_dist;
		if (ray_angle >= 180 && ray_angle <= 360)
			ray_casting(g, ray_angle, id_ray, g->assets->north_texture);
		else
			ray_casting(g, ray_angle, id_ray, g->assets->south_texture);
		g->win->current_texture = (g->win->hor_inter_x / g->win->shpsize)
			- ((int)(g->win->hor_inter_x / g->win->shpsize));
	}
	else
	{
		g->win->total_dist = g->win->vert_dist;
		if (ray_angle >= 90 && ray_angle <= 270)
			ray_casting(g, ray_angle, id_ray, g->assets->east_texture);
		else
			ray_casting(g, ray_angle, id_ray, g->assets->west_texture);
		g->win->current_texture = (g->win->vert_inter_y / g->win->shpsize)
			- ((int)(g->win->vert_inter_y / g->win->shpsize));
	}
}
