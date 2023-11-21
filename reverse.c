/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:38:13 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/09/28 18:25:20 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*last_b;

	if (!(*stack_a))
		return (0);
	last_b = NULL;
	tmp = *stack_a;
	while ((*stack_a)->next)
	{
		if (!(*stack_a)->next->next && !last_b)
			last_b = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	end = *stack_a;
	*stack_a = end;
	end->next = tmp;
	last_b->next = NULL;
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*last_a;

	if (!(*stack_b))
		return (0);
	last_a = NULL;
	tmp = *stack_b;
	while ((*stack_b)->next)
	{
		if (!(*stack_b)->next->next && !last_a)
			last_a = *stack_b;
		*stack_b = (*stack_b)->next;
	}
	end = *stack_b;
	*stack_b = end;
	end->next = tmp;
	last_a->next = NULL;
	ft_printf("rrb\n");
	return (0);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
