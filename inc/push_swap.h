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
 * @param which_stack Flag which indicates if stack A or B will be pushed
 * (PA or PB).
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
 * be reverse rotated (RRA, RRB or RRR).
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
 * be rotated (RA, RB or RR).
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

//FILE: stack.c

/**
 * @brief Check if stack B is not empty or stack A is not sorted in ascending order.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @return Returns 1 if stacks are not sorted otherwise returns 0.
 */
int		stack_is_not_sorted(t_stacks *stacks);

/**
 * @brief Copy the old stack into the new malloced stack. 
 * 
 * @param new Target stack.
 * @param old Source stack.
 */
void	copy_stack(t_stack *new, t_stack *old);

/**
 * @brief Free malloced attributes at stack.
 * 
 * @param stack 
 */
void	free_stack(t_stack *stack);

//FILE: swap.c

/**
 * @brief Swap first and second elements of a stack.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param which_stack Flag which indicates if stack A, B or both will
 * be swapped (SA, SB or SS).
 */
void	swap_stacks(t_stacks *stacks, int which_stack);

//FILE: tree.c

/**
 * @brief Push a new node element in the tree sent as paramenter.
 * 
 * @param tree tree which will receive new node.
 * @param node new node to be sent to tree.
 * @return Returns tree's root.
 */
t_tree	*push_tree(t_tree *tree, t_node **node);

/**
 * @brief Create a new tree object with node as a parameter.
 * 
 * @param node
 * @return Returns new tree element. 
 */
t_tree	*create_new_tree(t_node **node);

/**
 * @brief Set the node's index attributes with the value of *index, 
 * after setted the tree element is freed.
 * 
 * @param tree Address of tree element to be setted.
 * @param index New value of index attribute.
 */
void	set_nodes_index(t_tree **tree, int *index);

//FILE: utils.c

/**
 * @brief Calculates the absolute value of integer a.
 * 
 * @param a Integer which will be calculated.
 * @return Returns a if a is greater than 0 otherwise returns -a.
 */
int		mod(int a);

/**
 * @brief Compares a and b absolute values and returns the maximum.
 * 
 * @param a 
 * @param b 
 * @return Returns the maximum absolute value between a and b.
 */
int		max(int a, int b);

/**
 * @brief Compares a and b absolute values and returns the minimum.
 * 
 * @param a 
 * @param b 
 * @return Returns the minimum absolute value between a and b.
 */
int		min(int a, int b);

/**
 * @brief Swap the content of two integer pointers.
 * 
 * @param x 
 * @param y 
 */
void	swap(int *x, int *y);

//FILE: wheel_algorithm.c

/**
 * @brief Algorithm which rotate both stacks in order to sort all elements
 * in stack A in ascending order and keep the stack B empty.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	wheel_algorithm(t_stacks *stacks);

/**
 * @brief This function first split the elements of stack A in two halves,
 * one half with the bigger elements and the other with the smaller. Secondly,
 * all elements of the bigger half but the maximum are pushed to stack B. Finally,
 * all elements of the smaller half but the minimum are pushed to stack B.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	parse_halves(t_stacks *stacks);

/**
 * @brief This function rotate both stacks is order to push an element to stack A
 * and keep the stack A ascending sorted.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	rotate_to_push(t_stacks *stacks);

/**
 * @brief This function check if there is a node inside of a range which has 
 * to make less rotations than the B stack head's node to push a element to A stack
 * and keep A stack ascending sorted.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param min Instruction vairable which stores the minimum amout of rotations in both stacks.
 * @param range Ranger of nodes to compare with B stack head's node.
 * @param direction If direction is 1 compares the nodes in forward direction, if direction is
 * -1 copmares the nodes in backwards direction.
 */
void	check_nodes_in_range(t_stacks *stacks, t_instruction *min, \
	int range, int direction);
#endif