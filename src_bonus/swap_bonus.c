/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:35:59 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 23:27:19 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	swap_stacks(t_stacks *stacks, int which_stack)
{
	t_node	*sec;

	if (which_stack & SA)
	{
		sec = (stacks->a.head)->next;
		if (stacks->a.head == NULL || sec == NULL)
			return ;
		swap(&(stacks->a.head)->data, &sec->data);
	}
	if (which_stack & SB)
	{
		sec = (stacks->b.head)->next;
		if (stacks->b.head == NULL || sec == NULL)
			return ;
		swap(&(stacks->b.head)->data, &sec->data);
	}
}
