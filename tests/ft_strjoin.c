/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:33:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/22 12:44:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *src1, const char *src2)
{
	const char	*osrc1 = src1;
	const char	*osrc2 = src2;
	char		*str;
	size_t		len;

	if (src1 == NULL || src2 == NULL)
		return (NULL);
	while (*src1 != 0)
		src1++;
	while (*src2 != 0)
		src2++;
	len = (src1 - osrc1) + (src2 - osrc2);
	str = (char *) malloc (len + 1);
	if (str == NULL)
		return (NULL);
	str += len;
	*str = 0;
	while (src2 > osrc2)
		*--str = *--src2;
	while (src1 > osrc1)
		*--str = *--src1;
	return (str);
}
