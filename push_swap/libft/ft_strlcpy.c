/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:57:06 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/13 08:49:27 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t size)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (size != 0)
	{
		while (size - 1)
		{
			*d = *s;
			if (!(*d))
				return (ft_strlen(src));
			d++;
			s++;
			size--;
		}
		*d++ = '\0';
	}
	return (ft_strlen(src));
}
