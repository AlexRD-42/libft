/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:26:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:26:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Outputs the string ’s’ to the specified file descriptor followed by a newline
// ft_strlen
void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}