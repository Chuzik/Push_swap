/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:58:27 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 09:58:31 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	transfer_from_b(t_stack **stack_a, t_stack **stack_b, int argc, int *m)
{
	int		median;

	median = (argc - 2) / 2;
	while ((*stack_a)->next->next != NULL && median != 0)
	{
		if ((*stack_a)->content != m[0] && (*stack_a)->content != m[argc - 2])
			if ((*stack_a)->content >= m[median])
				pb(&(*stack_a), &(*stack_b));
		else
		{
			pb(&(*stack_a), &(*stack_b));
			rb(&(*stack_b));
		}
		else
			ra(&(*stack_a));
	}
	if (median != 0 && (*stack_a)->content < (*stack_a)->next->content)
		sa(&(*stack_a));
}

void	transfer_from_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->content < (*stack_b)->content)
	{
		while ((*stack_a)->content < (*stack_b)->content)
			ra(&(*stack_a));
		pa(&(*stack_a), &(*stack_b));
	}
	else
	{
		if ((lstlast(*stack_a))->content < (*stack_b)->content)
			pa(&(*stack_a), &(*stack_b));
		else
		{
			while ((lstlast(*stack_a))->content > (*stack_b)->content)
				rra(&(*stack_a));
			pa(&(*stack_a), &(*stack_b));
		}
	}
}

void	ft_operations(t_stack **stack_a, t_stack **stack_b, int argc, int *m)
{
	transfer_from_b(&(*stack_a), &(*stack_b), argc, &m[0]);
	while (*stack_b)
	{
		ft_r_up_down(&(*stack_b));
		ft_stack_a(&(*stack_a), &(*stack_b));
		while (sum_r_ab(*stack_b)->content != (*stack_b)->content)
		{
			if (sum_r_ab(*stack_b)->up_b == 1)
				rb(&(*stack_b));
			else
				rrb(&(*stack_b));
		}
		transfer_from_a(&(*stack_a), &(*stack_b));
	}
	while ((*stack_a)->content != m[0])
		ra(&(*stack_a));
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack)->next)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*stack);
}

void	push_swap(char **argv, int argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*m;

	stack_b = NULL;
	stack_a = NULL;
	m = malloc(sizeof(int) * (argc - 1));
	get_start_list(&stack_a, argv);
	get_start_array(&m[0], argv);
	get_array_sort(&m[0], argc - 1);
	if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 6)
		sort_five(&stack_a, &stack_b, m);
	else
		ft_operations(&stack_a, &stack_b, argc, m);
	free_stack(&stack_a);
	free(stack_b);
	free(m);
}
