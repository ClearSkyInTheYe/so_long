/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:25:56 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 19:25:58 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*s3;
	size_t	l3;
	size_t	l1;
	size_t	l2;

	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	l1 = 0;
	l2 = 0;
	s3 = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	l3 = 0;
	while (s1[l1])
		s3[l3++] = s1[l1++];
	while (s2[l2])
		s3[l3++] = s2[l2++];
	s3[l3] = '\0';
	return (s3);
}

void	ft_read_map(char *argv, t_long *game)
{
	int		fd;
	char	*str;
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	fd = ft_fileerror(argv);
	str = NULL;
	s = get_next_line(fd);
	while (s)
	{
		tmp = ft_strjoin1(str, s);
		free(s);
		free(str);
		str = tmp;
		s = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map = ft_split(str, '\n');
	free(str);
	ft_mapdop(game, i);
	ft_check_walls(game);
}

void	ft_map_width(t_long *game)
{
	int	i;
	int	x;

	i = 0;
	x = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (x != ft_strlen(game->map[i]))
		{
			write(1, "map error\n", 10);
			ft_exit2(game);
		}
		i++;
	}
	game->width = x;
}

void	ft_check_map_error(t_long *game)
{
	int	i;
	int	x;

	i = 0;
	while (game->map[i])
	{
		x = 0;
		while (game->map[i][x] != '\0')
		{
			player_p(game, game->map[i][x], x, i);
			tornado_p(game, game->map[i][x], x, i);
			if (game->map[i][x] != '1' && game->map[i][x] != '0'
				&& game->map[i][x] != 'E' && game->map[i][x] != 'C'
				&& game->map[i][x] != 'P' && game->map[i][x] != 'T')
			{
				write(1, "map error\n", 10);
				ft_exit2(game);
			}
			x++;
		}
		i++;
	}
}

void	ft_check_walls(t_long *game)
{
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1')
		{
			write(1, "map error\n", 10);
			ft_exit2(game);
		}
		x++;
	}
	x = 0;
	while (game->map[game->height - 1][x])
	{
		if (game->map[game->height - 1][x] != '1')
		{
			write(1, "map error\n", 10);
			ft_exit2(game);
		}
		x++;
	}
	ft_check_walls2(game);
}
