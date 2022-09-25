/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:26:40 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 19:26:44 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_palyer(t_long *game)
{
	int	i;
	int	x;
	int	p;

	x = 0;
	p = 0;
	while (game->map[x] != NULL)
	{
		i = 0;
		while (game->map[x][i++])
		{
			if (game->map[x][i] == 'P')
				p++;
		}
		x++;
	}
	if (p != 1)
	{
		ft_1free(game->map);
		write(1, "map error\n", 10);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_exit(t_long *game)
{
	int	i;
	int	x;
	int	p;

	x = 0;
	p = 0;
	while (game->map[x] != NULL)
	{
		i = 0;
		while (game->map[x][i])
		{
			if (game->map[x][i] == 'E')
				p++;
			i++;
		}
		x++;
	}
	if (p == 0)
	{
		ft_1free(game->map);
		write(1, "map error\n", 10);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_collect(t_long *game)
{
	int	i;
	int	x;
	int	p;

	x = 0;
	p = 0;
	while (game->map[x] != NULL)
	{
		i = 0;
		while (game->map[x][i])
		{
			if (game->map[x][i] == 'C')
				p++;
			i++;
		}
		x++;
	}
	if (p < 1)
	{
		ft_1free(game->map);
		write(1, "map error\n", 10);
		exit(EXIT_FAILURE);
	}
}

int	key_move(int keycode, t_long *game)
{
	if (keycode == 13)
		move_p(game, 0, -1);
	if (keycode == 53)
		ft_exit(game);
	if (keycode == 0)
		move_p(game, -1, 0);
	if (keycode == 1)
		move_p(game, 0, 1);
	if (keycode == 2)
		move_p(game, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_long	game;

	game.step = 0;
	game.cc = 0;
	if (argc != 2)
	{
		write(1, "Invalid number of arguments\n", 28);
		exit(EXIT_FAILURE);
	}
	check_format_map(argv[1]);
	ft_read_map(argv[1], &game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window (game.mlx_ptr, game.width * 42,
			game.height * 42, "WC2)");
	image(&game);
	take_image(&game);
	mlx_hook(game.win_ptr, 17, 0, ft_exit1, &game);
	mlx_hook(game.win_ptr, 02, 0, key_move, &game);
	if (game.t == 1)
		mlx_loop_hook(game.mlx_ptr, move_tornado, &game);
	mlx_loop(game.mlx_ptr);
}
