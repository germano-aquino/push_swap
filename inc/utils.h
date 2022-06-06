/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:49:36 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 13:50:18 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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
#endif