/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:18 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 10:00:42 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_start_array(int *m, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		m[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

void	get_array_sort(int *a, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > i)
		{
			if (a[j - 1] > a[j])
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
			j--;
		}
		i++;
	}
}

void	sort_three(t_stack **stack)
{
	int	m[3];

	m[0] = (int)(*stack)->content;
	m[1] = (int)(*stack)->next->content;
	m[2] = (int)(*stack)->next->next->content;
	if (m[0] > m[1] && m[0] > m[2] && m[1] > m[2])
		write(1, "sa\nrra\n", 7);
	else if (m[0] < m[1] && m[0] < m[2] && m[1] > m[2])
		write(1, "sa\nra\n", 6);
	else if (m[0] > m[1] && m[0] < m[2] && m[1] < m[2])
		write(1, "sa\n", 3);
	else if (m[0] < m[1] && m[0] > m[2] && m[1] > m[2])
		write(1, "rra\n", 4);
	else if (m[0] > m[1] && m[0] > m[2] && m[1] < m[2])
		write(1, "ra\n", 3);
}

int	found(t_stack *stack_a, int m)
{
	int	i;

	i = 0;
	while (stack_a->content != m)
	{
		i++;
		stack_a = stack_a->next;
	}
	if (i > 2)
		return (1);
	return (0);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int *m)
{
	int	j;

	j = 0;
	while (j < 2)
	{
		if (found(*stack_a, m[j]))
		{
			while ((*stack_a)->content != m[j])
				rra(stack_a);
		}
		else
		{
			while ((*stack_a)->content != m[j])
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		j++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
