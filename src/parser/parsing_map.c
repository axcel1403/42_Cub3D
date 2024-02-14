/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:30:45 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 19:34:10 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_valid_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static char	*fix_tabs(char *line)
{
	char	*str;
	int		i;
	int		t;
	int		a;

	str = (char *)ft_calloc(sizeof(char), ft_strlen(line) + (strreps(line, '\t')
				* 3) + 1);
	if (!str)
		return (NULL);
	i = -1;
	t = 0;
	while (line[++i])
	{
		if (line[i] == '\t')
		{
			a = 0;
			while (a < 4)
				str[(i + (3 * t)) + a++] = ' ';
			t++;
		}
		else
			str[i + (3 * t)] = line[i];
	}
	free(line);
	return (str);
}

static void	add_map_row(char *line, t_game *g)
{
	int		i;
	char	**a;

	if (!line)
		return ;
	a = (char **)calloc(sizeof(char *), ft_arrlen(g->map->map_array) + 2);
	if (!a)
		return ;
	i = 0;
	while (i < ft_arrlen(g->map->map_array))
	{
		a[i] = ft_strdup(g->map->map_array[i]);
		i++;
	}
	a[i] = ft_strdup(line);
	if (g->map->map_array)
		ft_arrfree(g->map->map_array);
	g->map->map_array = a;
}

static bool	set_up_map(t_game *g)
{
	int		i;
	char	**new_map;

	i = -1;
	g->map->width = 0;
	if (!g || !g->map)
		return (false);
	while (g->map->map_array[++i])
		if (ft_strlen(g->map->map_array[i]) > (size_t)g->map->width)
			g->map->width = ft_strlen(g->map->map_array[i]);
	g->map->height = i;
	new_map = (char **)ft_calloc(sizeof(char *), g->map->height + 1);
	if (!new_map)
		return (false);
	i = -1;
	while (++i < g->map->height)
	{
		new_map[i] = (char *)ft_calloc(sizeof(char), g->map->width + 1);
		ft_memset(new_map[i], ' ', g->map->width);
		ft_memcpy(new_map[i], g->map->map_array[i],
			ft_strlen(g->map->map_array[i]));
	}
	ft_arrfree(g->map->map_array);
	g->map->map_array = new_map;
	return (true);
}

int	cub_parse_map(t_game *g)
{
	bool	error;
	char	*line;

	error = false;
	while (error != true)
	{
		line = get_next_line(g->map->file.fd);
		if (line == NULL)
			break ;
		line = remove_newline(line);
		if (ft_strlen(line))
		{
			line = fix_tabs(line);
			if (!is_valid_map_line(line))
				error = true;
			else
				add_map_row(line, g);
		}
		free(line);
	}
	if (g->map->map_array == 0)
		error_exit(g, "No map provided\n");
	if (error == true || set_up_map(g) == false)
		return (error);
	return (is_valid_map_format(g));
}
