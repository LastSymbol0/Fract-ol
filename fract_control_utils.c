/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_control_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:41:47 by aillia            #+#    #+#             */
/*   Updated: 2019/04/24 13:41:49 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	redraw(t_fract *fract)
{
	fract->optimise_r = 0;
	fract->optimise_i = 0;
	mlx_clear_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr);
	if (fract->iso == 1)
		mlx_clear_window(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr);
	draw(fract);
}

int		exit_proj(t_fract *fract)
{
	fract->iso = 0;
	return (1);
}

void	bonus_win(t_fract *fract)
{
	if (fract->iso == 0)
	{
		fract->mlx->bonus_win_ptr = mlx_new_window(fract->mlx->mlx_ptr,
			fract->mlx->width, fract->mlx->height, "aillia's fract iso");
		fract->mlx->bonus_img = mlx_new_image(fract->mlx->mlx_ptr,
									fract->mlx->width, fract->mlx->height);
		fract->mlx->bonus_img_ptr = mlx_get_data_addr(fract->mlx->bonus_img,
			&fract->mlx->bonus_bpp, &fract->mlx->bonus_line_size,
			&fract->mlx->bonus_endian);
		mlx_put_image_to_window(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr,
												fract->mlx->bonus_img, 0, 0);
		mlx_hook(fract->mlx->bonus_win_ptr, 17, 0, exit_proj, fract);
		fract->iso = 1;
	}
	else
	{
		mlx_destroy_window(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr);
		fract->iso = 0;
	}
}

int		legend(t_fract *fract)
{
	if (fract->legend == 0)
	{
		fract->legend = 1;
		redraw(fract);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 0, 0, L);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 20, 0, L1);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 40, 0, L2);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 60, 0, L3);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 80, 0, L4);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 100, 0, L5);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 120, 0, L6);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 140, 0, L7);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 160, 0, L8);
		STRING_PUT(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 180, 0, L9);
	}
	else
	{
		fract->legend = 0;
		redraw(fract);
	}
	return (0);
}
