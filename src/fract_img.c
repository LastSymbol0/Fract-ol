/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:58:33 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:58:35 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

void	pixel_put(t_fract *fract, int x, int y, int color)
{
	if (x < 0 || x >= fract->mlx->width || y < 0 || y >= fract->mlx->height)
		return ;
	*(int *)(fract->mlx->img_ptr + ((x + y * fract->mlx->width) *
		fract->mlx->bpp / 8)) = mlx_get_color_value(fract->mlx->mlx_ptr, color);
}

void	pixel_put_iso(t_fract *fract, int x, int y, double z)
{
	int x_iso;
	int y_iso;

	x_iso = (int)((x - y) * cos(0.523599) + fract->mlx->width / 2);
	y_iso = (int)((x + y) * sin(0.523599) - (int)z);
	if (x_iso < 0 || x_iso >= fract->mlx->width ||
		y_iso < 0 || y_iso >= fract->mlx->height)
		return ;
	*(int *)(fract->mlx->bonus_img_ptr + ((x_iso + y_iso * fract->mlx->width) *
		fract->mlx->bpp / 8)) = mlx_get_color_value(fract->mlx->mlx_ptr,
													create_color_c(z, *fract));
}
