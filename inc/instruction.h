/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:52:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 13:53:36 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

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
#endif