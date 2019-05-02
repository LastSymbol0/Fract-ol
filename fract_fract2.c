/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fract2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:32:41 by aillia            #+#    #+#             */
/*   Updated: 2019/04/26 12:32:43 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandel_tricorn(t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	c;
	t_complex	tmp;
	double		r_tmp;

	tmp.i = 0;
	tmp.r = 0;
	c = create_complex(x, y, fract, 0);
	// c.r = fract->julia.r;
	// c.i = fract->julia.i;
	// c.r = -0.7;
	// c.i = 0.27015;
	i = -1;
	while (++i < fract->max_iters && CARDIOID < 4)
	{
		r_tmp = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		tmp.i = tmp.r * tmp.i * 2 + c.i;
		tmp.r = -r_tmp;
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
	if (fract->fdf > 0)
		write_to_file(fract, y, i);
}

void	mandel_5th(t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	c;
	t_complex	tmp;
	double		r_tmp;

	tmp.i = 0;
	tmp.r = 0;
	c = create_complex(x, y, fract, 0);
	// c.r = fract->julia.r;1
	// c.i = fract->julia.i;
	// c.r = -0.7;
	// c.i = 0.27015;
	i = -1;
	while (++i < fract->max_iters && CARDIOID < 4)
	{
		r_tmp = pow(tmp.r, 5) - 10 * pow(tmp.r, 3) * pow(tmp.i, 2) + 5 * tmp.r * pow(tmp.i, 4) + c.r;
		tmp.i = 5 * pow(tmp.r, 4) * tmp.i - 10 * pow(tmp.r, 2) * pow(tmp.i, 3) + pow(tmp.i, 5) + c.i;
		tmp.r = r_tmp;
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
	if (fract->fdf > 0)
		write_to_file(fract, y, i);
}

void	mandel_5th_slim(t_fract *fract, int x, int y)
{
	int			i;
	double		continuos_i;
	t_complex	c;
	t_complex	tmp;
	double		r_tmp;

	tmp.i = 0;
	tmp.r = 0;
	c = create_complex(x, y, fract, 0);
	// c.r = fract->julia.r;1
	// c.i = fract->julia.i;
	// c.r = -0.7;
	// c.i = 0.27015;
	i = -1;
	while (++i < fract->max_iters && CARDIOID < 4)
	{
		r_tmp = pow(tmp.r, 5) - 10 * pow(tmp.r, 3) * pow(tmp.i, 2) + 5 * tmp.r * pow(tmp.i, 4) + c.r;
		tmp.i = 5 * pow(tmp.r, 4) * tmp.i - 10 * pow(tmp.r, 2) * pow(tmp.i, 3) + pow(tmp.i, 5) + c.i;
		tmp.r = -r_tmp;
	}
	continuos_i = i + 1 - (log(2) / sqrt(c.r * c.r + c.i * c.i)) / log(2);
	pixel_put(fract, x, y, create_color_c(continuos_i, *fract));
	if (fract->iso == 1)
		pixel_put_iso(fract, x, y, i);
	if (fract->fdf > 0)
		write_to_file(fract, y, i);
}
