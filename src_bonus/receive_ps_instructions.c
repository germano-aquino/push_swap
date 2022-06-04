/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_ps_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:15:30 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/02 22:30:07 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	exec_if_valid_instruction(t_stacks *stacks, char *inst, int len)
{
	if (!ft_strncmp(inst, "sa\n", max(len, 3)))
		swap_stacks(stacks, SA);
	else if (!ft_strncmp(inst, "sb\n", max(len, 3)))
		swap_stacks(stacks, SB);
	else if (!ft_strncmp(inst, "ss\n", max(len, 3)))
		swap_stacks(stacks, SS);
	else if (!ft_strncmp(inst, "pa\n", max(len, 3)))
		push_stacks(stacks, PA);
	else if (!ft_strncmp(inst, "pb\n", max(len, 3)))
		push_stacks(stacks, PB);
	else if (!ft_strncmp(inst, "ra\n", max(len, 3)))
		rotate_stacks(stacks, RA);
	else if (!ft_strncmp(inst, "rb\n", max(len, 3)))
		rotate_stacks(stacks, RB);
	else if (!ft_strncmp(inst, "rr\n", max(len, 3)))
		rotate_stacks(stacks, RR);
	else if (!ft_strncmp(inst, "rra\n", max(len, 4)))
		reverse_rotate_stacks(stacks, RRA);
	else if (!ft_strncmp(inst, "rrb\n", max(len, 4)))
		reverse_rotate_stacks(stacks, RRB);
	else if (!ft_strncmp(inst, "rrr\n", max(len, 4)))
		reverse_rotate_stacks(stacks, RRR);
	else
		return (1);
	return (0);
}

int	receive_push_swap_instructions(t_stacks *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, 0);
		if (line)
		{
			if (exec_if_valid_instruction(stacks, line, ft_strlen(line)))
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
