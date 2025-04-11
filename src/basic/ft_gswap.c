/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 16:00:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_gswap(void *a_void, void *b_void, size_t size)
{
	unsigned char	buffer[32];

	if (size > 32)
		return ;
	ft_memcpy(buffer, a_void, size);
	ft_memcpy(a_void, b_void, size);
	ft_memcpy(b_void, buffer, size);
}
