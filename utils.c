/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:59:48 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/03 14:59:23 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_b(t_stack *stack_b)
{
	t_stack	*tmp;

	while (stack_b)
	{
		tmp = stack_b;
		stack_b = tmp->next;
		free(tmp);
	}
}

void	free_stack_a(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = tmp->next;
		free(tmp);
	}
}

void	ft_err(t_stack *stack_a, t_stack *stack_b, int res, char *error)
{
	if (res < 0)
	{
		free_stack_a(stack_a);
		free_stack_b(stack_b);
		ft_printf("%s", error);
		exit(1);
	}
}

int	check_sort(t_stack *stack_a)
{
	t_stack	*tmp;

	if (stack_a)
	{
		while (stack_a->next)
		{
			tmp = stack_a->next;
			while (tmp)
			{
				if (stack_a->value > tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			stack_a = stack_a->next;
		}
	}
	else
		return (-1);
	return (0);
}

int	is_double(t_stack *box)
{
	t_stack	*tmp;

	tmp = NULL;
	if (box)
	{
		while (box->next)
		{
			tmp = box->next;
			while (tmp)
			{
				if (box->value == tmp->value)
					return (-1);
				tmp = tmp->next;
			}
			box = box->next;
		}
	}
	return (0);
}
