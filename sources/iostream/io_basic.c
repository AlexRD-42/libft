/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:45:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:34:58 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t	ft_read_size(const char *filename)
{
	const int32_t	fd = open(filename, O_RDONLY);
	uint8_t			buffer[16 * 1024];
	ssize_t			bytes_read;
	ssize_t			bytes_total;

	if (fd < 0)
		return (-1);
	bytes_total = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_total += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
		return (-1);
	close(fd);
	return (bytes_total);
}
