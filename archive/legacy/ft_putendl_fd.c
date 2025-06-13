/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:42:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 22:42:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
