/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:19:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:43:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

// Is 0 part of the charset?
uint8_t	ft_ischarset(const char c, const char *charset)
{
	while (*charset != c && *charset != 0)
		charset++;
	return (*charset != 0 || c == 0);
}
