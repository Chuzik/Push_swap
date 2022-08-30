/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:58:28 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/19 15:05:10 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (!m)
		return (0);
	i = 0;
	while (s[i])
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = 0;
	return (m);
}
