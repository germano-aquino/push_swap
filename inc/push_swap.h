/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:07:06 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 13:53:51 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include "macro.h"
# include "struct.h"
# include "operation.h"
# include "stack.h"
# include "sort_algorithm.h"

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
#endif