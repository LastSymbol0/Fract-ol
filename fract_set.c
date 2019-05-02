/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:57:58 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:57:59 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	set_(t_fract *fract)
{
	fract->max_iters = 50;
	fract->zoom = 1;
	fract->iso = 0;
	fract->julia_move = 1;
	fract->color_move = -1;
	fract->legend = 0;
	fract->fdf = 0;
	fract->line = 0;
	fract->move_x = 0;
	fract->move_y = 0;

	// fract->ptread_id[0] = ;
	// fract->ptread_id[1] = ;
	// fract->ptread_id[2] = ;
	// fract->ptread_id[3] = ;
}

void	set_colors(t_fract *fract)
{
	if (fract->type == 1)
		set_colors_light_cyan(fract);
	else if (fract->type == 2)
		set_colors_hard_shit(fract);
	else if (fract->type == 3)
		set_colors_psyho_purple(fract);
	else
		set_colors_purple_lemon(fract);
}

void	set_colors_grey(t_fract *fract)
{
	fract->colors.red.frequenc = 0.01;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = 0.01;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = -1;
	fract->colors.blue.frequenc = 0.01;
	fract->colors.blue.phase = 2;
	fract->colors.blue.sign = -1;
}

void	set_colors_psyho_barbie(t_fract *fract)
{
	fract->colors.red.frequenc = -0.053;
	fract->colors.red.phase = 18;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = - 0.228;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = -1;
	fract->colors.blue.frequenc = 0.073;
	fract->colors.blue.phase = 2;
	fract->colors.blue.sign = -1;
}

void	set_colors_purple_lemon(t_fract *fract)
{
	fract->colors.red.frequenc = -0.116;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = 1;
	fract->colors.green.frequenc = -0.081;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = 1;
	fract->colors.blue.frequenc = -0.767001;
	fract->colors.blue.phase = 2;
	fract->colors.blue.sign = 1;
}

void	set_colors_dark_cyan(t_fract *fract)
{
	fract->colors.red.frequenc = 0.003;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = 0.017;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = -1;
	fract->colors.blue.frequenc = 0.003;
	fract->colors.blue.phase = 2;
	fract->colors.blue.sign = -1;
}

void	set_colors_light_cyan(t_fract *fract)
{
	fract->colors.red.frequenc = -0.193;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = 0.003;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = 1;
	fract->colors.blue.frequenc = 0.024;
	fract->colors.blue.phase = -3;
	fract->colors.blue.sign = 1;
}

void	set_colors_psyho_purple(t_fract *fract)
{
	fract->colors.red.frequenc = -0.214;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = -0.27;
	fract->colors.green.phase = 10;
	fract->colors.green.sign = 1;
	fract->colors.blue.frequenc = 0.01;
	fract->colors.blue.phase = -5;
	fract->colors.blue.sign = 1;
}

void	set_colors_red_n_yellow(t_fract *fract)
{
	fract->colors.red.frequenc = 0.003;
	fract->colors.red.phase = 2;
	fract->colors.red.sign = 1;
	fract->colors.green.frequenc = 0.017;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = 1;
	fract->colors.blue.frequenc = 0.003;
	fract->colors.blue.phase = 2;
	fract->colors.blue.sign = -1;
}

void	set_colors_hard_shit(t_fract *fract)
{
	fract->colors.red.frequenc = -0.298000;
	fract->colors.red.phase = 1;
	fract->colors.red.sign = -1;
	fract->colors.green.frequenc = 0.185;
	fract->colors.green.phase = 2;
	fract->colors.green.sign = -1;
	fract->colors.blue.frequenc = 0.157;
	fract->colors.blue.phase = 6;
	fract->colors.blue.sign = -1;
}

t_mlx	*set_mlx(t_fract *fract, int width, int height)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->line_size = 0;
	mlx->endian = 0;
	mlx->bpp = 4;
	mlx->width = width;
	mlx->height = height;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
														"aillia's fract");
	mlx->img = mlx_new_image(mlx->mlx_ptr, width, height);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_size,
															&mlx->endian);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 0, key_controls, fract);
	mlx_hook(mlx->win_ptr, 17, 0, ft_exit, NULL);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, fract);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, fract);
	return (mlx);
}
