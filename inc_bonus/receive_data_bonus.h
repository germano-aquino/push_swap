/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_data_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:08:56 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 20:10:57 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_DATA_BONUS_H
# define RECEIVE_DATA_BONUS_H

# include "struct_bonus.h"

//FILE: receive_data_bonus.c

/**
 * @brief Get the data from args and parse to stacks variable.
 * 
 * @param args Sequence of integers to be sorted in string format.
 * @param stacks Variable which contain the stacks A and B.
 * @return Returns -1 if a error occurs otherwise returns 1.
 */
int	get_stack_data(t_stacks *stacks, char *args);

/**
 * @brief Check if "nb" number is already parsed in stack.
 * 
 * @param stack Stack which will be checked.
 * @param nb Number to be checked.
 * @return Returns 1 if number is present in stack otherwise returns 0.
  */
int	check_number_is_in_stack(t_stack *stack, int nb);

/**
 * @brief Check if str is a number greater than INT_MAX or is less
 * than INT_MIN.
 * 
 * @param str String which will be checked.
 * @return Return 1 if str is out integers range otherwise returns 0.
 */
int	out_int_range(char *str);

/**
 * @brief Check if str string is not a number.
 * 
 * @param str String which will be checked.
 * @return Returns 1 if string is not a number otherwise returns 0.
 */
int	is_not_a_number(char *str);
#endif