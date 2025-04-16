/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:32:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 22:32:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// +1 [1 2 3 4] -> [4 1 2 3]
// +2 [1 2 3 4] -> [4 3 1 2]

// [1 2 3 4] [1 2 3 4]
// [2 1 3 4] [3 2 1 4]
// [3 1 2 4] [3 2 1 4]
// [4 1 2 3] [1 2 3 4]
void	ft_circshift(void *array_void, size_t array_size, size_t data_size, size_t n)
{
	ft_gswap(array_void + n, array_void + array_size - n, data_size*array_size);
}

int main()
{
	char *str = "alex";

	ft_circshift(str, 4, 5, 1);
	printf("%s", str);
}