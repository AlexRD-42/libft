/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:43:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 14:43:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int64_t	ft_sqrt(int64_t number)
{
	int64_t	i;

	i = 1;
	if (number <= 0)
		return (0);
	else if (number == 1)
		return (1);
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (0);
}
