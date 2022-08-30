/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:41:49 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 13:34:14 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*m;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	m = (char *)malloc(sizeof(const char) * (s1_len + s2_len + 1));
	if (!m)
		return (0);
	ft_memcpy (m, s1, s1_len);
	ft_memcpy (&m[s1_len], s2, s2_len);
	m[s1_len + s2_len] = 0;
	free(s1);
	return (m);
}
