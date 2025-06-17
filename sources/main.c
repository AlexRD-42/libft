/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/17 17:07:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

// Count how many bytes are needed for a contiguous read
// Could count how many occurrences of a determined character
// Malloc can be avoided if count words is alias proof
// Would involve shifting the last two read elements to the start
size_t	ft_read_size(const char *str)
{
	int32_t	fd;
	uint8_t	buffer[4096];
	ssize_t	bytes_read;
	size_t	bytes_total;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0); // Error handling
	bytes_total = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_total += (size_t) bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
		return (0); // Error handling
	close(fd);
	return (bytes_total);
}

void	fdf_init(const char *str, const uint8_t byte, t_fdf_array *array)
{
	const uint8_t	*ustr = (const uint8_t *) str;
	size_t			i;

	array->rows = 0;
	while (*ustr != 0)
	{
		array->rows += (*ustr == byte);
		ustr++;
	}
	if (array->rows == 0 || array->length % array->rows != 0)
		return ; // Error Handling
	array->cols = array->length / array->rows;
	array->min = INT32_MAX;
	array->max = INT32_MIN;
	i = 0;
	while (i < array->length)
	{
		if (array->ptr[i] > array->max)
			array->max = array->ptr[i];
		if (array->ptr[i] < array->min)
			array->min = array->ptr[i];
		i++;
	}
}

// This is retarded
void	fdf_read(const char *str, const char *charset, t_fdf_array *array)
{
	char			*buffer;
	const size_t	total_memory = ft_read_size(str);
	ssize_t			bytes_read;
	int32_t			fd;

	fd = open(str, O_RDONLY);
	if (total_memory == 0 || fd < 0)
		return ; // Error Handling
	buffer = malloc(total_memory + 1);
	if (buffer == NULL)
		return ; // Error Handling (have to include closes)
	bytes_read = read(fd, buffer, total_memory);
	if (bytes_read <= 0 || (size_t) bytes_read != total_memory)
		return ; // Error Handling
	buffer[bytes_read] = 0;
	array->ptr = ft_split_numbers(buffer, charset, &(array->length));
	fdf_init(buffer, '\n', array);
	free(buffer);
	close(fd);
}

int	main(void)
{
	t_fdf_array	array;

	fdf_read("resources/maps/julia.fdf", " ,\n", &array);
}
