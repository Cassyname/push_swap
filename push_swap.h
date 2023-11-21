/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:35 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/10/04 16:22:13 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>

# define ERROR "error\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* main.c */
int		ft_atoi(char *str, t_stack *node, char **args);
t_stack	*add_box(t_stack *val, int nb);
void	check_two_args(int argc, char **argv, t_stack **stack);
void	ft_error_two(t_stack *stack, char **args, char *mess);
/* push.c */
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
/* rotate.c  */
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* reverse.c  */
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* swap.c  */
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/* radix.c */
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
int		len_stack(t_stack *stack);
/* sorting.c  */
void	fill_index(t_stack **stack_a);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
/* sorting2.c  */
int		min_index(t_stack **stack);
int		max_index(t_stack **stack);
void	three_box(t_stack **stack_a);
void	sort_four_five(t_stack **stack_a, \
		t_stack **stack_b, int pos, int len_a);
void	four_five_box(t_stack **stack_a, t_stack **stack_b);
/* utils.c */
void	free_stack_b(t_stack *stack_b);
void	free_stack_a(t_stack *stack);
void	ft_err(t_stack *stack_a, t_stack *stack_b, int res, char *error);
int		check_sort(t_stack *stack_a);
int		is_double(t_stack *box);
#endif
