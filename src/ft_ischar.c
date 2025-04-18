/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:19:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 20:19:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int8_t	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int8_t	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int8_t	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int8_t	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int8_t	ft_isascii(int c)
{
	return (!(c >> 7));
}
