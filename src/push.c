/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:12:36 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/25 01:17:04 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	out_point(t_stack *out)
{
	if (out->size == 0)
	{
		out->head = NULL;
		out->tail = NULL;
	}
	else
	{
		out->head = out->head->next;
		out->head->previous = out->tail;
		out->tail->next = out->head;
	}
}

void	in_point(t_stack *in, t_node *to_be_pushed)
{
	if (in->size == 1)
	{
		to_be_pushed->next = to_be_pushed;
		to_be_pushed->previous = to_be_pushed;
		in->tail = to_be_pushed;
	}
	else
	{
		to_be_pushed->next = in->head;
		to_be_pushed->previous = in->tail;
		(in->head)->previous = to_be_pushed;
		(in->tail)->next = to_be_pushed;
	}
	in->head = to_be_pushed;
}

void	push(t_stack *in, t_stack *out)
{
	t_node	*to_be_pushed;

	if (out->head == NULL)
		return ;
	out->size -= 1;
	in->size += 1;
	to_be_pushed = out->head;
	out_point(out);
	in_point(in, to_be_pushed);
}

void	push_stacks(t_stacks *stacks, int which_stack)
{
	if (which_stack & PA)
	{
		push(&stacks->a, &stacks->b);
		ft_printf("pa\n");
	}
	if (which_stack & PB)
	{
		push(&stacks->b, &stacks->a);
		ft_printf("pb\n");
	}
}
