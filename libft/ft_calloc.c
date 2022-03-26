/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:17:50 by snair             #+#    #+#             */
/*   Updated: 2021/07/14 14:20:14 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total;

	total = count * size;
	ptr = (char *)malloc(sizeof(void) * total);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
