/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:58:11 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:58:13 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	create_color(int red, int green, int blue)
{
	int color;

	color = 0;
	color += RED(red);
	color += GREEN(green);
	color += BLUE(blue);
	return (color);
}

int	create_color_c(float i, t_fract fract)
{
	int color;

	color = (int)i << 24;
	color += RED(fract.colors.red.sign * sin(fract.colors.red.frequenc
							* i + fract.colors.red.phase) * 230 + 25);
	color += GREEN(fract.colors.green.sign * sin(fract.colors.green.frequenc
							* i + fract.colors.green.phase) * 230 + 25);
	color += BLUE(fract.colors.blue.sign * sin(fract.colors.blue.frequenc
							* i + fract.colors.blue.phase) * 230 + 25);
	return (color);
}
