/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:08:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/28 21:17:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

uint64_t	ft_fibonacci(uint64_t index)
{
	uint64_t	previous;
	uint64_t	current;
	uint64_t	next;

	next = index;
	previous = 0;
	current = 1;
	while (index > 1)
	{
		next = previous + current;
		previous = current;
		current = next;
		index--;
	}
	return (next);
}
