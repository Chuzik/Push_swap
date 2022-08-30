/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:53:22 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/15 19:00:31 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (*dst)
	{
		dst++;
		dstsize--;
	}
	if (dstsize)
	{
		while (dstsize-- - 1)
		{
			*dst = *src;
			if (!(*dst))
				return (len_dst + len_src);
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (len_dst + len_src);
}
