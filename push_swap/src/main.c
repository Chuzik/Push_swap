/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:58:47 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 18:02:33 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	errors(char *m)
{
	int	i;

	i = 12;
	while (m[i])
	{
		if (!ft_isdigit(m[i]) && m[i] != ' ' && m[i] != '-')
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	check_sort(char **m)
{
	int	i;

	i = 1;
	while (m[i])
	{
		if (ft_atoi(m[i - 1]) > ft_atoi(m[i]))
			return (0);
		i++;
	}
	return (1);
}

int	errors_double(char **mm)
{
	int	i;
	int	j;

	i = 1;
	while (mm[i])
	{
		j = 1;
		while (mm[j])
		{
			if (ft_atoi(mm[j]) == ft_atoi(mm[i]) && i != j)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char	*m;
	int		i;
	char	**mm;

	(void) argc;
	i = 0;
	proverka(argv);
	m = malloc(1);
	while (argv[i])
	{
		m = ft_strjoin(m, " ");
		m = ft_strjoin(m, argv[i++]);
	}
	errors(m);
	mm = ft_split(m, ' ');
	free(m);
	i = errors_double(mm);
	if (i > 1 && check_sort(&mm[1]))
		exit(EXIT_SUCCESS);
	if (i > 2)
		push_swap(mm, i);
	free_mat(mm);
	return (0);
}
