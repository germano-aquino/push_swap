/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:22:47 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 19:32:41 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_free_2d_char_ptr(char ***ptr)
{
	char	**temp;
	int		i;

	temp = *ptr;
	i = 0;
	while (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
		i++;
		temp = (*ptr + i);
	}
	free(*ptr);
	*ptr = NULL;
}

int	stack_is_not_sorted(t_stacks *stacks)
{
	t_node	*iter;
	size_t	i;

	iter = stacks->a.head;
	i = 0;
	if (stacks->b.head != NULL)
		return (1);
	while (i < stacks->a.size - 1)
	{
		if (iter->data > iter->next->data)
			return (1);
		i++;
		iter = iter->next;
	}
	return (0);
}
