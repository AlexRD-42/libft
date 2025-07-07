/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_iostream.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:41:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 19:58:05 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IOSTREAM_H
# define LIBFT_IOSTREAM_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

ssize_t		ft_putstr(char *str, int fd, char c);
ssize_t		ft_putnbr(int64_t number, int fd, char c);
ssize_t		ft_putnchar(const char c, int fd, size_t length);
ssize_t		ft_putbits(const uint8_t byte, int fd);

int64_t		ft_atoi(const char *num_str);
uint64_t	ft_atoi_hex(const char *str);
int64_t		ft_atoi_base(const char *str, const char *base);

char		*ft_itoa(int64_t number);
char		*ft_itoa_stack(int64_t number, char *ptr);
char		*ft_itoa_base(const int64_t number, const char *base);

ssize_t		ft_read_size(const char *filename);
char		*get_next_line(int fd);
ssize_t		ft_printf(const char *str, ...);

#endif
