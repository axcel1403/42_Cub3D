/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:26:46 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:00:00 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_config_texture_2(char *elem, t_game *g, char c)
{
	if (c == 'N')
	{
		g->mapflags |= FLAG_HASNORTH;
		g->assets->north_path = ft_strdup(elem);
	}
	else if (c == 'S')
	{
		g->mapflags |= FLAG_HASSOUTH;
		g->assets->south_path = ft_strdup(elem);
	}
	else if (c == 'W')
	{
		g->mapflags |= FLAG_HASWEST;
		g->assets->west_path = ft_strdup(elem);
	}
	else if (c == 'E')
	{
		g->mapflags |= FLAG_HASEAST;
		g->assets->east_path = ft_strdup(elem);
	}
	else
		return ;
}

static bool	set_config_texture(char **elems, t_game *g)
{
	if (elems == NULL || ft_arrlen(elems) != 2)
		return (false);
	if (ft_strlen(elems[1]) <= 4 || !ft_strnstr(elems[1] + ft_strlen(elems[1])
			- 4, ".png", 4) || !file_exists(elems[1]))
		return (false);
	if (ft_strncmp(elems[0], "NO", 2) == 0 && !(g->mapflags & FLAG_HASNORTH))
		set_config_texture_2(elems[1], g, 'N');
	else if (ft_strncmp(elems[0], "SO", 2) == 0
		&& !(g->mapflags & FLAG_HASSOUTH))
		set_config_texture_2(elems[1], g, 'S');
	else if (ft_strncmp(elems[0], "WE", 2) == 0
		&& !(g->mapflags & FLAG_HASWEST))
		set_config_texture_2(elems[1], g, 'W');
	else if (ft_strncmp(elems[0], "EA", 2) == 0
		&& !(g->mapflags & FLAG_HASEAST))
		set_config_texture_2(elems[1], g, 'E');
	else
		return (false);
	return (true);
}

static bool	cub_set_element(char **elems, t_game *g)
{
	bool	error;

	error = true;
	if (ft_arrlen(elems) > 0)
	{
		if (ft_arrlen(elems) != 2)
			error = false;
		if ((set_config_texture(elems, g)) == false)
			error = cub_config_color(elems, g);
	}
	if (elems != NULL)
		ft_arrfree(elems);
	return (error);
}

int	cub_parse_elements(t_game *g)
{
	bool	error;
	char	*line;
	char	*tmp;
	int		fd;

	error = true;
	fd = g->map->file.fd;
	while (error != false)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = line;
		line = ft_strndup(tmp, ft_strlen(tmp) - 1);
		free(tmp);
		error = cub_set_element(ft_split(line, ' '), g);
		free(line);
		if (g->mapflags == 0b01111110)
			break ;
	}
	if (g->mapflags != 0b01111110)
		return (false);
	return (error);
}

int	cub_main_parser(t_game *g)
{
	g->mapflags = 0b00000000;
	cub_file_open(g);
	if (cub_parse_elements(g) == false)
		error_exit(g, "Parsing Elements -- Error\n");
	if (cub_parse_map(g) == false)
		error_exit(g, "Parsing Map -- Error\n");
	if (is_player_on_edge(g) == true)
		error_exit(g, "Player is on the edge of the map\n");
	return (EXIT_SUCCESS);
}
