/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_interp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:23:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/18 16:04:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

// __always_inline
uint32_t ft_lerp(int32_t max, int32_t min, int32_t value)
{
	double var = (double) (value - min) / (double) (max - min);
	return ((uint32_t) (var * 0x00FFFFFF));
}

