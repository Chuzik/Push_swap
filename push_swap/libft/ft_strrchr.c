/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:40:52 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/16 18:22:00 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char	*s, int c)
{
	int	n;

	n = 0;
	while (*s)
	{
		s++;
		n++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	s--;
	while (n)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
		n--;
	}
	return (NULL);
}
