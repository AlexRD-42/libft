/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:39:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/22 15:59:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_gswap(void *a_void, void *b_void, size_t size)
{
	unsigned char	buffer[32];

	if (size > 32)
		return ;
	ft_memcpy(buffer, a_void, size);
	ft_memcpy(a_void, b_void, size);
	ft_memcpy(b_void, buffer, size);
}
