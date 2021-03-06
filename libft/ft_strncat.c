/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:17:22 by aillia            #+#    #+#             */
/*   Updated: 2018/10/27 21:24:34 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	j;
	int		i;

	i = 0;
	j = -1;
	while (dst[i] != '\0')
		i++;
	while (src[++j] != '\0' && j < n)
		dst[i++] = src[j];
	dst[i] = '\0';
	return (dst);
}
