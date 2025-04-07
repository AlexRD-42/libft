/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:47:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 10:47:42 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Behavior: Skips whitespaces until either sign or number
// Edge Cases: INT_MIN, INT_MAX, 0

int32_t	ft_atoi(const char *num_str)
{
	int32_t	number;

	number = 0;
	while (*num_str == 32 || (*num_str >= 9 && *num_str <= 13))
		num_str++;
	if (*num_str == '+')
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		while (*num_str >= '0' && *num_str <= '9')
			number = number * 10 - (*num_str++ - '0');
	}
	else
	{
		while (*num_str >= '0' && *num_str <= '9')
			number = number * 10 + (*num_str++ - '0');
	}
	return (number);
}