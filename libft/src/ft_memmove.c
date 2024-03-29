/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:38:57 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/10 17:24:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the destination is less than the source, copy the source to the 
 * destination, otherwise copy the source to the destination in reverse
 * 
 * @param dst This is the pointer to the destination array where the content is
 * to be copied, type-casted to a void*.
 * @param src The source string.
 * @param len the number of bytes to copy
 * 
 * @return A pointer to the destination string. 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	char			*lastd;
	const char		*lasts;

	d = dst;
	s = src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if (dst == 0 && src == 0)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
