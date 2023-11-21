/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:14:57 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/03 13:59:18 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_box(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	f = *stack_a;
	s = f->next;
	t = s->next;
	if (f->value < s->value && s->value < t->value && s->value < t->value)
		return ;
	else if (f->value < s->value && f->value < t->value && s->value > t->value)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (f->value > s->value && f->value < t->value && s->value < t->value)
		sa(stack_a);
	else if (f->value < s->value && f->value > t->value && s->value > t->value)
		rra(stack_a);
	else if (f->value > s->value && f->value > t->value && s->value < t->value)
		ra(stack_a);
	else if (f->value > s->value && f->value > t->value && s->value > t->value)
	{
		ra(stack_a);
		sa(stack_a);
	}
}

int	min_index(t_stack **stack)
{
	t_stack	*first;
	int		i;

	first = *stack;
	i = 0;
	while (*stack)
	{
		if ((*stack)->index == 0)
			break ;
		i++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (i);
}

int	max_index(t_stack **stack)
{
	t_stack	*first;
	int		max;
	int		i;

	first = *stack;
	max = len_stack(*stack);
	i = 0;
	while (*stack)
	{
		if ((*stack)->index == max)
			break ;
		i++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (i);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int pos, int len_a)
{
	int	i;

	i = 0;
	if (pos <= len_a / 2)
	{
		while (i < pos)
		{
			ra(stack_a);
			i++;
		}
	}
	else if (pos > len_a / 2)
	{
		while (i < len_a - pos)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
}

void	four_five_box(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;
	int	pos_min;
	int	pos_max;

	len_stack_a = len_stack(*stack_a);
	pos_min = min_index(stack_a);
	sort_four_five(stack_a, stack_b, pos_min, len_stack_a);
	len_stack_a = len_stack(*stack_a);
	pos_max = max_index(stack_a);
	sort_four_five(stack_a, stack_b, pos_max, len_stack_a);
	len_stack_a = len_stack(*stack_a);
	if (len_stack_a == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	else if (len_stack_a == 3)
		three_box(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
}
