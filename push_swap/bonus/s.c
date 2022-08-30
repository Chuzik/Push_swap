/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:12 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 16:47:27 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack **stack)
{
	t_stack	*list_1;
	t_stack	*list_2;

	if (!(*stack))
		return ;
	if ((*stack)->next)
	{
		list_1 = *stack;
		list_2 = list_1->next;
		list_1->next = (*stack)->next->next;
		list_2->next = list_1;
		*stack = list_2;
	}
}

void	sa(t_stack **stack)
{
	swap(stack);
}

void	sb(t_stack **stack)
{
	swap(stack);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
