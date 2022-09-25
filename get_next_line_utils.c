/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:54:10 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 19:54:14 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*sd;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	sd = malloc(sizeof(char) * i + 1);
	if (sd == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sd[i] = s1[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}

char	*ft_strchr(const char	*str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if (*str == (char) c)
		return ((char *) str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_calloc1(size_t n, size_t size)
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
