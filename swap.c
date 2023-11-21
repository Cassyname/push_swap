/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:57:50 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/03 14:35:59 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	if (!(*stack_a))
		return (0);
	f = *stack_a;
	s = f->next;
	*stack_a = s;
	if (s->next)
		t = s->next;
	else
		t = NULL;
	f->next = t;
	s->next = f;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_stack **stack_b)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	if (!(*stack_b))
		return (0);
	f = *stack_b;
	s = f->next;
	*stack_b = s;
	if (s->next)
		t = s->next;
	else
		t = NULL;
	f->next = t;
	s->next = f;
	ft_printf("sb\n");
	return (0);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
