/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:32:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 15:32:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int64_t	ft_power(int64_t number, int64_t power)
{
	int64_t	base;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	base = number;
	while (power-- > 1)
		number = number * base;
	return (number);
}
