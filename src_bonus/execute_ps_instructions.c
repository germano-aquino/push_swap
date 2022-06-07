/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ps_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:15:30 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/07 00:12:10 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	exec_if_valid_instruction(t_stacks *stacks, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 4))
		swap_stacks(stacks, SA);
	else if (!ft_strncmp(inst, "sb\n", 4))
		swap_stacks(stacks, SB);
	else if (!ft_strncmp(inst, "ss\n", 4))
		swap_stacks(stacks, SS);
	else if (!ft_strncmp(inst, "pa\n", 4))
		push_stacks(stacks, PA);
	else if (!ft_strncmp(inst, "pb\n", 4))
		push_stacks(stacks, PB);
	else if (!ft_strncmp(inst, "ra\n", 4))
		rotate_stacks(stacks, RA);
	else if (!ft_strncmp(inst, "rb\n", 4))
		rotate_stacks(stacks, RB);
	else if (!ft_strncmp(inst, "rr\n", 4))
		rotate_stacks(stacks, RR);
	else if (!ft_strncmp(inst, "rra\n", 5))
		reverse_rotate_stacks(stacks, RRA);
	else if (!ft_strncmp(inst, "rrb\n", 5))
		reverse_rotate_stacks(stacks, RRB);
	else if (!ft_strncmp(inst, "rrr\n", 5))
		reverse_rotate_stacks(stacks, RRR);
	else
		return (1);
	return (0);
}

int	exec_push_swap_instructions(t_stacks *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, 0);
		if (line)
		{
			if (exec_if_valid_instruction(stacks, line))
			{
				free(line);
				line = get_next_line(0, 1);
				return (1);
			}
		}
		else
			break ;
		free(line);
	}
	free(line);
	return (0);
}
