/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:57:47 by aillia            #+#    #+#             */
/*   Updated: 2019/04/18 16:57:49 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	route(int x, int y, t_fract *fract)
{
	if (fract->type == 1)
		mandel(create_complex(x, y, fract, 1), fract, x, y);
	if (fract->type == 2)
		julia(fract, x, y);
	if (fract->type == 3)
		newton(fract, x, y);
}

void	pixels(t_fract *fract)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= fract->mlx->width)
	{
		y = -1;
		while (++y <= fract->mlx->height)
		{
			route(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr,
												fract->mlx->img, 0, 0);
	if (fract->legend == 0)
		mlx_string_put(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 0, 0, L0);
}

t_fract	*fract_creator(short type, int window_size)
{
	t_fract *fract;

	if (!(fract = (t_fract *)malloc(sizeof(t_fract))))
		ft_err("Error malloc", 1);
	if (window_size > 4 || window_size < 1)
		window_size = 1;
	fract->type = type;
	fract->max_iters = 50;
	set_(fract);
	fract->mlx = set_mlx(fract, 630 * window_size, 420 * window_size);
	set_colors(fract);
	return (fract);
}

t_fract	*multi_window_checker(int ac, char **av)
{
	int		i;
	int		win_s;
	short	type;
	pid_t	pid;

	i = 0;
	type = 0;
	pid = getpid();
	while (++i < ac)
	{
		if ((type = define_type(av[i])) == 0)
			break ;
		else
		{
			if (i + 1 < ac && ft_isdigit(av[i + 1][0]))
				win_s = ft_atoi(av[++i]);
			if (i + 1 < ac)
				fork();
			if (getpid() == pid)
				return (fract_creator(type, win_s));
			pid = getpid();
		}
		win_s = 1;
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_fract *fract;

	if (ac < 2)
		usage();
	else if ((fract = multi_window_checker(ac, av)) != NULL)
	{
		pixels(fract);
		mlx_string_put(fract->mlx->mlx_ptr, fract->mlx->win_ptr, 10, 0, 0, L0);
		mlx_loop(fract->mlx->mlx_ptr);
	}
	else
		usage();
	return (0);
}
