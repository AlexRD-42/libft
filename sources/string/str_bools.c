/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:19:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:38:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint8_t	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

uint8_t	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

uint8_t	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

uint8_t	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

uint8_t	ft_isascii(int c)
{
	return (!(c >> 7));
}

uint8_t	is_charset(const char c, const char *charset)
{
	while (*charset != c && *charset != 0)
		charset++;
	return (*charset != 0 || c == 0);
}
