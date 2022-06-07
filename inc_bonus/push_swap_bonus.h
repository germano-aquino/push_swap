/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 23:22:52 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "macro_bonus.h"
# include "struct_bonus.h"
# include "operation_bonus.h"
# include "receive_data_bonus.h"

//FILE: node_bonus.c

/**
 * @brief Add a node as a new tail in stack.
 * 
 * @param stack Stack which will be added.
 * @param nb Data node.
 * @return Returns the new node created.
 */
void	add_node_in_stack_tail(t_stack *stack, int nb);

//FILE: execute_ps_instructions.c

/**
 * @brief This function receives the instructions from STDIN and then
 * execute if it is a valid instruction.
 * 
 * @param stacks Variable which stores A and B stacks.
 * @return Returns 1 if an error occurs otherwise returns 0.
 */
int		exec_push_swap_instructions(t_stacks *stacks);

/**
 * @brief Check if string inst is a valid push_swap instruction and then
 * execute.
 * 
 * @param stacks Variable which stores A and B stacks.
 * @param inst Possible instruction to be executed.
 * @return Returns 1 if an error occurs otherwise returns 0.
 */
int		exec_if_valid_instruction(t_stacks *stacks, char *inst);

//FILE: utils.c

/**
 * @brief Swap the content of two integer pointers.
 * 
 * @param x 
 * @param y 
 */
void	swap(int *x, int *y);

/**
 * @brief Check if stack B is not empty or stack A is not sorted in 
 * ascending order.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @return Returns 1 if stacks are not sorted otherwise returns 0.
 */
int		stack_is_not_sorted(t_stacks *stacks);

/**
 * @brief This functions free a null ending 2 dimension char pointer.
 * 
 * @param ptr address of the 2 dimension char pointer.
 */
void	ft_free_2d_char_ptr(char ***ptr);
#endif