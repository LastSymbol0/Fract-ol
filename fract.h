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
# include <math.h>

# define GREEN_T "\x1b[32m"
# define GREY_T "\x1b[37m"
# define YELLOW_T "\x1b[33m"

# define BLUE(x) (int)(x) << 0
# define GREEN(x) (int)(x) << 8
# define RED(x) (int)(x) << 16

# define STRING_PUT(x, y, z, a, b, c) mlx_string_put(x, y, z, a, b, c)

# define TO_RED 0 + i * 2
# define TO_GREEN (0 + i * i)
# define TO_BLUE (255 - i)

# define L "Legend:"
# define L0 "Press 'L' to show legend"
# define L1 "Move: mouse click or '<-' '^' '->' keys"
# define L2 "Zoom: mosue wheel or '+' '-' keys"
# define L3 "Show iso-projection: press 'P' key"
# define L4 "Change max iterations: 'home' and 'end' keys"
# define L5 "Change color spectrum: all num-pad keys"
# define L6 "Reset color spectrum: press 'R' key"
# define L7 "Reset zoom and position: press 'S' key"

# define CARDIOID  tmp.r * tmp.r + tmp.i * tmp.i

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;

	void		*bonus_win_ptr;

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

	short		type;
	short		iso;
	short		legend;

	int			max_iters;
	float		zoom;
	float		move_x;
	float		move_y;
	int			color_coef;

	double		optimise_r;
	double		optimise_i;
	double		optimise_r1;
	double		optimise_i1;
}				t_fract;

/*
** fract_color.c
*/
int				create_color(int red, int green, int blue);
int				create_color_c(float i, t_fract fract);

/*
** fract_main.c
*/
void			pixels(t_fract *fract);
int				main(int ac, char **av);
t_fract			*multi_window_checker(int ac, char **av);
t_fract			*fract_creator(short type, int window_size);
void			route(int x, int y, t_fract *fract);

/*
** fract_set.c
*/
void			set_colors(t_fract *fract);
void			set_(t_fract *fract);
t_mlx			*set_mlx(t_fract *fract, int width, int height);

/*
** fract_controls.c
*/
int				key_controls(int key, t_fract *fract);
int				mouse_press(int button, int x, int y, t_fract *fract);
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
** fract_control_utils.c
*/
int				exit_proj(t_fract *fract);
void			redraw(t_fract *fract);
void			bonus_win(t_fract *fract);
int				legend(t_fract *fract);

/*
** fract_fract.c
*/
void			julia(t_fract *fract, int x, int y);
void			mandel(t_complex c, t_fract *fract, int x, int y);
void			newton(t_fract *fract, int x, int y);

#endif
