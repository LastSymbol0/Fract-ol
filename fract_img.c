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

#include "fract.h"

void	pixel_put(t_fract *fract, int x, int y, int color)
{
	if (x < 0 || x >= fract->mlx->width || y < 0 || y >= fract->mlx->height)
		return ;
	*(int *)(fract->mlx->img_ptr + ((x + y * fract->mlx->width) *
		fract->mlx->bpp / 8)) = mlx_get_color_value(fract->mlx->mlx_ptr, color);
}

void	pixel_put_iso(t_fract *fract, int x, int y, double z)
{
	mlx_pixel_put(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr,
		(x - y) * cos(0.523599) + fract->mlx->width / 2,
		(x + y) * sin(0.523599) - (int)z, create_color_c(z, *fract));
}
