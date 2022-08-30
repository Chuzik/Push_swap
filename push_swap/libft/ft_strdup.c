/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:24:05 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 19:10:03 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*m;
	int		len;

	len = 0;
	len = ft_strlen(s1);
	m = (void *)malloc(sizeof(const char) * (len + 1));
	if (!m)
		return (0);
	ft_memcpy (m, s1, (len + 1));
	return (m);
}
