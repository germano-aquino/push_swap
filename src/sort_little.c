/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:06:56 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 23:19:40 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_2(t_stacks *stacks)
{
	swap_stacks(stacks, SA);
}

void	sort_3(t_stacks *stacks)
{
	t_stack		new;
	t_node		*top;

	copy_stack(&new, &stacks->a);
	top = new.head;
	if (top->index == 2)
	{
		rotate_stacks(stacks, RA);
		if (top->next->index == 1)
			swap_stacks(stacks, RA);
	}
	else if (top->index == 1)
	{
		if (top->next->index == 2)
			reverse_rotate_stacks(stacks, RRA);
		if (top->next->index == 0)
			swap_stacks(stacks, SA);
	}
	else if (top->next->index == 2)
	{
		swap_stacks(stacks, SA);
		rotate_stacks(stacks, RA);
	}
	free_stack(&new);
}

void	sort_little(t_stacks *stacks)
{
	if (stacks->a.size == 2)
		sort_2(stacks);
	else if (stacks->a.size == 3)
		sort_3(stacks);
	else
	{
		while (stacks->a.size > 3)
		{
			if (stacks->a.head->index && stacks->a.head->index != stacks->max)
				push_stacks(stacks, PB);
			else
				rotate_stacks(stacks, RA);
		}
		sort_3(stacks);
		wheel_algorithm(stacks);
	}
}
