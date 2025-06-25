/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:45:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 09:46:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
// Count how many bytes are needed for a contiguous read
// Could count how many occurrences of a determined character
// Malloc can be avoided if count words is alias proof
// Would involve shifting the last two read elements to the start
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