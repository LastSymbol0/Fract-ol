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
	fract->legend = 0;
	fract->move_x = 0;
	fract->move_y = 0;
}

void	set_colors(t_fract *fract)
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
	return (mlx);
}
