/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:28:19 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/03 15:37:42 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*copy_a;
	int		i;

	first = *stack_a;
	copy_a = *stack_a;
	i = 0;
	while (*stack_a)
	{
		copy_a = first;
		i = 0;
		while (copy_a)
		{
			if ((*stack_a)->value > copy_a->value)
				i++;
			if (!copy_a->next)
				break ;
			copy_a = copy_a->next;
		}
		(*stack_a)->index = i;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*copy_a;
	int		nb_box;

	nb_box = 0;
	copy_a = *stack_a;
	fill_index(stack_a);
	if (check_sort(*stack_a) == 0)
	{
		free_stack_a((*stack_a));
		exit(1);
	}
	while (copy_a)
	{
		copy_a = copy_a->next;
		nb_box++;
	}
	if (nb_box == 2 && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else if (nb_box == 3)
		three_box(stack_a);
	else if (nb_box > 3 && nb_box < 6)
		four_five_box(stack_a, stack_b);
	else if (nb_box > 5)
		ft_radix(stack_a, stack_b);
}
