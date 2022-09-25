/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:12:10 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/26 20:14:01 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destoy(t_long *game)
{
	if (game->wall.image)
		mlx_destroy_image(game->mlx_ptr, game->wall.image);
	if (game->ground.image)
		mlx_destroy_image(game->mlx_ptr, game->ground.image);
	if (game->player.image)
		mlx_destroy_image(game->mlx_ptr, game->player.image);
	if (game->collectable.image)
		mlx_destroy_image(game->mlx_ptr, game->collectable.image);
	if (game->exit.image)
		mlx_destroy_image(game->mlx_ptr, game->exit.image);
	if (game->tornado.image)
		mlx_destroy_image(game->mlx_ptr, game->tornado.image);
	if (game->p1.image)
		mlx_destroy_image(game->mlx_ptr, game->p1.image);
}

int	ft_fileerror(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(1, "File error\n", 11);
		exit(3);
	}
	return (fd);
}

int	ft_exit1(t_long *game)
{
	ft_exit(game);
	return (0);
}

void	ft_check_t(t_long *game)
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
			if (game->map[x][i] == 'T')
				p = 1;
			i++;
		}
		x++;
	}
	if (p == 1)
		game->t = 1;
	else
		game->t = 0;
}

void	tornado_help(t_long *game)
{
	if (game->map[game->tpy + 1][game->tpx] == '0'
		|| game->map[game->tpy + 1][game->tpx] == 'P')
		move_down(game);
	if (game->map[game->tpy - 1][game->tpx] == '0'
		|| game->map[game->tpy - 1][game->tpx] == 'P')
		move_up(game);
}
