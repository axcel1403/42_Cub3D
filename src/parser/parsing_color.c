/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:36:32 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 21:03:22 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_uint8(int *color)
{
	if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255
		|| color[2] < 0 || color[2] > 255)
		return (false);
	return (true);
}

t_rgb	cub_get_color(int *arr)
{
	t_rgb	rgb;

	rgb.r = (uint8_t)arr[0];
	rgb.g = (uint8_t)arr[1];
	rgb.b = (uint8_t)arr[2];
	return (rgb);
}

static char	**color_strings_check(char *elems)
{
	char	**colors;

	colors = ft_split(elems, ',');
	if (ft_arrlen(colors) != 3 || !ft_isdigit_str(colors[0])
		|| !ft_isdigit_str(colors[1]) || !ft_isdigit_str(colors[2]))
	{
		ft_arrfree(colors);
		return (NULL);
	}
	return (colors);
}

static char	**parse_spaces(char **elems)
{
	char	**colors;
	char	*check;
	char	*tmp;
	int		i;

	i = 1;
	if (ft_strlen(elems[0]) != 1 || (*elems[0] != 'C' && *elems[0] != 'F'))
		return (false);
	if (elems[2] != NULL)
	{
		check = ft_strdup("");
		while (elems[i] != NULL)
		{
			tmp = check;
			check = ft_strjoin(tmp, elems[i]);
			free(tmp);
			i++;
		}
		colors = color_strings_check(check);
		free(check);
	}
	else
		colors = color_strings_check(elems[1]);
	return (colors);
}

bool	cub_config_color(char **elems, t_game *g)
{
	char	**colors;
	int		color[3];

	colors = parse_spaces(elems);
	if (colors == NULL)
		return (false);
	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	if (!is_uint8(color))
	{
		ft_arrfree(colors);
		return (false);
	}
	if (colors != NULL)
		ft_arrfree(colors);
	cub_config_color2(elems, g, color);
	return (true);
}
