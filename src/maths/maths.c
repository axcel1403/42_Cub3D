/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:31:21 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/07 21:13:37 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y1 - y2), 2)));
}
