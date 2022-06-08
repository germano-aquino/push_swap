/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:22:47 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/07 23:11:05 by grenato-         ###   ########.fr       */
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

void	ft_free_char_ptr(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int	stack_is_not_sorted(t_stacks *stacks)
{
	t_node	*iter;
	int		i;

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
