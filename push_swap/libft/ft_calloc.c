/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:17:07 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 18:27:47 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;
	size_t	n;

	n = count * size;
	m = (void *)malloc(count * size);
	if (!m)
		return (0);
	ft_memset (m, '\0', n);
	return (m);
}
