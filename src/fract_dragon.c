/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_dragon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:59:56 by aillia            #+#    #+#             */
/*   Updated: 2019/04/26 17:00:00 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

t_line	create_line(int x0, int y0, int x1, int y1)
{
	t_line line;

	line.start.x = x0;
	line.start.y = y0;
	line.end.x = x1;
	line.end.y = y1;
	return (line);
}

void	recurs_dragon(t_fract *fract, int max_iters, t_line line, double angle)
{
	int		x;
	int		y;

	if (max_iters == 0)
		put_line(line, *fract);
	else
	{
		if (fract->colors.blue.sign == 1)
			put_line(line, *fract);
		x = cos(angle) * ((line.end.x - line.start.x) *
		cos(angle) - (line.end.y - line.start.y) * sin(angle)) + line.start.x;
		y = cos(angle) * ((line.end.x - line.start.x) *
		sin(angle) + (line.end.y - line.start.y) * cos(angle)) + line.start.y;
		recurs_dragon(fract, max_iters - 1, create_line(line.start.x,
		line.start.y, x, y), angle * fract->colors.red.sign + fract->julia.r);
		recurs_dragon(fract, max_iters - 1, create_line(x, y, line.end.x,
			line.end.y), angle * fract->colors.green.sign + fract->julia.i);
	}
}

void	dragon(t_fract *fract)
{
	t_line start_line;

	mlx_clear_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr);
	ft_bzero(fract->mlx->img_ptr,
		fract->mlx->width * fract->mlx->height * sizeof(int));
	start_line = create_line(fract->mlx->width / 2, 250, fract->mlx->width / 2,
		fract->mlx->height - 100);
	if (12 + fract->max_iters / 50 < 0)
		return ;
	recurs_dragon(fract, 12 + fract->max_iters / 50, start_line,
		0.78539816339);
	mlx_put_image_to_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr,
												fract->mlx->img, 0, 0);
}
