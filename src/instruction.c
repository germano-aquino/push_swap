/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:12:59 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/27 23:07:41 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	inst_left_receive_right(t_instruction *a, t_instruction *b)
{
	a->rot_a = b->rot_a;
	a->rot_b = b->rot_b;
	a->total = b->total;
}

int	get_total_number_instructions(t_instruction inst)
{
	if (inst.rot_a * inst.rot_b == 0)
		return (mod(inst.rot_a + inst.rot_b));
	else if (inst.rot_a * inst.rot_b < 0)
		return (mod(inst.rot_a) + mod(inst.rot_b));
	else
		return (max(inst.rot_a, inst.rot_b));
}

void	rotate_multiple_times(t_stacks *stacks, int rotate_amount, \
	t_instruction *inst, int flag)
{
	while (rotate_amount)
	{
		if (inst->rot_a > 0 || inst->rot_b > 0)
		{
			rotate_stacks(stacks, flag);
			if (flag & RA)
				inst->rot_a -= 1;
			if (flag & RB)
				inst->rot_b -= 1;
		}
		else
		{
			reverse_rotate_stacks(stacks, flag);
			if (flag & RRA)
				inst->rot_a += 1;
			if (flag & RRB)
				inst->rot_b += 1;
		}
		rotate_amount--;
	}
}
