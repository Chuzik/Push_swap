/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stack_and_sum_r_ab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:39 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 18:00:44 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	write_stack(t_stack *stack)
{
	write(1, "\n\n\n", 3);
	if (stack == NULL)
	{
		write(1, "NULL\n", 5);
		return ;
	}
	while (stack->next)
	{
		write(1, ft_itoa(stack->content), ft_strlen(ft_itoa(stack->content)));
		write(1, "   ", 3);
		write(1, ft_itoa(stack->r_b), ft_strlen(ft_itoa(stack->r_b)));
		write(1, "   ", 3);
		write(1, ft_itoa(stack->r_a), ft_strlen(ft_itoa(stack->r_a)));
		write(1, "\n", 1);
		stack = stack->next;
	}
	write(1, ft_itoa(stack->content), ft_strlen(ft_itoa(stack->content)));
	write(1, "\n", 1);
}

t_stack	*sum_r_ab(t_stack *stack_b)
{
	t_stack	*list;

	list = stack_b;
	while (stack_b)
	{
		if ((list->r_a + list->r_b) > (stack_b->r_a + stack_b->r_b))
			list = stack_b;
		stack_b = stack_b->next;
	}
	return (list);
}

void	proverka(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(ft_strtrim(argv[i], " ")) == 0)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
