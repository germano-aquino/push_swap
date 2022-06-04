/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:40:29 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/25 01:10:36 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail = stack->head;
	stack->head = stack->head->next;
}

void	rotate_stacks(t_stacks *stacks, int which_stack)
{
	if (which_stack & RA)
		rotate(&stacks->a);
	if (which_stack & RB)
		rotate(&stacks->b);
	if (which_stack == RA)
		ft_printf("ra\n");
	else if (which_stack == RB)
		ft_printf("rb\n");
	else if (which_stack == RR)
		ft_printf("rr\n");
}
