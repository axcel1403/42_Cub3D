/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:16:53 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:01:17 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map_format(t_game *g)
{
	int	i;
	int	j;

	if (!g->map->map_array || is_singleplayer(g) == false)
		return (false);
	i = -1;
	while (g->map->map_array[++i])
	{
		j = -1;
		while (g->map->map_array[i][++j])
		{
			if (ft_strchr("0NSWE", g->map->map_array[i][j]))
			{
				if (i == 0 || i == g->map->height - 1 || j == 0
					|| j == g->map->width - 1)
					return (false);
				if (g->map->map_array[i - 1][j] == ' ' || g->map->map_array[i
					+ 1][j] == ' ' || g->map->map_array[i][j - 1] == ' '
					|| g->map->map_array[i][j + 1] == ' ')
					return (false);
			}
		}
	}
	return (true);
}

bool	is_player_on_edge(t_game *g)
{
	int	map_width;
	int	map_height;

	map_width = ft_strlen(g->map->map_array[0]);
	map_height = 0;
	while (g->map->map_array[map_height] != NULL)
	{
		map_height++;
	}
	if (g->map->spawnx == 0 || g->map->spawnx == map_width - 1
		|| g->map->spawny == 0 || g->map->spawny == map_height - 1)
	{
		return (true);
	}
	return (false);
}

uint32_t	cub_get_hex_color(t_rgb rgb)
{
	uint32_t	hex;

	hex = 0;
	hex += rgb.r << 24;
	hex += rgb.g << 16;
	hex += rgb.b << 8;
	hex += ALPHA_CHANNEL;
	return (hex);
}
