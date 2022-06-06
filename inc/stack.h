/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:34:20 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 19:07:26 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

//FILE node.c

/**
 * @brief Add a node as a new tail in stack.
 * 
 * @param stack Stack which will be added.
 * @param nb Data node.
 * @return Returns the new node created.
 */
t_node	*add_node_in_stack_tail(t_stack *stack, int nb);

//FILE: stack.c

/**
 * @brief Check if stack B is not empty or stack A is not sorted in 
 * ascending order.
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

#endif