/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_color_presets2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:20:44 by aillia            #+#    #+#             */
/*   Updated: 2019/05/10 13:25:03 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

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
