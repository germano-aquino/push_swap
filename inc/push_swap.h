/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/04 18:01:16 by grenato-         ###   ########.fr       */
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

//	FILE: get_rotation.c

/**
 * @brief Get the rotation direction relative to stack's head to find number.
 * 
 * @param stack Stack which will be searched.
 * @param num Target to be found.
 * @return Returns 1 to forward direction -1 to backward direction and
 *  0 if number is not found.
 */
int		get_rotation_direction_to_find_number(t_stack *stack, int num);

/**
 * @brief Get the minimum rotations in stack to find a available position to push
 * index element in stack.
 * 
 * @param stack Stack which will be searched.
 * @param index Element to be pushed.
 * @return Number of rotations. Return is greater than 0 to forward direction
 *  and less than 0 to backward direction.
 */
int		get_min_rotations(t_stack *stack, int index);

/**
 * @brief Get the minimum number of rotations to be done on stack A to find an
 * element other than the extremes that is below or above the pivot.
 * 
 * @param stack Stack A that will be searched.
 * @param pivot Element of comparation.
 * @param below_or_above If value is 1 find first number below pivot, if -1 find
 * first number above pivot otherwise returns 0.
 * @param max Maximum extreme that can not be a possible solution.
 * @return Number of rotations. Return is greater than 0 to forward direction
 *  and less than 0 to backward direction.
 */
int		get_rotations_to_pb(t_stack *stack, int pivot, \
	int below_or_above, int max);

//FILE instruction.c

/**
 * @brief Instruction "a" is populated with instruction "b" values.
 * 
 * @param a Target instruction variable.
 * @param b Source instruction variable.
 */
void	inst_left_receive_right(t_instruction *a, t_instruction *b);

/**
 * @brief Calculates the total number of instructions to be execcuted.
 * 
 * @param inst Instruction variable.
 * @return Total amount of instructions to execute.
 */
int		get_total_number_instructions(t_instruction inst);

/**
 * @brief Rotate the stack multiple times according to the rules
 * in instruction variable.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param rotate_amount Amount of rotation to be made.
 * @param inst Instruction variable which has the rules to rotate.
 * @param flag Flag which indicates if stack A, B or both will be rotated.
 */
void	rotate_multiple_times(t_stacks *stacks, int rotate_amount, \
	t_instruction *inst, int flag);

//FILE node.c

/**
 * @brief Add a node as a new tail in stack.
 * 
 * @param stack Stack which will be added.
 * @param nb Data node.
 * @return Returns the new node created.
 */
t_node	*add_node_in_stack_tail(t_stack *stack, int nb);

//FILE push.c
/**
 * @brief Execute a push operation from a stack to another.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param which_stack Flag which indicates if stack A or B will be pushed.
 */
void	push_stacks(t_stacks *stacks, int which_stack);

/**
 * @brief Execute a push operation from stack "in" to stack "out".
 * 
 * @param in Target stack.
 * @param out Source stack.
 */
void	push(t_stack *in, t_stack *out);

/**
 * @brief Make the redirections on previous and next node's attributes
 * to ensure the "in" stack remains circular.
 * 
 * @param in Target stack.
 * @param to_be_pushed Node to be pushed in "in" stack.
 */
void	in_point(t_stack *in, t_node *to_be_pushed);

/**
 * @brief Make the redirections on previous and next node's attributes
 * to ensure the "out" stack remains circular.
 * 
 * @param out Source stack.
 */
void	out_point(t_stack *out);

//FILE: receive_data.c

/**
 * @brief Get the data from argv matrix and parse to stacks variable.
 * 
 * @param argc Number of parameters parsed as arguments
 * @param argv Arguments
 * @param stacks Variable which contain the stacks A and B.
 * @return Returns -1 if a error occurs otherwise returns 1.
 */
int		get_data(int argc, char *argv[], t_stacks *stacks);

/**
 * @brief Check if "nb" number is already parsed in stack.
 * 
 * @param stack Stack which will be checked.
 * @param nb Number to be checked.
 * @return Returns 1 if number is present in stack otherwise returns 0.
 */
int		check_number_is_in_stack(t_stack *stack, int nb);

/**
 * @brief Check if str is a number greater than INT_MAX or is less
 * than INT_MIN.
 * 
 * @param str String which will be checked.
 * @return Return 1 if str is out integers range otherwise returns 0.
 */
int		out_int_range(char *str);

/**
 * @brief Check if str string is not a number.
 * 
 * @param str String which will be checked.
 * @return Returns 1 if string is not a number otherwise returns 0.
 */
int		is_not_a_number(char *str);

//FILE: reverse_rotate.c

/**
 * @brief Execute a reverse rotate operation at stacks.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param which_stack Flag which indicates if stack A, B or both will
 * be reverse rotated.
 */
void	reverse_rotate_stacks(t_stacks *stacks, int which_stack);

/**
 * @brief Execute a reverse rotate operation in a specific stack.
 * 
 * @param stack Stack which will be reverse rotated.
 */
void	reverse_rotate(t_stack *stack);

//FILE: rotate.c

/**
 * @brief Execute a rotate operation at stacks.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param which_stack Flag which indicates if stack A, B or both will
 * be rotated.
 */
void	rotate_stacks(t_stacks *stacks, int which_stack);

/**
 * @brief Execute a rotate operation in a specific stack.
 * 
 * @param stack Stack which will be rotated.
 */
void	rotate(t_stack *stack);

//FILE: sort_little.c

/**
 * @brief Algorithm that sorts stacks A and B when the total amount of nodes is 2.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	sort_2(t_stacks *stacks);

/**
 * @brief Algorithm that sorts stacks A and B when the total amount of nodes is 3.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	sort_3(t_stacks *stacks);

/**
 * @brief Algorithm that sorts stacks A and B when the total amount of nodes
 * is less than 10.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	sort_little(t_stacks *stacks);

void	swap_stacks(t_stacks *stack, int which_stack);
t_tree	*push_tree(t_tree *tree, t_node **node);
void	set_nodes_index(t_tree **tree, int *index);
void	radix_algorithm(t_stacks *stacks);
void	mid_point_algorithm(t_stacks *stacks);
void	wheel_algorithm(t_stacks *stacks);
int		stack_is_not_ordered(t_stacks *stacks);
int		max(int a, int b);
int		min(int a, int b);
int		mod(int a);

void	rotate_to_push(t_stacks *stacks);
void	copy_stack(t_stack *new, t_stack *old);
void	free_stack(t_stack *stack);
void	swap(int *x, int *y);
#endif