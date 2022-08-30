/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:43:09 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/17 19:40:38 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_ilen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_recurse(int num, int len, char **s)
{
	if (num > -10)
		(*s)[len] = '0' - num;
	else
	{
		ft_itoa_recurse(num / 10, len - 1, s);
		(*s)[len] = '0' - num % 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		kol;

	kol = ft_ilen(n);
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *) malloc (sizeof (char) * (kol + 1));
	if (!s)
		return (0);
	if (n > 0)
		n = -n;
	else
		s[0] = '-';
	ft_itoa_recurse(n, kol - 1, &s);
	s[kol] = 0;
	return (s);
}
