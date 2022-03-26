/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:35:50 by snair             #+#    #+#             */
/*   Updated: 2021/06/25 09:39:59 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;
	size_t			i;

	i = 0;
	c_s = (unsigned char *)s;
	while (i < n)
	{
		if (c_s[i] == (unsigned char)c)
			return (&c_s[i]);
		i++;
	}
	return (NULL);
}
