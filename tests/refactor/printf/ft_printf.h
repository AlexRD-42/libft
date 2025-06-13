/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:04:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/12 17:42:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Includes	and Structs ------------------------------------------------------
# include <stdint.h>
# include <unistd.h>

ssize_t	ft_printf(const char *str, ...);
#endif