/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/02 22:40:34 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "macro_bonus.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}				t_stacks;

typedef struct s_instruction
{
	int	rot_a;
	int	rot_b;
	int	total;
}				t_instruction;


void	add_node_in_stack_tail(t_stack *stack, int nb);
void	display(t_stacks *stacks);
int		get_stack_data(t_stacks *stacks, char *args);
void	swap_stacks(t_stacks *stack, int which_stack);
void	push_stacks(t_stacks *stacks, int which_stack);
void	rotate_stacks(t_stacks *stacks, int which_stack);
void	reverse_rotate_stacks(t_stacks *stacks, int which_stack);
int		stack_is_not_ordered(t_stacks *stacks);
int		receive_push_swap_instructions(t_stacks *stacks);
int		max(int a, int b);
void	ft_free_2d_char_ptr(char ***ptr);
int		stack_is_not_ordered(t_stacks *stacks);

#endif