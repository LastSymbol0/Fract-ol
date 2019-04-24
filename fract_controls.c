/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:58:22 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:58:24 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mouse_press(int button, int x, int y, t_fract *fract)
{
	if (button == 4)
		fract->zoom += fract->zoom / 2;
	else if (button == 5)
		fract->zoom -= fract->zoom / 2;
	fract->move_x += (x - fract->mlx->width / 2) / fract->zoom;
	fract->move_y += (y - fract->mlx->height / 2) / fract->zoom;
	redraw(fract);
	return (1);
}

void	green_and_blue(int key, t_fract *fract)
{
	if (key == 81)
		fract->colors.green.frequenc += 0.007;
	else if (key == 87)
		fract->colors.green.phase += 1;
	else if (key == 91)
		fract->colors.green.frequenc -= 0.007;
	else if (key == 84)
		fract->colors.green.phase -= 1;
	else if (key == 64)
		fract->colors.green.sign *= -1;
	else if (key == 75)
		fract->colors.blue.frequenc += 0.007;
	else if (key == 88)
		fract->colors.blue.phase += 1;
	else if (key == 92)
		fract->colors.blue.frequenc -= 0.007;
	else if (key == 85)
		fract->colors.blue.phase -= 1;
	else if (key == 79)
		fract->colors.blue.sign *= -1;
}

void	color_exit_reset(int key, t_fract *fract)
{
	if (key == 53)
		ft_exit(NULL);
	else if (key == 15)
		set_colors(fract);
	else if (key == 1)
		set_(fract);
	else if (key == 71)
		fract->colors.red.frequenc += 0.007;
	else if (key == 86)
		fract->colors.red.phase += 1;
	else if (key == 89)
		fract->colors.red.frequenc -= 0.007;
	else if (key == 83)
		fract->colors.red.phase -= 1;
	else if (key == 106)
		fract->colors.red.sign *= -1;
	else
		green_and_blue(key, fract);
}

int		key_controls(int key, t_fract *fract)
{
	if (key == 35)
		bonus_win(fract);
	else if (key == 37)
		return (legend(fract));
	else if (key == 69)
		fract->zoom += fract->zoom / 2;
	else if (key == 78 && fract->zoom > 0)
		fract->zoom -= fract->zoom / 2;
	else if (key == 115)
		fract->max_iters -= 50;
	else if (key == 119)
		fract->max_iters += 50;
	else if (key == 123)
		fract->move_x -= 20 / fract->zoom;
	else if (key == 124)
		fract->move_x += 20 / fract->zoom;
	else if (key == 125)
		fract->move_y += 20 / fract->zoom;
	else if (key == 126)
		fract->move_y -= 20 / fract->zoom;
	else
		color_exit_reset(key, fract);
	redraw(fract);
	return (1);
}
