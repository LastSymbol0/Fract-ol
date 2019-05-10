/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:03:35 by aillia            #+#    #+#             */
/*   Updated: 2019/04/25 15:03:38 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

void		fdf(t_fract *fract)
{
	create_file(fract);
	mlx_clear_window(fract->mlx->mlx_ptr, fract->mlx->win_ptr);
	if (fract->iso == 1)
		mlx_clear_window(fract->mlx->mlx_ptr, fract->mlx->bonus_win_ptr);
	fract->pthread_y_start = 0;
	fract->pthread_y_end = fract->mlx->height;
	pixels(fract);
	close(fract->fdf);
	fract->fdf = 0;
}

static char	*ft_strjoin_upd(char *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (r == NULL)
		return (NULL);
	while (s1[j] != '\0')
		r[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	free(s1);
	s1 = NULL;
	return (r);
}

static char	*ft_name_create(char *pre)
{
	int		i;
	char	*name;
	char	*time_s;
	time_t	cur_time;

	cur_time = time(NULL);
	time_s = ctime(&cur_time);
	name = ft_strnew(ft_strlen(time_s) + 16);
	i = -1;
	while (++i < 11)
		name[i] = pre[i];
	while (time_s[i])
	{
		name[i] = time_s[i];
		i++;
	}
	return (ft_strjoin_upd(name, ".fdf"));
}

void		create_file(t_fract *fract)
{
	int		fd;
	char	*name;

	name = ft_name_create("./fdf_maps/");
	fd = creat(name, 0644);
	free(name);
	fract->fdf = fd;
}

void		write_to_file(t_fract *fract, int y, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (y > fract->line)
		write(fract->fdf, "\n", 1);
	write(fract->fdf, s, ft_strlen(s));
	free(s);
	write(fract->fdf, " ", 1);
	fract->line = y;
}
