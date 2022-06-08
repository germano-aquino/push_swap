/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:14:25 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/07 22:24:02 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_is_not_sorted(t_stacks *stacks)
{
	t_node	*iter;
	int		i;

	iter = stacks->a.head;
	i = 0;
	if (stacks->b.head != NULL)
		return (1);
	while (i < stacks->a.size)
	{
		if (i != iter->index)
			return (1);
		i++;
		iter = iter->next;
	}
	return (0);
}

void	copy_stack(t_stack *new, t_stack *old)
{
	int		i;
	t_node	*iter;
	t_node	*node;
	t_tree	*tree;

	iter = old->head;
	i = -1;
	tree = NULL;
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	while (++i < old->size)
	{
		node = add_node_in_stack_tail(new, iter->data);
		tree = push_tree(tree, &node);
		iter = iter->next;
	}
	i = 0;
	set_nodes_index(&tree, &i);
}

void	free_stack(t_stack *stack)
{
	t_node	*iter;
	t_node	*temp;

	iter = stack->head;
	while (stack->size)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
		stack->size--;
	}
}
