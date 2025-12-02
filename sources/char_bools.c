/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:19:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 10:11:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint8_t	ft_isalpha(int32_t c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

uint8_t	ft_isdigit(int32_t c)
{
	return (c >= '0' && c <= '9');
}

uint8_t	ft_isspace(int32_t c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
