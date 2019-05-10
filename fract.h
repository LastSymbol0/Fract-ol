/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:55:16 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:55:19 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <pthread.h>
# include <time.h>
# include <math.h>

# define GREEN_T "\x1b[32m"
# define GREY_T "\x1b[37m"
# define YELLOW_T "\x1b[33m"

# define BLUE(x) (int)(x) << 0
# define GREEN(x) (int)(x) << 8
# define RED(x) (int)(x) << 16

# define TO_RED 80 + line.start.x
# define TO_GREEN 250 - line.start.x
# define TO_BLUE 275 - line.start.x

# define STRING_PUT(x, y, z, a, b, c) mlx_string_put(x, y, z, a, b, c)

# define L "Legend:"
# define L0 "Press 'L' to show legend"
# define L1 "Move: mouse click or '<-' '^' '->' keys"
# define L2 "Zoom: mosue wheel or '+' '-' keys"
# define L3 "Show iso-projection: press 'P' key"
# define L4 "Change max iterations: 'home' and 'end' keys"
# define L5 "Change color spectrum: all num-pad keys or digits for presets"
# define L6 "Reset color spectrum: press 'R' key"
# define L7 "Reset zoom and position: press 'S' key"
# define L8 "To crate FdF 'Screen Shot': press 'F' key"
# define L9 "Mouse move changes: 'M' for julia, 'C' for color"

# define CARDIOID  tmp.r * tmp.r + tmp.i * tmp.i

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;

	void		*bonus_win_ptr;
	void		*bonus_img;
	char		*bonus_img_ptr;
	int			bonus_line_size;
	int			bonus_endian;
	int			bonus_bpp;

	void		*img;
	char		*img_ptr;
	int			line_size;
	int			endian;
	int			bpp;
}				t_mlx;

typedef struct	s_color
{
	float		frequenc;
	int			phase;
	int			sign;
}				t_color;

typedef struct	s_colors
{
	t_color		red;
	t_color		green;
	t_color		blue;
}				t_colors;

typedef struct	s_complex
{
	double			r;
	double			i;
}				t_complex;

typedef struct	s_fract
{
	t_mlx		*mlx;

	t_colors	colors;

	pthread_t	pthread_id[4];
	int			pthread_y_start;
	int			pthread_y_end;

	short		type;
	short		iso;
	short		legend;

	int			fdf;
	int			line;

	int			max_iters;
	float		zoom;
	float		move_x;
	float		move_y;
	int			color_coef;

	double		optimise_r;
	double		optimise_i;
	double		optimise_r1;
	double		optimise_i1;

	t_complex	julia;
	short		julia_move;
	short		color_move;
}				t_fract;

/*
** fract_color.c
*/
int				create_color(int red, int green, int blue);
int				create_color_c(float i, t_fract fract);

/*
** fract_color_presets.c
*/
void			set_colors_grey(t_fract *fract);
void			set_colors_psyho_barbie(t_fract *fract);
void			set_colors_dark_cyan(t_fract *fract);
void			set_colors_purple_lemon(t_fract *fract);
void			set_colors_red_n_yellow(t_fract *fract);
void			set_colors_psyho_purple(t_fract *fract);
void			set_colors_light_cyan(t_fract *fract);
void			set_colors_hard_shit(t_fract *fract);

/*
** fract_main.c
*/
void			draw(t_fract *fract);
void			*pixels(void *param);
int				main(int ac, char **av);
int				multi_window_checker(int ac, char **av, void *mlx);
void			route(int x, int y, t_fract *fract);

/*
** fract_set.c
*/
void			set_colors(t_fract *fract);
void			set_(t_fract *fract);
t_mlx			*set_mlx(t_fract *fract, int width, int height, void *mlx);

/*
** fract_controls.c
*/
int				key_controls(int key, t_fract *fract);
int				mouse_press(int button, int x, int y, t_fract *fract);
int				mouse_move(int x, int y, t_fract *fract);
void			color_exit_reset(int key, t_fract *fract);
void			green_and_blue(int key, t_fract *fract);

/*
** fract_img.c
*/
void			pixel_put(t_fract *fract, int x, int y, int color);
void			pixel_put_iso(t_fract *fract, int x, int y, double z);

/*
** fract_utils.c
*/
t_complex		create_complex(int x, int y, t_fract *fract, short offset);
short			define_type(char *s);
void			ft_err(char *err, int status);
int				ft_exit(void *param);
void			usage(void);

/*
** fract_utils2.c
*/
t_fract			*fract_creator(short type, int window_size, void *mlx);
int				go(t_fract *fract);

/*
** fract_control_utils.c
*/
int				exit_proj(t_fract *fract);
void			redraw(t_fract *fract);
void			bonus_win(t_fract *fract);
int				legend(t_fract *fract);
void			color_presets(int key, t_fract *fract);

/*
** fract_fract.c
*/
void			julia(t_fract *fract, int x, int y);
void			mandel(t_complex c, t_fract *fract, int x, int y);
void			newton(t_fract *fract, int x, int y);

/*
** fract_fract2.c
*/
void			mandel_tricorn(t_fract *fract, int x, int y);
void			mandel_5th(t_fract *fract, int x, int y);
void			mandel_5th_slim(t_fract *fract, int x, int y);

/*
** fract_fdf.c
*/
void			create_file(t_fract *fract);
void			write_to_file(t_fract *fract, int y, int i);
void			fdf(t_fract *fract);

/*
** fract_line.c
*/
void			put_line(t_line line, t_fract fract);
void			line_y_bigger(t_line line, int delta_x, int delta_y,
															t_fract fract);
void			line_x_bigger(t_line line, int delta_x, int delta_y,
															t_fract fract);
void			swap_p(t_line *line, int *sign, int *sign_z);

/*
** fract_dragon.c
*/
void			dragon(t_fract *fract);
t_line			create_line(int x0, int y0, int x1, int y1);
void			recurs_dragon(t_fract *fract, int max_iters, t_line line,
															double angle);

#endif
