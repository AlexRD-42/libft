/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 17:03:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// int64_t	ft_log(int64_t number, int64_t base)
// {
	
// }

// int32_t	ft_log2(uint32_t number)
// {
// 	int32_t	result;

// 	result = 0;
// 	if (number == 0)
// 		return (-1);
// 	if (number & 0xFFFF0000)
// 	{
// 		result += 16;
// 		number >>= 16;
// 	}
// 	if (number & 0x0000FF00)
// 	{
// 		result += 8;
// 		number >>= 8;
// 	}
// 	if (number & 0x000000F0)
// 	{
// 		result += 4;
// 		number >>= 4;
// 	}
// 	if (number & 0x0000000C)
// 	{
// 		result += 2;
// 		number >>= 2;
// 	}
// 	if (number & 0x00000002) 
// 		result += 1;
// 	return (result);
// }

// uint32_t	ft_log2(uint32_t number)
// {
// 	static const uint8_t log2_table[256] = {0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3,
// 		3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
// 		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
// 		5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
// 		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
// 		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
// 		6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
// 		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
// 		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
// 		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
// 		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
// 		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};

// 	if (number & 0xFF000000)
// 		return (log2_table[number >> 24] + 24);
// 	if (number & 0x00FF0000)
// 		return (log2_table[number >> 16] + 16);
// 	if (number & 0x0000FF00)
// 		return (log2_table[number >> 8] + 8);
// 	return (log2_table[number]);
// }

int32_t ft_log2(uint32_t number)
{
    static const int MultiplyDeBruijnBitPosition[32] = 
    {0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
    8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31};
    if (number == 0)
        return (-1);
    number |= number >> 1;
    number |= number >> 2;
    number |= number >> 4;
    number |= number >> 8;
    number |= number >> 16;
    return MultiplyDeBruijnBitPosition[(uint32_t)(number * 0x07C4ACDDU) >> 27];
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_log2(8));
}