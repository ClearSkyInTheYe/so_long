/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tornado.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:26:34 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/20 20:26:36 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tornado(t_long *game, char *s)
{
	void	*a;

	a = game->tornado.image;
	if (a)
		mlx_destroy_image(game->mlx_ptr, a);
	game->tornado.image = mlx_xpm_file_to_image(game->mlx_ptr, s,
			&game->tornado.w, &game->tornado.h);
	take_image(game);
}

int	move_tornado(t_long *game)
{
	static int	a;

	if (a % 1000 == 0)
		moving_tornado(game);
	if (a == 1000)
		draw_tornado(game, TORNADO);
	if (a == 2000)
		draw_tornado(game, TORNADO1);
	if (a == 3000)
		draw_tornado(game, TORNADO2);
	if (a > 3000)
		a = 0;
	a++;
	return (0);
}

void	move_up(t_long *game)
{
	static int	a;

	if (a == 10)
	{
		if (game->map[game->tpy - 1][game->tpx] == 'P')
			ft_exit(game);
		game->map[game->tpy][game->tpx] = '0';
		game->tpy = game->tpy - 1;
		game->map[game->tpy][game->tpx] = 'T';
		if (game->map[game->tpy - 1][game->tpx] == 'E'
			|| game->map[game->tpy - 1][game->tpx] == 'C'
			|| game->map[game->tpy - 1][game->tpx] == '1'
				)
			game->dir = 1;
	}
	if (a > 10)
		a = 0;
	a++;
}

void	move_down(t_long *game)
{
	static int	a;

	if (a == 10)
	{
		if (game->map[game->tpy + 1][game->tpx] == 'P')
			ft_exit(game);
		game->map[game->tpy][game->tpx] = '0';
		game->tpy = game->tpy + 1;
		game->map[game->tpy][game->tpx] = 'T';
		if (game->map[game->tpy + 1][game->tpx] == 'E'
			|| game->map[game->tpy + 1][game->tpx] == 'C'
			|| game->map[game->tpy + 1][game->tpx] == '1'
				)
			game->dir = 2;
	}
	if (a > 10)
		a = 0;
	a++;
}

void	moving_tornado(t_long *game)
{
	tornado_help(game);
	if (game->map[game->tpy + 1][game->tpx] == 'E'
		|| game->map[game->tpy + 1][game->tpx] == 'C'
		|| game->map[game->tpy + 1][game->tpx] == '1'
		|| game->map[game->tpy + 1][game->tpx] == 'T'
		||game->map[game->tpy - 1][game->tpx] == 'E'
		|| game->map[game->tpy - 1][game->tpx] == 'C'
		|| game->map[game->tpy - 1][game->tpx] == '1'
		|| game->map[game->tpy - 1][game->tpx] == 'T')
		return ;
	else if (game->map[game->tpy + 1][game->tpx] == 'E'
			|| game->map[game->tpy + 1][game->tpx] == 'C'
			|| game->map[game->tpy + 1][game->tpx] == '1')
		move_up(game);
	if (game->map[game->tpy - 1][game->tpx] == 'E'
		|| game->map[game->tpy - 1][game->tpx] == 'C'
		|| game->map[game->tpy - 1][game->tpx] == '1')
		move_down(game);
	if (game->dir == 1)
		move_down(game);
	else
		move_up(game);
}
