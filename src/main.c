/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:09 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 00:26:38 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_free(t_stacks *stack)
{
	t_node	*iter;
	t_node	*temp;

	iter = stack->a.head;
	while (stack->a.size != 0)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
		stack->a.size -= 1;
	}
	iter = stack->b.head;
	while (stack->b.size != 0)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
		stack->b.size -= 1;
	}
}

void	ft_exit(t_stacks *stack, int err)
{
	if (stack != NULL)
		ft_free(stack);
	if (err)
	{
		ft_printf("Error\n");
		exit(1);
	}
	else
		exit(0);
}

void	ft_init(t_stacks *stacks)
{
	stacks->a.head = NULL;
	stacks->a.tail = NULL;
	stacks->a.size = 0;
	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.size = 0;
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	ft_init(&stacks);
	if (get_data(argc, argv, &stacks) == -1)
		ft_exit(&stacks, 1);
	if (stack_is_not_sorted(&stacks))
	{
		if (stacks.a.size < 10)
			sort_little(&stacks);
		else
			wheel_algorithm(&stacks);
	}
	ft_exit(&stacks, 0);
	return (0);
}
