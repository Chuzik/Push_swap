/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:17:35 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 18:19:33 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;

	src = (char *)s;
	while (n)
	{
		if ((unsigned char)*src == (unsigned char)c)
			return ((char *)src);
		src++;
		n--;
	}
	return (0);
}
