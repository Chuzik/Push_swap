/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:07 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 16:00:51 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*list_1;

	if (!(*stack))
		return ;
	list_1 = (lstlast(*stack));
	lstlast_1(*stack)->next = NULL;
	list_1->next = *stack;
	*stack = list_1;
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	rotate(stack_b);
	write(1, "rrr\n", 4);
}
