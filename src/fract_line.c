/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:49:37 by aillia            #+#    #+#             */
/*   Updated: 2019/04/26 16:49:39 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

void	swap_p(t_line *line, int *sign, int *sign_z)
{
	t_point tmp;

	tmp = line->end;
	line->end = line->start;
	line->start = tmp;
	*sign = -*sign;
	*sign_z = -*sign_z;
}

void	line_x_bigger(t_line line, int delta_x, int delta_y, t_fract fract)
{
	int error;
	int sign_y;
	int sign_z;

	error = delta_x - delta_y;
	sign_y = line.start.y < line.end.y ? 1 : -1;
	sign_z = line.start.z < line.end.z ? 1 : -1;
	if (line.start.x > line.end.x)
		swap_p(&line, &sign_y, &sign_z);
	pixel_put(&fract, line.start.x, line.start.y, 0xff0000);
	while (line.start.x <= line.end.x)
	{
		pixel_put(&fract, line.start.x, line.start.y,
					0xff0000);
		error -= delta_y;
		if (error < 0)
		{
			line.start.y += sign_y;
			error += delta_x;
			if (line.start.z != line.end.z)
				line.start.z += sign_z;
		}
		line.start.x++;
	}
}

void	line_y_bigger(t_line line, int delta_x, int delta_y, t_fract fract)
{
	int error;
	int sign_x;
	int sign_z;

	error = delta_x - delta_y;
	sign_x = line.start.x < line.end.x ? 1 : -1;
	sign_z = line.start.z < line.end.z ? 1 : -1;
	if (line.start.y > line.end.y)
		swap_p(&line, &sign_x, &sign_z);
	pixel_put(&fract, line.start.x, line.start.y, 0xff0000);
	while (line.start.y <= line.end.y)
	{
		pixel_put(&fract, line.start.x, line.start.y,
					0xff0000);
		error -= delta_x;
		if (error < 0)
		{
			line.start.x += sign_x;
			error += delta_y;
			if (line.start.z != line.end.z)
				line.start.z += sign_z;
		}
		line.start.y++;
	}
}

void	put_line(t_line line, t_fract fract)
{
	int delta_x;
	int delta_y;

	delta_x = abs(line.end.x - line.start.x);
	delta_y = abs(line.end.y - line.start.y);
	if (delta_x > delta_y)
		line_x_bigger(line, delta_x, delta_y, fract);
	else
		line_y_bigger(line, delta_x, delta_y, fract);
}
