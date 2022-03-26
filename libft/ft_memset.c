/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:06:58 by snair             #+#    #+#             */
/*   Updated: 2022/03/22 17:19:38 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*conb;

	i = 0;
	conb = (unsigned char *)b;
	while (i < len)
	{
		conb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
