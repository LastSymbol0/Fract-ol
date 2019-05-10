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

#include "../fract.h"

void	route(int x, int y, t_fract *fract)
{
	if (fract->type == 1)
		mandel(create_complex(x, y, fract, 1), fract, x, y);
	else if (fract->type == 2)
		julia(fract, x, y);
	else if (fract->type == 3)
		newton(fract, x, y);
	else if (fract->type == 4)
		mandel_5th(fract, x, y);
	else if (fract->type == 5)
		mandel_5th_slim(fract, x, y);
	else if (fract->type == 6)
		mandel_tricorn(fract, x, y);
}

void	*pixels(void *param)
{
	int		x;
	int		y;
	t_fract	*fract;

	fract = (t_fract *)param;
	y = fract->pthread_y_start - 1;
	while (++y <= fract->pthread_y_end)
	{
		x = -1;
		while (++x <= fract->mlx->width)
		{
			route(x, y, fract);
		}
	}
	return (NULL);
}

void	draw(t_fract *fract)
{
	int		i;
	t_fract fract_copy[4];

	fract_copy[0] = *fract;
	fract_copy[1] = *fract;
	fract_copy[2] = *fract;
	fract_copy[3] = *fract;
	if (fract->iso == 1)
		ft_bzero(fract->mlx->bonus_img_ptr,
			fract->mlx->width * fract->mlx->height * sizeof(int));
	i = -1;
	while (++i < 4)
	{
		fract_copy[i].pthread_y_start = fract_copy[i].mlx->height / 4 * i;
		fract_copy[i].pthread_y_end = fract_copy[i].mlx->height / 4 * (i + 1);
		pthread_create(&(fract->pthread_id[i]), NULL, pixels, &fract_copy[i]);
	}
	while (--i >= 0)
		pthread_join((fract->pthread_id[i]), NULL);
	mlx_put_image_to_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr,
												fract->mlx->img, 0, 0);
	if (fract->iso == 1)
		mlx_put_image_to_window(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr,
												fract->mlx->bonus_img, 0, 0);
}

int		multi_window_checker(int ac, char **av, void *mlx)
{
	int		i;
	int		c;
	int		win_s;
	short	type;

	i = 0;
	c = 0;
	type = 0;
	while (++i < ac)
	{
		if ((type = define_type(av[i])) == 0)
			break ;
		else
		{
			if (i + 1 < ac && ft_isdigit(av[i + 1][0]))
				win_s = ft_atoi(av[++i]);
			c = go(fract_creator(type, win_s, mlx));
		}
		win_s = 1;
	}
	if (c == 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	void	*mlx;

	mlx = mlx_init();
	if (ac < 2 || ac > 15)
		usage();
	else if ((multi_window_checker(ac, av, mlx)) == 1)
		mlx_loop(mlx);
	else
		usage();
	return (0);
}
