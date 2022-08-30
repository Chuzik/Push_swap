/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:07 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 16:51:50 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*list_1;

	if (!(*stack))
		return ;
	if ((*stack)->next)
	{
		list_1 = (lstlast(*stack));
		lstlast_1(*stack)->next = NULL;
		list_1->next = *stack;
		*stack = list_1;
	}
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	rotate(stack_b);
}
