/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:45:47 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/09 12:10:44 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_two(t_stack *stack, char **args, char *mess)
{
	int	i;

	i = 0;
	free(stack);
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
	printf("%s", mess);
	exit(1);
}

int	ft_atoi(char *str, t_stack *node, char **args)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			ft_error_two(node, args, "Error\nLimits reached\n");
	}
	if (str[i] || (sign == -1 && i == 1) || i == 0)
		ft_error_two(node, args, "Error\nConvert in int\n");
	return (result * sign);
}

t_stack	*add_box(t_stack *val, int nb)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->value = nb;
		tmp->next = val;
	}
	return (tmp);
}

void	check_two_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	char	**args;

	args = NULL;
	i = 0;
	if (argc == 2)
	{
		i = 0;
		args = ft_split(argv[1], ' ');
		if (!args || !args[i])
		{
			free(args);
			ft_err(NULL, NULL, -1, "Error\nEmpty args\n");
		}
		while (args[i])
			i++;
		while (--i >= 0)
			*stack = add_box(*stack, ft_atoi(args[i], *stack, args));
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args[i]);
		free(args);
		ft_err(*stack, NULL, is_double(*stack), "Error\nSame number\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		check_two_args(argc, argv, &stack_a);
		ft_sort(&stack_a, &stack_b);
	}
	else
	{
		while (--argc >= 1)
			stack_a = add_box(stack_a, ft_atoi(argv[argc], stack_a, NULL));
		ft_err(stack_a, stack_b, is_double(stack_a), "Error\nSame number\n");
		ft_sort(&stack_a, &stack_b);
	}
	free_stack_a(stack_a);
	return (0);
}
