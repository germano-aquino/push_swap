/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:04:41 by grenato-          #+#    #+#             */
/*   Updated: 2022/06/03 23:16:13 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	mod(int a)
{
	if (a > 0)
		return (a);
	else
		return (-1 * a);
}

int	max(int a, int b)
{
	if (mod(a) > mod(b))
		return (mod(a));
	else
		return (mod(b));
}

int	min(int a, int b)
{
	if (mod(a) < mod(b))
		return (mod(a));
	else
		return (mod(b));
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
