/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:19:39 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 18:59:52 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcul_distance(t_game *g)
{
	g->win->hor_dist = distance_between_points(g->win->pos_x,
			g->win->pos_y, g->win->hor_inter_x, g->win->hor_inter_y);
	g->win->vert_dist = distance_between_points(g->win->pos_x,
			g->win->pos_y, g->win->vert_inter_x, g->win->vert_inter_y);
}

uint32_t	get_texel(mlx_image_t *img, int x, int y)
{
	uint8_t	*pixel;
	uint8_t	alpha;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	pixel = &img->pixels[((y * img->width) + x) * 4];
	red = pixel[0];
	green = pixel[1];
	blue = pixel[2];
	alpha = pixel[3];
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

void	check_ray_draw(t_game *g, float ray_angle, int id_ray)
{
	if (ray_angle > 0 && ray_angle < 180)
		check_raycast_down(g, ray_angle);
	else
		check_raycast_up(g, ray_angle);
	if (ray_angle < 90 || ray_angle > 270)
		check_raycast_right(g, ray_angle);
	else
		check_raycast_left(g, ray_angle);
	calcul_distance(g);
	call_raycasting(g, ray_angle, id_ray);
}
