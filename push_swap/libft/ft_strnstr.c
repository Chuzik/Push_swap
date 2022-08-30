/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:07:44 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/15 15:27:16 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;
	size_t	d;

	j = 0;
	if (*needle == '\0' || !*needle)
		return ((char *)haystack);
	d = ft_strlen(needle);
	while (haystack[j] != '\0' && haystack != 0 && (j + d) <= len)
	{
		if (ft_strncmp(&haystack[j], needle, d) == 0)
			return ((char *)&haystack[j]);
		j++;
	}
	return (0);
}
