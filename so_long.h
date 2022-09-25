/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:17:20 by chfederi          #+#    #+#             */
/*   Updated: 2022/04/07 19:17:22 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include<stdint.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WALL "./wc2/water.xpm"
# define GROUND "./wc2/ground.xpm"
# define COLLECT "./wc2/pig.xpm"
# define EXIT "./wc2/pigfarm.xpm"
# define PLAYER "./wc2/peon.xpm"
# define PLAYER1 "./wc2/peon1.xpm"
# define TORNADO "./wc2/tornado.xpm"
# define TORNADO1 "./wc2/tornado1.xpm"
# define TORNADO2 "./wc2/tornado2.xpm"

typedef struct s_image
{
	void	*image;
	int		w;
	int		h;
}t_mig;

typedef struct s_long
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		nc;
	int		cc;
	int		ppx;
	int		ppy;
	int		step;
	int		tpx;
	int		tpy;
	int		t;
	int		dir;
	t_mig	ground;
	t_mig	wall;
	t_mig	player;
	t_mig	collectable;
	t_mig	exit;
	t_mig	tornado;
	t_mig	p1;
}t_long;
char	*get_next_line(int fd);
char	*myread(int fd, char *s);
char	*ft_strdup(const char *s1);
char	*ft_cpy(size_t b, char *str, char *s);
char	*tail(char *s );
char	*trstr(char *s);
char	*ft_calloc1(size_t n, size_t size);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char	*str, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_format_map(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_read_map(char *argv, t_long *game);
char	**ft_split(char *s, char c);
void	*ft_1free(char **s);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_map_width(t_long *game);
void	ft_check_map_error(t_long *game);
void	ft_check_palyer(t_long *game);
void	ft_check_exit(t_long *game);
void	ft_check_collect(t_long *game);
void	ft_check_all(t_long *game);
void	n_of_c(t_long *game);
void	pps1(t_long *game, int x, int y);
void	move_p1(t_long *game, int x, int y);
void	image(t_long *game);
void	put_image(t_long *game, int x, int y);
void	take_image(t_long *game);
void	move_p(t_long *game, int x, int y);
void	draw_player(t_long *game, int x, int y);
void	tornado_p(t_long *game, char b, int x, int i);
void	player_p(t_long *game, char b, int x, int i);
int		tornado_1(t_long *game);
int		key_move(int keycode, t_long *game);
void	draw_tornado(t_long *game, char *s);
int		move_tornado(t_long *game);
void	moving_tornado(t_long *game);
void	move_down(t_long *game);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_exit(t_long *game);
void	ft_mapdop(t_long *game, int i);
char	*ft_itoa(int n);
int		ft_fileerror(char *argv);
int		ft_exit1(t_long *game);
void	ft_destoy(t_long *game);
void	ft_check_t(t_long *game);
void	tornado_help(t_long *game);
void	move_up(t_long *game);
void	ft_check_walls(t_long *game);
void	ft_exit2(t_long *game);
void	ft_check_walls2(t_long *game);

#endif
