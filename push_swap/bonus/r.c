/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:03 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 15:56:52 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*list_1;

	if (!(*stack))
		return ;
	if ((*stack)->next)
	{
		list_1 = *stack;
		*stack = (*stack)->next;
		list_1->next = NULL;
		(lstlast(*stack))->next = list_1;
	}
}

void	ra(t_stack **stack)
{
	rotate(stack);
}

void	rb(t_stack **stack)
{
	rotate(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
