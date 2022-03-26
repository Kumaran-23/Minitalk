/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:16:11 by snair             #+#    #+#             */
/*   Updated: 2021/07/13 10:17:26 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	i = 0;
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (!c_dst && !c_src)
		return (0);
	if (c_dst > c_src)
	{
		while (len > 0)
		{
			len--;
			c_dst[len] = c_src[len];
		}
	}
	while (i < len)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
