/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:14:51 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/13 20:50:31 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image(t_long *game)
{
	game->wall.image = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&game->wall.w, &game->wall.h);
	game->ground.image = mlx_xpm_file_to_image(game->mlx_ptr, GROUND,
			&game->ground.w, &game->ground.h);
	game->player.image = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER,
			&game->player.w, &game->player.h);
	game->collectable.image = mlx_xpm_file_to_image(game->mlx_ptr, COLLECT,
			&game->collectable.w, &game->collectable.h);
	game->exit.image = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->exit.w, &game->exit.h);
	game->tornado.image = mlx_xpm_file_to_image(game->mlx_ptr, TORNADO,
			&game->tornado.w, &game->tornado.h);
	game->p1.image = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER1,
			&game->p1.w, &game->p1.h);
}

void	put_image(t_long *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ground.image, x * 42, y * 42);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.image, x * 42, y * 42);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.image, x * 42, y * 42);
	if (game->map[y][x] == 'P')
		draw_player(game, x, y);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectable.image, x * 42, y * 42);
	if (game->map[y][x] == 'T')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->tornado.image, x * 42, y * 42);
}

void	take_image(t_long *game)
{
	int		x;
	int		y;
	char	*s;

	y = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(game, x, y);
			x++;
		}
		y++;
	}
	s = ft_itoa(game->step);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, 12, 0xEEEEEE, "Steps");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 80, game->width, 0xEEEEEE, s);
	free(s);
}

void	draw_player(t_long *game, int x, int y)
{
	static int	a;

	if (a % 2 == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player.image, x * 42, y * 42);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->p1.image, x * 42, y * 42);
	a++;
	if (a == 100)
		a = 0;
}

void	ft_exit2(t_long *game)
{
	ft_1free(game->map);
	exit(3);
}
