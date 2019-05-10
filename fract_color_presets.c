/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_color_presets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:20:33 by aillia            #+#    #+#             */
/*   Updated: 2019/05/10 13:20:36 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

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
	fract->colors.green.frequenc = -0.228;
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
