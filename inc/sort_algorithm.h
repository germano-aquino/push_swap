/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:36:47 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 19:09:06 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHM_H
# define SORT_ALGORITHM_H

//FILE: sort_little.c

/**
 * @brief Algorithm that sorts stacks A and B when the total amount
 * of nodes is 2.
 * 
 * @param stacks Variable which contain the stacks A and B.
 */
void	sort_2(t_stacks *stacks);

/**
 * @brief Algorithm that sorts stacks A and B when the total amount
 * of nodes is 3.
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
 * all elements of the bigger half but the maximum are pushed to stack B.
 * Finally, all elements of the smaller half but the minimum are pushed to
 * stack B.
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
 * @brief This function check if there is a node inside of a range which has to
 * make less rotations than the B stack head's node to push a element to A stack
 * and keep A stack ascending sorted.
 * 
 * @param stacks Variable which contain the stacks A and B.
 * @param min Instruction vairable which stores the minimum amout of rotations
 * in both stacks.
 * @param range Ranger of nodes to compare with B stack head's node.
 * @param direction If direction is 1 compares the nodes in forward direction,
 *  if direction is -1 copmares the nodes in backwards direction.
 */
void	check_nodes_in_range(t_stacks *stacks, t_instruction *min, \
	int range, int direction);
#endif