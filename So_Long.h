/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:52:58 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/03 22:10:02 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"

# define FPS 64

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			lstfrm;
	t_movement	*mv;
}			t_window;

typedef struct s_pars
{
	char	**ffmap;
	bool	exit;
}			t_pars;

typedef struct s_map
{
	char		**map;
	int			mapfd;
	int			exit[2];
	int			spawn[2];
	int			marker[3];
	int			size_line;
	int			size_col;
	int			reachable;
}				t_map;

typedef struct s_movement
{
	void		*right[3];
	void		*left[3];
	void		*up[3];
	void		*down[2];
	void		*stay[2];
	void		*env[6];
}				t_movement;

typedef struct s_game
{
	int			player[2];
	int			exit_img;
	int			item;
	int			moves;
	bool		kp;
	t_map		*map;
	t_pars		*pars;
	t_window	*win;
}				t_game;

///////////////////////////////////////
/*              parsing              */
///////////////////////////////////////

int		intermap_check(t_map *data, int linelen, int x, int y);
bool	map_parsing(t_game *data, char *map);

///////////////////////////////////////
/*          game management          */
///////////////////////////////////////

void	*xpm_img(void *mlx, char *path, int size);
bool	init_window(t_game *data);
bool	put_image(t_game *data, t_window *win, char **map);
void	events(t_game *data);
int		kp(int keysym, t_game *data);
int		kr(t_game *data);
int		loop_hook(t_game *data);
int		keysel(int keysym, t_game *data);

///////////////////////////////////////
/*         memory management         */
///////////////////////////////////////

void	freedarray(char **sent);
void	clean_img(t_game *data);
void	exit_w_code(int code, t_game *data);
void	quit_lose(t_game *data);
int		quit_sl(t_game *data);
void	quit_win(t_game *data);


#endif
