/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:48:50 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/15 17:47:38 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	char	*d_ptr;
	char	*s_ptr;
	int		delta;

	if (dest < src)
	{
		d_ptr = (char *)dest;
		s_ptr = (char *)src;
		delta = 1;
	}
	else if (dest > src)
	{
		d_ptr = (char *)(dest) + n - 1;
		s_ptr = (char *)src + n - 1;
		delta = -1;
	}
	else
		return (dest);
	while (n--)
	{
		*d_ptr = *s_ptr;
		d_ptr += delta;
		s_ptr += delta;
	}
	return (dest);
}
