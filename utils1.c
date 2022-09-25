/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:44:00 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/08 21:44:02 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strndup(const char *s1, size_t len)
{
	char	*sd;
	size_t	i;

	i = 0;
	while (s1[i] && i < len)
		i++;
	sd = malloc(sizeof(char) * i + 1);
	if (sd == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		sd[i] = s1[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sb = malloc(sizeof (char));
		if (sb == NULL)
			return (NULL);
		*sb = '\0';
		return (sb);
	}
	sb = ft_strndup(&s[start], len);
	if (sb == NULL)
		return (NULL);
	return (sb);
}

int	tornado_1(t_long *game)
{
	int	i;
	int	x;

	i = 0;
	while (game->map[i] != NULL)
	{
		x = 0;
		while (game->map[i][x])
		{
			if (game->map[i][x] == 'T')
				return (1);
			i++;
		}
		x++;
	}
	return (0);
}

void	tornado_p(t_long *game, char b, int x, int i)
{
	if (b == 'T')
	{
		game->tpy = i;
		game->tpx = x;
		game->t = 1;
	}
}

void	player_p(t_long *game, char b, int x, int i)
{
	if (b == 'P')
	{
		game->ppy = i;
		game->ppx = x;
	}
}
