/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:54:49 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/16 18:00:56 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				r_a;
	int				r_b;
	int				up_b;
}	t_stack;

t_stack	*lstnew(int content);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstlast_1(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	write_stake(t_stack *stack);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ft_r_up_down(t_stack **stack_b);
void	ft_stack_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*sum_r_ab(t_stack *stack_b);
void	transfer_from_b(t_stack **stack_a, t_stack **stack_b, int argc, int *m);
void	transfer_from_a(t_stack **stack_a, t_stack **stack_b);
void	ft_operations(t_stack **stack_a, t_stack **stack_b, int argc, int *m);
void	free_stack(t_stack **stack);
void	push_swap(char **argv, int argc);
void	write_stack(t_stack *stack);
void	get_start_list(t_stack **stack_a, char **argv);
void	get_start_array(int *m, char **argv);
void	get_array_sort(int *a, int size);
void	sort_three(t_stack **stack);
int		found(t_stack *stack_a, int m);
void	sort_five(t_stack **stack_a, t_stack **stack_b, int *m);
t_stack	*sum_r_ab(t_stack *stack_b);
void	read_console_and_sort(t_stack **stack_a, t_stack **stack_b);
void	proverka(char **argv);

#endif