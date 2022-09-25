/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:48:31 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/11 20:00:59 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	n_of_c(t_long *game)
{
	int	i;
	int	x;

	i = 0;
	game->nc = 0;
	while (game->map[i] != NULL)
	{
		x = 0;
		while (game->map[i][x] != '\0')
		{
			if (game->map[i][x] == 'C')
			{
				game->nc++;
			}
			x++;
		}
		i++;
	}
}

void	pps(t_long *game)
{
	int	i;
	int	x;
	int	n;

	i = 0;
	n = 1;
	while (game->map[i] != NULL)
	{
		x = 0;
		if (n == 0)
			break ;
		while (game->map[i][x] != '\0')
		{
			if (game->map[i][x] == 'P')
			{
				n = 0;
				break ;
			}
			x++;
		}
		i++;
	}
	game->ppx = x;
	game->ppy = i;
}

void	ft_check_walls2(t_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			write(1, "map error\n", 10);
			ft_exit2(game);
		}
		i++;
	}
}
