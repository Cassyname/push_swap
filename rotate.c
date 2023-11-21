/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:58:22 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/02 13:28:03 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*up;
	t_stack	*end;

	if (!*stack_a)
		return (0);
	end = NULL;
	tmp = *stack_a;
	up = tmp->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	end = *stack_a;
	end->next = tmp;
	*stack_a = up;
	tmp->next = NULL;
	ft_printf("ra\n");
	return (0);
}

int	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*up;
	t_stack	*end;

	if (!*stack_b)
		return (0);
	end = NULL;
	tmp = *stack_b;
	up = tmp->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	end = *stack_b;
	end->next = tmp;
	*stack_b = up;
	tmp->next = NULL;
	ft_printf("rb\n");
	return (0);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
