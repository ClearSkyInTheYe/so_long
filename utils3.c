/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:39:53 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/22 20:39:55 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static	int	ft_nlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n > 0)
	{
		if (n <= 9 && n > 0)
		{
			i = 1;
			return (i);
		}
		while ((n / 10) > 9)
		{
			n = n / 10;
			i++;
		}
		i = i + 2;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	c;
	char			*s;
	int				i;
	int				l;
	long			b;

	b = n;
	i = ft_nlen(n);
	l = ft_nlen(n) - 1;
	s = malloc(sizeof (char) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
		n = -n;
	c = n;
	while (l >= 0)
	{
		s[l] = c % 10 + 48;
		c = c / 10;
		l--;
	}
	if (b < 0)
		s[l + 1] = '-';
	s[i] = '\0';
	return (s);
}

void	check_format_map(char *str)
{
	int		i;
	int		fd;
	char	*s;

	s = malloc(sizeof (char ) * 11);
	if (s == NULL)
		exit(EXIT_FAILURE);
	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
	{
		write(1, "Invalid map format\n", 19);
		exit(EXIT_FAILURE);
	}
	fd = ft_fileerror(str);
	i = read(fd, s, 10);
	if (i < 1)
	{
		write(1, "Invalid map format\n", 19);
		exit(EXIT_FAILURE);
	}
	close(fd);
	free(s);
}
