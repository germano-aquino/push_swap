/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:15:53 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/06 19:16:50 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

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
}				t_stacks;

typedef struct s_instruction
{
	int	rot_a;
	int	rot_b;
	int	total;
}				t_instruction;
#endif
