/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:02:01 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/11 23:36:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// TODO: Return total bytes without separator
size_t	ft_count_words(const char *str, const char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str != 0)
		str++;
	count = (*str != 0);
	while (*str != 0)
	{
		count += (str[0] == c) && (str[1] != c) && (str[1] != 0);
		str++;
	}
	return (count);
}

t_str	*ft_split_tokens(const char *str, char c)
{
	
}