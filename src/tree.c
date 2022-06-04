/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:11:36 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 23:15:35 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_nodes_index(t_tree **tree, int *index)
{
	t_node	*node;

	if (*tree != NULL)
	{
		node = (*tree)->node;
		set_nodes_index(&(*tree)->left, index);
		node->index = (*index)++;
		set_nodes_index(&(*tree)->right, index);
		free(*tree);
	}
}

t_tree	*create_new_tree(t_node **node)
{
	t_tree	*new;

	new = (t_tree *) malloc(sizeof(t_tree));
	new->node = *node;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_tree	*push_tree(t_tree *tree, t_node **node)
{
	t_node	*tree_node;

	tree_node = tree->node;
	if (tree == NULL)
	{
		tree = create_new_tree(node);
		return (tree);
	}
	else if (tree_node->data > (*node)->data)
		tree->left = push_tree(tree->left, node);
	else if (tree_node->data < (*node)->data)
		tree->right = push_tree(tree->right, node);
	return (tree);
}
