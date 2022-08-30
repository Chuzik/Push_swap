/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:59:34 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 09:59:35 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lstsize(t_stack *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}

void	if_ch_1(t_stack **list, int i, int ch)
{
	if (ch == 1)
	{
		(*list)->r_b = i;
		(*list)->up_b = 1;
		*list = (*list)->next;
	}
}

void	ft_r_up_down(t_stack **stack_b)
{
	t_stack	*list;
	int		i;
	int		median;
	int		ch;

	i = 0;
	list = *stack_b;
	median = lstsize(list) / 2;
	ch = lstsize(list) % 2;
	while (i < median)
	{
		list->r_b = i++;
		list->up_b = 1;
		list = (list)->next;
	}
	if_ch_1(&list, i, ch);
	i--;
	while (i >= 0)
	{
		list->r_b = i--;
		list->up_b = 0;
		list = (list)->next;
	}
}

void	count_down(t_stack **list_a, t_stack **list_b, int *i)
{
	while ((*list_a)->content > (*list_b)->content)
		*list_a = (*list_a)->next;
	while ((*list_a)->content < (*list_b)->content)
		if ((*list_a)->next)
			*list_a = (*list_a)->next;
	else
		return ;
	while (*list_a)
	{
		(*i)++;
		*list_a = (*list_a)->next;
	}
}

void	ft_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		i;

	list_a = *stack_a;
	list_b = *stack_b;
	while (list_b)
	{
		i = 0;
		list_a = *stack_a;
		if (list_a->content < list_b->content)
		{
			while (list_a && list_a->content < list_b->content)
			{
				i++;
				list_a = (list_a)->next;
			}
		}
		else
		{
			count_down(&list_a, &list_b, &i);
		}
		list_b->r_a = i;
		list_b = list_b->next;
	}
}
