/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:09:31 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/11 22:09:34 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_p(t_long *game, int x, int y)
{
	if (game->map[game->ppy + y][game->ppx + x] == '1')
		return ;
	else if (game->map[game->ppy + y][game->ppx + x] == 'C')
	{
		game->cc++;
		game->map[game->ppy + y][game->ppx + x] = '0';
	}
	else if (game->map[game->ppy + y][game->ppx + x] == 'E')
	{
		if (game->cc == game->nc)
		{
			game->step++;
			ft_exit(game);
		}
		else
			return ;
	}
	else if (game->map[game->ppy + y][game->ppx + x] == 'T')
		ft_exit(game);
	pps1(game, x, y);
}

void	pps1(t_long *game, int x, int y)
{
	if (game->map[game->ppy - x][game->ppx - y] == 'C')
	{
		game->map[game->ppy][game->ppx] = '0';
		game->map[game->ppy + y][game->ppx + x] = 'P';
	}
	game->map[game->ppy][game->ppx] = '0';
	game->map[game->ppy + y][game->ppx + x] = 'P';
	move_p1(game, x, y);
}

void	move_p1(t_long *game, int x, int y)
{
	game->step++;
	write(1, "steps ", 6);
	ft_putnbr_fd(game->step, 1);
	write(1, "\n", 1);
	game->ppy = game->ppy + y;
	game->ppx = game->ppx + x;
	take_image(game);
}

void	ft_exit(t_long *game)
{
	mlx_destroy_window (game->mlx_ptr, game->win_ptr);
	ft_1free(game->map);
	ft_destoy(game);
	exit(EXIT_FAILURE);
}

void	ft_mapdop(t_long *game, int i)
{
	int	x;

	x = 0;
	while (game->map[x])
		x++;
	if (x != i)
	{
		write(1, "map error\n", 10);
		ft_exit2(game);
	}
	ft_map_width(game);
	ft_check_map_error(game);
	ft_check_all(game);
	n_of_c(game);
	game->height = i;
}
