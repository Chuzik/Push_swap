/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:27:00 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/14 16:05:34 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*src1;
	char	*src2;

	src1 = (char *)s1;
	src2 = (char *)s2;
	while (n)
	{
		if (*src1 != *src2)
			return ((unsigned char)*src1 - (unsigned char)*src2);
		src1++;
		src2++;
		n--;
	}
	return (0);
}
