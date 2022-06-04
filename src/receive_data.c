/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:20:53 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/28 23:11:05 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_not_a_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!i && !(str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i]))
			return (1);
		else if (i && !ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int	out_int_range(char *str)
{
	int	has_signal;

	has_signal = 0;
	if (str[0] == '-' || str[0] == '+')
		has_signal = 1;
	if (ft_strlen(str) > 10 + has_signal)
		return (1);
	else if (ft_strlen(str) < 10 + has_signal)
		return (0);
	else if (!has_signal && (ft_strncmp("2147483647", str, 10) < 0))
		return (1);
	else if (str[0] == '-' && (ft_strncmp("-2147483648", str, 11) < 0))
		return (1);
	else if (str[0] == '+' && (ft_strncmp("+2147483647", str, 11) < 0))
		return (1);
	else
		return (0);
}

int	check_number_is_in_stack(t_stack *stack, int nb)
{
	int		size;
	t_node	*iter;

	iter = stack->head;
	size = stack->size;
	if (iter == NULL)
		return (0);
	else
	{
		while (size)
		{
			if (iter->data == nb)
				return (1);
			iter = iter->next;
			size--;
		}
		return (0);
	}
}

int	get_data(int argc, char *argv[], t_stacks *stacks)
{
	int		i;
	int		nb;
	t_node	*node;
	t_tree	*tree;

	i = 0;
	tree = NULL;
	while (++i < argc)
	{
		if (is_not_a_number(argv[i]) || out_int_range(argv[i]))
			return (-1);
		nb = ft_atoi(argv[i]);
		if (check_number_is_in_stack(&stacks->a, nb))
			return (-1);
		node = add_node_in_stack_tail(&stacks->a, nb);
		tree = push_tree(tree, &node);
	}
	i = 0;
	set_nodes_index(&tree, &i);
	stacks->max = stacks->a.size - 1;
	return (1);
}
