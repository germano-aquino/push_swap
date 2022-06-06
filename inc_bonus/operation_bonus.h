/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:25:32 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 19:29:33 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_BONUS_H
# define OPERATION_BONUS_H

# include "struct_bonus.h"
//FILE push_bonus.c

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

//FILE: reverse_rotate_bonus.c

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

//FILE: rotate_bonus.c

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

//FILE: swap_bonus.c

/**
 * @brief Swap first and second elements of a stack.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param which_stack Flag which indicates if stack A, B or both will
 * be swapped (SA, SB or SS).
 */
void	swap_stacks(t_stacks *stacks, int which_stack);
#endif