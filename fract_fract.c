/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:49:57 by aillia            #+#    #+#             */
/*   Updated: 2019/04/23 15:49:59 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	julia(t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	tmp;
	t_complex	c;
	double		r_tmp;

	c.r = -0.7;
	c.i = 0.27015;
	tmp = create_complex(x, y, fract, 0);
	i = -1;
	while (++i < fract->max_iters && CARDIOID < 4)
	{
		r_tmp = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		tmp.i = tmp.r * tmp.i + tmp.r * tmp.i + c.i;
		tmp.r = r_tmp;
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
}

void	mandel(t_complex c, t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	tmp;
	double		r_tmp;

	tmp.i = 0;
	tmp.r = 0;
	i = -1;
	while (++i < fract->max_iters && CARDIOID < 4)
	{
		r_tmp = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		tmp.i = tmp.r * tmp.i + tmp.r * tmp.i + c.i;
		tmp.r = r_tmp;
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
}

void	newton(t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	old;
	t_complex	c;
	double		tmp;

	c = create_complex(x, y, fract, 0);
	i = -1;
	tmp = 1;
	while (++i < fract->max_iters && tmp > 0.000001)
	{
		old = c;
		tmp = (c.r * c.r + c.i * c.i) * (c.r * c.r + c.i * c.i);
		c.r = (2 * c.r * tmp + c.r * c.r - c.i * c.i) / (3 * tmp);
		c.i = (2 * c.i * (tmp - old.r)) / (3 * tmp);
		tmp = (c.r - old.r) * (c.r - old.r) + (c.i - old.i) * (c.i - old.i);
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
}
