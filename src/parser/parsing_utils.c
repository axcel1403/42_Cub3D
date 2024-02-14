/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:13:33 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:00 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	store_player_position(t_game *g)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = g->map->map_array[i];
	while (line != NULL)
	{
		j = 0;
		while (line[j] != '\0')
		{
			if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E'
				|| line[j] == 'W')
			{
				g->map->spawnx = j;
				g->map->spawny = i;
				g->player->playerdirection = line[j];
				g->map->map_array[i][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
		line = g->map->map_array[i];
	}
}

int	strreps(char *line, char c)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (line[i])
		if (line[i++] == c)
			tabs++;
	return (tabs);
}

char	*remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (line);
}

bool	is_singleplayer(t_game *g)
{
	int	p;
	int	i;

	i = -1;
	p = 0;
	while (g->map->map_array[++i])
		p += (strreps(g->map->map_array[i], 'N') + strreps(g->map->map_array[i],
					'S') + strreps(g->map->map_array[i], 'E')
				+ strreps(g->map->map_array[i], 'W'));
	if (p == 1)
	{
		store_player_position(g);
		return (true);
	}
	else
	{
		printf("Not enough player (or too much idk really)\n");
		return (false);
	}
}

bool	is_valid_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (true);
	return (false);
}
