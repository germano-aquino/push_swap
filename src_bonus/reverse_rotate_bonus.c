/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:02:57 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/02 22:16:12 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

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
}
