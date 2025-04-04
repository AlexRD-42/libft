/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:58:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/04 16:14:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	return (c >= 97 && c <= 122 || c >= 65 && c <= 90);
}

int	ft_isdigit(char c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isalnum(char c)
{
	return (c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57);
}

int	ft_isascii(char c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}