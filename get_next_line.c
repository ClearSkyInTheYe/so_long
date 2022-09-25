/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:53:17 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 19:53:20 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*trstr(char *s)
{
	char	*str;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof (char ) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = i + 1;
	while (i > 0)
	{
		str[x] = s[x];
		i--;
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*tail(char *s )
{
	char	*str;
	size_t	i;
	size_t	x;
	size_t	b;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	b = i + 1;
	if (s[i] == '\0')
		b = i;
	if (s[i] == '\n' && s[i + 1] == '\0')
		return (NULL);
	x = 0;
	while (s[i++])
		x++;
	if (x == 0)
		return (NULL);
	str = malloc(sizeof (char ) * (x + 1));
	if (str == NULL)
		return (NULL);
	str = ft_cpy(b, str, s);
	return (str);
}

char	*ft_cpy(size_t b, char *str, char *s)
{
	size_t	x;

	x = 0;
	while (s[b])
		str[x++] = s[b++];
	str[x] = '\0';
	return (str);
}

char	*myread(int fd, char *s)
{
	char		*str;
	size_t		l;
	char		*tmp;

	if (read (fd, NULL, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_calloc1((BUFFER_SIZE + 1), sizeof (char ));
	if (!str)
		return (NULL);
	if (s == NULL || !ft_strchr(s, '\n'))
	{
		while (!ft_strchr(str, '\n'))
		{
			l = read(fd, str, BUFFER_SIZE);
			str[l] = '\0';
			if (l == 0)
				break ;
			tmp = ft_strjoin(s, str);
			free(s);
			s = tmp;
		}
		free(str);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*st;
	char		*tmp;

	if (s == NULL || !ft_strchr(s, '\n'))
	{
		s = myread(fd, s);
		if (s == NULL)
			return (NULL);
		st = trstr(s);
		tmp = tail(s);
		free(s);
		s = tmp;
		return (st);
	}
	if (s != NULL)
	{
		st = trstr(s);
		tmp = tail(s);
		free(s);
		s = tmp;
		return (st);
	}
	free(s);
	return (NULL);
}
