/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:02:57 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/25 01:12:05 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->tail;
	stack->tail = stack->tail->previous;
}

void	reverse_rotate_stacks(t_stacks *stacks, int which_stack)
{
	if (which_stack & RRA)
		reverse_rotate(&stacks->a);
	if (which_stack & RRB)
		reverse_rotate(&stacks->b);
	if (which_stack == RRA)
		ft_printf("rra\n");
	else if (which_stack == RRB)
		ft_printf("rrb\n");
	else if (which_stack == RRR)
		ft_printf("rrr\n");
}
