/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:16:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 23:26:36 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	add_node_in_stack_tail(t_stack *stack, int nb)
{
	t_node	*last;

	stack->size++;
	if (stack->tail == NULL)
	{
		stack->tail = (t_node *)malloc(sizeof(t_node));
		stack->tail->data = nb;
		stack->tail->next = stack->tail;
		stack->tail->previous = stack->tail;
		stack->head = stack->tail;
	}
	else
	{
		last = (t_node *) malloc(sizeof(t_node));
		stack->tail->next = last;
		stack->head->previous = last;
		last->previous = stack->tail;
		last->data = nb;
		last->next = stack->head;
		stack->tail = last;
	}
}
