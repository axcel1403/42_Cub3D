/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:43:59 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:15 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Si ça compile pas
-> curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
-> brew install cmake
-> brew install glfw
*/

#include "cub3d.h"

static int	argv_check(char *argv, int argc)
{
	if (argc != 2)
		return (false);
	if (argv == NULL)
		return (false);
	if (is_cub_file(argv))
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!argv_check(argv[1], argc))
	{
		ft_putstr_fd(USAGEPRINT, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	init_game_struct(&game);
	game->map->file.filepath = argv[1];
	cub_main_parser(game);
	init_mlx(game, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	init_textures(game);
	init_player(game);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img)
		return (1);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	init_draw(game, 1);
	mlx_hooks(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
