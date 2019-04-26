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

int		mouse_move(int x, int y, t_fract *fract)
{
	if ((fract->type == 2 || fract->type == 4) && fract->julia_move == 1)
	{
		// printf("x: %d\ty:%d\n", x, y);
		fract->julia.r = (float)x / (float)(2500) * 2 - 1;
		fract->julia.i = (float)y / (float)(1400) * 2 - 1; 
		redraw(fract);
	}
	return (1);
}

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
		set_colors_grey(fract);
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

void	info(t_fract *fract)
{
	printf("color:\n\tred:\t%f\n\t\t%d\n\t\t%d\n\n", fract->colors.red.frequenc, fract->colors.red.phase, fract->colors.red.sign);
	printf("\tgreen:\t%f\n\t\t%d\n\t\t%d\n\n", fract->colors.green.frequenc, fract->colors.green.phase, fract->colors.green.sign);
	printf("\tblue:\t%f\n\t\t%d\n\t\t%d\n\n", fract->colors.blue.frequenc, fract->colors.blue.phase, fract->colors.blue.sign);


}

int		key_controls(int key, t_fract *fract)
{
	if (key == 3)
		fdf(fract);
	if (key == 46)
		fract->julia_move = -fract->julia_move;	
	if (key == 18)
		set_colors_grey(fract);
	if (key == 19)
		set_colors_dark_cyan(fract);
	if (key == 20)
		set_colors_psyho_barbie(fract);
	if (key == 21)
		set_colors_purple_lemon(fract);
	if (key == 22)
		set_colors_red_n_yellow(fract);
	if (key == 23)
		set_colors_psyho_purple(fract);
	if (key == 24)
		set_colors_light_cyan(fract);
	if (key == 25)
		set_colors_hard_shit(fract);
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
