/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:46:45 by aillia            #+#    #+#             */
/*   Updated: 2019/04/23 14:47:01 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

t_complex	create_complex(int x, int y, t_fract *fract, short offset)
{
	t_complex c;

	if (fract->optimise_r == 0 && fract->optimise_i == 0)
	{
		fract->optimise_r = (0.5 * fract->zoom * fract->mlx->width);
		fract->optimise_r1 = -offset + fract->move_x /
											(fract->mlx->width / 2) * 2;
		fract->optimise_i = (0.5 * fract->zoom * fract->mlx->height);
		fract->optimise_i1 = fract->move_y / (fract->mlx->height / 2) * 2;
	}
	c.r = 2 * (x - fract->mlx->width / 2) / fract->optimise_r +
														fract->optimise_r1;
	c.i = 2 * (y - fract->mlx->height / 2) / fract->optimise_i +
														fract->optimise_i1;
	return (c);
}

short		define_type(char *s)
{
	if (!s)
		ft_err("Error reading", 1);
	if (ft_strequ(s, "mandel"))
		return (1);
	if (ft_strequ(s, "julia"))
		return (2);
	if (ft_strequ(s, "newton"))
		return (3);
	if (ft_strequ(s, "mandel_5th"))
		return (4);
	if (ft_strequ(s, "mandel_5th_slim"))
		return (5);
	if (ft_strequ(s, "mandel_tricorn"))
		return (6);
	if (ft_strequ(s, "dragon"))
		return (7);
	return (0);
}

int			ft_exit(void *param)
{
	if (param)
		exit(0);
	system("leaks -q fractol");
	exit(0);
}

void		ft_err(char *err, int status)
{
	if (status == 1)
		ft_putstr("Error: ");
	ft_putstr(err);
	exit(status);
}

void		usage(void)
{
	system("clear");
	ft_putstr(GREEN_T);
	ft_putendl("Usage:");
	ft_putendl("\t./fractol type [WIN_SIZE] type [WIN_SIZE] ...\n");
	ft_putstr(GREY_T);
	ft_putendl("\t\tTypes:\t\tmandel, julia, newton, dragon");
	ft_putendl("\t\t\t\t\tmandel_5th, mandel_5th_slim, mandel_tricorn");
	ft_putendl("\t\tWindow size:\t1-4 (Default: 1)");
	ft_putstr(YELLOW_T);
	ft_putendl("Example:\n\t./fractol julia 3\n");
	ft_putendl("\t./fractol newton 2 mandel dragon 3\n");
}
