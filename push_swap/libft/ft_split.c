/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:41:48 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/07 20:56:29 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_str_1(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_count(char const	*s, char c)
{
	int	l;
	int	num;

	l = 0;
	num = 0;
	while (s[l])
	{
		if ((s[l] != c && s[l + 1] == c && s[l + 1])
			|| (s[l] != c && !s[l + 1]))
			num++;
		l++;
	}
	return (num);
}

static int	ft_start(char const	*s, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i++] == c)
		l++;
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		num;
	int		i;
	int		l;

	i = -1;
	if (!s)
		return (0);
	num = ft_count(s, c);
	m = malloc((num + 1) * sizeof(char *));
	if (!m)
		return (NULL);
	l = ft_start(s, c);
	while (++i < num)
	{
		m[i] = ft_substr(&s[0], l, ft_strlen_str_1(&s[l], c));
		if (!m[i])
			return (0);
		l += ft_strlen_str_1(&s[l], c);
		while (s[l] == c)
			l++;
	}
	m[i] = 0;
	return (m);
}
