/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/05/30 00:57:59 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include "macro.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	t_node			*node;
}				t_tree;

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
	int		max;
}				t_stacks;

typedef struct s_instruction
{
	int	rot_a;
	int	rot_b;
	int	total;
}				t_instruction;


t_node	*add_node_in_stack_tail(t_stack *stack, int nb);
void	display(t_stacks *stacks);
int		get_data(int argc, char *argv[], t_stacks *stack);
void	swap_stacks(t_stacks *stack, int which_stack);
void	push_stacks(t_stacks *stacks, int which_stack);
void	rotate_stacks(t_stacks *stacks, int which_stack);
void	reverse_rotate_stacks(t_stacks *stacks, int which_stack);
t_tree	*push_tree(t_tree *tree, t_node **node);
void	set_nodes_index(t_tree **tree, int *index);
void	radix_algorithm(t_stacks *stacks);
void	mid_point_algorithm(t_stacks *stacks);
void	wheel_algorithm(t_stacks *stacks);
int		stack_is_not_ordered(t_stacks *stacks);
int		get_total_number_instructions(t_instruction inst);
void	inst_left_receive_right(t_instruction *a, t_instruction *b);
int		max(int a, int b);
int		min(int a, int b);
int		mod(int a);
void	rotate_multiple_times(t_stacks *stacks, int rotate_amount, \
	t_instruction *inst, int flag);
int		get_rotation_direction_to_find_number(t_stack *stack, int num);
int		get_min_rotations(t_stack *stack, int index);
int		get_rotations_to_pb(t_stack *stack, int pivot, int below_or_above, int max);
void	sort_2(t_stacks *stacks);
void	sort_3(t_stacks *stacks);
void	sort_little(t_stacks *stacks);
void	rotate_to_push(t_stacks *stacks);
void	copy_stack(t_stack *new, t_stack *old);
void	free_stack(t_stack *stack);
#endif