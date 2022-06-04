/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:20:53 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/02 22:26:47 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

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

int	get_stack_data(t_stacks *stacks, char *args)
{
	int		i;
	int		nb;
	char	**numbers;

	i = -1;
	numbers = ft_split(args, ' ');
	while (numbers[++i] != NULL)
	{
		if (is_not_a_number(numbers[i]) || out_int_range(numbers[i]))
			return (-1);
		nb = ft_atoi(numbers[i]);
		if (check_number_is_in_stack(&stacks->a, nb))
			return (-1);
		add_node_in_stack_tail(&stacks->a, nb);
	}
	ft_free_2d_char_ptr(&numbers);
	if (receive_push_swap_instructions(stacks))
		return (-1);
	return (1);
}
