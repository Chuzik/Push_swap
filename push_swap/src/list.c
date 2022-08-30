/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:58:39 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/19 13:15:05 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*lstlast_1(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}

void	get_start_list(t_stack **stack_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		lstadd_back(stack_a, lstnew(ft_atoi(argv[i])));
		i++;
	}
}
