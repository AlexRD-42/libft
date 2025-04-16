/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qrsqrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:28:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/13 10:28:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// This is faster than receiving a t_32 (thank god)
float	ft_qinvsqrt(float number)
{
	t_32	result;

	result.f = number;
	result.ui  = 0x5f3759df - (result.ui >> 1);
	result.f  = result.f * (1.5f - (number * 0.5f * result.f * result.f));
	return (result.f);
}
