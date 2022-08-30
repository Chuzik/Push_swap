/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:58:55 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 09:58:56 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_1;

	if (*stack_b != NULL)
	{
		list_1 = *stack_b;
		if ((*stack_b)->next != NULL)
			*stack_b = (*stack_b)->next;
		else
			*stack_b = NULL;
		list_1->next = *stack_a;
		*stack_a = list_1;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
