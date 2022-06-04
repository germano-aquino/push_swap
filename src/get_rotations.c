/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:12:23 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/30 01:23:48 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_rotations_to_pb(t_stack *stack, int pivot, \
	int below_or_above, int max)
{
	t_node	*forward;
	t_node	*backward;
	int		i;

	forward = stack->head;
	backward = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		if (forward->index && forward->index != max && \
			forward->index * below_or_above <= below_or_above * pivot)
			return (i);
		if (backward->index && backward->index != max && \
			backward->index * below_or_above <= below_or_above * pivot)
			return (-i);
		forward = forward->next;
		backward = backward->previous;
	}
	return (1);
}

int	get_min_rotations(t_stack *stack, int index)
{
	t_node	*forward;
	t_node	*backward;
	int		i;

	forward = stack->head;
	backward = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		if (index < forward->index && index > forward->previous->index)
			return (i);
		if (index < backward->index && index > backward->previous->index)
			return (-i);
		forward = forward->next;
		backward = backward->previous;
	}
	return (0);
}

int	get_rotation_direction_to_find_number(t_stack *stack, int num)
{
	t_node	*forward;
	t_node	*backward;
	int		i;

	forward = stack->head;
	backward = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		if (forward->index == num)
			return (1);
		if (backward->index == num)
			return (-1);
		forward = forward->next;
		backward = backward->previous;
	}
	return (0);
}
