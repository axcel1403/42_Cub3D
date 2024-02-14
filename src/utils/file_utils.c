/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:08 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:15 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_config_color2(char **elems, t_game *g, int *color)
{
	if (ft_strnstr(elems[0], "F", 1))
	{
		g->assets->floor_rgb = cub_get_color(color);
		g->assets->floor_hex = cub_get_hex_color(g->assets->floor_rgb);
		g->mapflags |= FLAG_HASFLOOR;
	}
	else if (ft_strnstr(elems[0], "C", 1))
	{
		g->assets->ceiling_rgb = cub_get_color(color);
		g->assets->ceiling_hex = cub_get_hex_color(g->assets->ceiling_rgb);
		g->mapflags |= FLAG_HASCEILING;
	}
}

int	cub_file_open(t_game *g)
{
	int		fd;
	char	*filepath;

	filepath = g->map->file.filepath;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			error_exit(g, ".cub : Permission denied\n");
		else if (errno == ENOENT)
			error_exit(g, ".cub : No such file or directory\n");
		else
			error_exit(g, ".cub : Unknown error\n");
	}
	g->map->file.fd = fd;
	return (EXIT_SUCCESS);
}

bool	is_cub_file(char *filename)
{
	const char	*extension = ft_strrchr(filename, '.');

	if (!extension || extension == filename)
	{
		return (false);
	}
	return (ft_strncmp(extension, ".cub", 255) == 0);
}

bool	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("File [%s] doesn't exist\n", filename);
		return (false);
	}
	close(fd);
	return (true);
}
