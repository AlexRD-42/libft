/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:23:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/05 11:23:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\includes\libft.h"

int	ft_isalpha(int c)
{
	c = (unsigned char) c;
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int	ft_isdigit(int c)
{
	c = (unsigned char) c;
	return (c >= '0' && c <= '9');
}

int	ft_isalnum(int c)
{
	c = (unsigned char) c;
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isprint(int c)
{
	c = (unsigned char) c;
	return (c >= 32 && c <= 126);
}

int	ft_toupper(int c)
{
	c = (unsigned char) c;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	c = (unsigned char) c;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}