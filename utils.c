/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:13:08 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 21:13:15 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && --n && (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	*ft_calloc(size_t n, size_t size)
{
	char			*s;
	size_t			total;
	size_t			i;

	if (size && SIZE_MAX / size < n)
		return (NULL);
	total = n * size;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (total--)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

static int	ft_strtrip1(char a, char const *set)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (set[g])
	{
		if (set[g] == a)
		{
			i = 1;
		}
		g++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		b;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	b = ft_strlen(s1);
	while (s1[i] && ft_strtrip1(s1[i], set) == 1)
		i++;
	while (i < b && s1[b - 1] && ft_strtrip1(s1[b - 1], set) == 1)
		b--;
	s2 = ft_substr(s1, i, b - i);
	return (s2);
}

void	ft_check_all(t_long *game)
{
	ft_check_collect(game);
	ft_check_exit(game);
	ft_check_palyer(game);
}
