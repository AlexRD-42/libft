/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:27:20 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:27:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Outputs the integer ’n’ to the specified file descriptor.
// ft_strlen, ft_itoa
void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd == -1)
		return;
	str = ft_itoa(n);
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		free(str);
	}
}