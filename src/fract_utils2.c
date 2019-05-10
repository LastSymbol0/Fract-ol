/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:59:02 by aillia            #+#    #+#             */
/*   Updated: 2019/05/10 13:59:04 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

t_fract	*fract_creator(short type, int window_size, void *mlx)
{
	t_fract *fract;

	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		ft_err("Error malloc", 1);
	if (window_size > 4 || window_size < 1)
		window_size = 1;
	fract->type = type;
	fract->max_iters = 50;
	set_(fract);
	fract->mlx = set_mlx(fract, 420 * window_size, 420 * window_size, mlx);
	set_colors(fract);
	return (fract);
}

int		go(t_fract *fract)
{
	if (fract->type == 7)
		dragon(fract);
	else
		draw(fract);
	mlx_string_put(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 0, 0, L0);
	return (1);
}
