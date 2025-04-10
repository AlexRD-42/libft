/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:24:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:29:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// assembly code generated is better with unsigned char
// check if inline code is passable
int	ft_isalpha(int c)
{
	unsigned char	byte;

	byte = (unsigned char) c;
	return ((byte >= 'a' && byte <= 'z') || (byte >= 'A' && byte <= 'Z'));
}
