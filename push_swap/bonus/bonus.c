/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:28:09 by zhizdahr          #+#    #+#             */
/*   Updated: 2022/03/19 13:21:51 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_strjoinchar(char *s1, char c)
{
	char	*output;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (c == '\n')
		output = (char *) malloc((ft_strlen(s1) + 3) * sizeof(char));
	else
		output = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!output)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		output[i++] = s1[j++];
	output[i++] = c;
	output[i] = 0;
	free(s1);
	return (output);
}

void	error_bonus(char *m)
{
	m++;
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	sort(char *m, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(m, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(m, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(m, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(m, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(m, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(m, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(m, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(m, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(m, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(m, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(m, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		error_bonus(m);
}

void	check(t_stack *stack_a, t_stack *stack_b)
{
	int	c;

	if (stack_b)
	{
		write(1, "KO\n", 3);
		exit(EXIT_SUCCESS);
	}
	while (stack_a->next)
	{
		c = stack_a->content;
		if (c > stack_a->next->content)
		{
			write(1, "KO\n", 3);
			exit(EXIT_SUCCESS);
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
}

void	read_console_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	c;
	char	*m;

	m = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			m = ft_strjoinchar(m, c);
			sort(m, stack_a, stack_b);
			free(m);
			m = NULL;
		}
		else
			m = ft_strjoinchar(m, c);
	}
	check(*stack_a, *stack_b);
}
