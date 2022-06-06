/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:02:35 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 00:43:20 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	parse_halves(t_stacks *stacks)
{
	t_stack			*a;
	t_instruction	inst;
	int				n_elm_below_half;
	int				n_elm_above_half;
	int				pivot;

	a = &stacks->a;
	inst.rot_b = 0;
	pivot = a->size / 2;
	n_elm_below_half = (a->size / 2) - 1;
	n_elm_above_half = (a->size / 2) - 1 + (a->size & 1);
	while (n_elm_above_half)
	{
		inst.rot_a = get_rotations_to_pb(a, pivot, -1, stacks->max);
		rotate_multiple_times(stacks, mod(inst.rot_a), &inst, RA);
		push_stacks(stacks, PB);
		n_elm_above_half--;
	}
	while (n_elm_below_half)
	{
		inst.rot_a = get_rotations_to_pb(a, pivot, 1, stacks->max);
		rotate_multiple_times(stacks, mod(inst.rot_a), &inst, RA);
		push_stacks(stacks, PB);
		n_elm_below_half--;
	}
}

void	check_nodes_in_range(t_stacks *stacks, t_instruction *min, \
	int range, int direction)
{
	t_instruction	new;
	t_node			*iter;
	int				i;

	i = -1;
	iter = stacks->b.head;
	new.rot_b = 0;
	while (++i < range)
	{
		if (direction == 1)
			iter = iter->next;
		else if (direction == -1)
			iter = iter->previous;
		else
			break ;
		new.rot_a = get_min_rotations(&stacks->a, iter->index);
		new.rot_b += direction;
		new.total = get_total_number_instructions(new);
		if (new.total < min->total)
			inst_left_receive_right(min, &new);
	}
}

void	rotate_to_push(t_stacks *stacks)
{
	t_instruction	min_inst;
	int				node_range;

	min_inst.rot_a = get_min_rotations(&stacks->a, stacks->b.head->index);
	min_inst.rot_b = 0;
	min_inst.total = get_total_number_instructions(min_inst);
	node_range = min_inst.total - 1;
	check_nodes_in_range(stacks, &min_inst, node_range, 1);
	check_nodes_in_range(stacks, &min_inst, node_range, -1);
	if (min_inst.rot_a * min_inst.rot_b > 0)
		rotate_multiple_times(stacks, min(min_inst.rot_a, min_inst.rot_b), \
			&min_inst, RR);
	rotate_multiple_times(stacks, mod(min_inst.rot_a), &min_inst, RA);
	rotate_multiple_times(stacks, mod(min_inst.rot_b), &min_inst, RB);
}

void	wheel_algorithm(t_stacks *stacks)
{
	parse_halves(stacks);
	if (stacks->a.head->index == 0)
		rotate_stacks(stacks, RA);
	while (stack_is_not_sorted(stacks))
	{
		if (stacks->b.head == NULL)
		{
			if (get_rotation_direction_to_find_number(&stacks->a, 0) > 0)
				rotate_stacks(stacks, RA);
			else
				reverse_rotate_stacks(stacks, RRA);
		}
		else if (stacks->b.head->index < stacks->a.head->index \
			&& stacks->b.head->index > stacks->a.tail->index)
			push_stacks(stacks, PA);
		else
			rotate_to_push(stacks);
	}
}
