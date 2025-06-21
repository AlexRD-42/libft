/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:11:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/20 19:58:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

// Count how many bytes are needed for a contiguous read
// Could count how many occurrences of a determined character
// Malloc can be avoided if count words is alias proof
// Would involve shifting the last two read elements to the start
static
size_t	fdf_read_size(const char *str)
{
	int32_t	fd;
	uint8_t	buffer[16 * 1024];
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

static
void	fdf_set_index2d(t_vars *vars)
{
	size_t	i;
	int32_t	y_index;

	i = 0;
	y_index = -1;
	while (i < vars->length)
	{
		y_index += (vars->ptr[i].x % vars->cols) == 0;
		vars->ptr[i].y = y_index * SCALE;
		vars->ptr[i].x = (vars->ptr[i].x % vars->cols) * SCALE;
		vars->ptr[i].z *= ZSCALE;
		i++;
	}
}

static
void	fdf_init(const char *str, const uint8_t byte, t_vars *vars)
{
	const uint8_t	*ustr = (const uint8_t *) str;
	size_t			i;

	vars->rows = 0;
	while (*ustr != 0)
	{
		vars->rows += (*ustr == byte);
		ustr++;
	}
	if (vars->rows == 0 || vars->length % vars->rows != 0)
		return ; // Error Handling
	vars->cols = vars->length / vars->rows;
	vars->min = INT32_MAX;
	vars->max = INT32_MIN;
	i = 0;
	while (i < vars->length)
	{
		if (vars->ptr[i].z > vars->max)
			vars->max = vars->ptr[i].z;
		if (vars->ptr[i].z < vars->min)
			vars->min = vars->ptr[i].z;
		i++;
	}
	fdf_set_index2d(vars);
}

t_vtx	fdf_atoi(const uint8_t *ustr, size_t count)
{
	t_vtx					vertex;
	int32_t					sign;
	static const uint8_t	lut[256] = {
	['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
	['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
	['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,
	['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

	sign = (*ustr == '-') - (*ustr != '-');
	ustr += (*ustr == '-') || (*ustr == '+');
	vertex.x = count;
	vertex.y = 0;
	vertex.z = 0;
	vertex.argb = 0;
	while (lut[*ustr] || *ustr == '0')
		vertex.z = vertex.z * 10 - lut[*ustr++];
	vertex.z *= sign;
	if (*ustr++ == ',')
	{
		ustr += (ustr[0] == '0' && (ustr[1] == 'x' || ustr[1] == 'X')) << 1;
		while (lut[*ustr] || *ustr == '0')
			vertex.argb = (vertex.argb << 4) + lut[*ustr++];
	}
	return (vertex);
}

t_vtx	*fdf_split(const char *str, const char *charset, size_t *count)
{
	t_vtx			*array;
	size_t			length;
	uint8_t			lut[256];
	const uint8_t	*ustr = (const uint8_t *) str;
	const size_t	tokens = ft_count_tokens(str, ft_setlut256(lut, charset), NULL);

	array = malloc(tokens * sizeof(t_vtx));
	if (array == NULL)
		return (NULL);
	*count = 0;
	while (*ustr != 0)
	{
		while (lut[*ustr] == 1)
			ustr++;
		length = 0;
		while (lut[ustr[length]] == 0)
			length++;
		if (length == 0)
			break ;
		array[*count] = fdf_atoi(ustr, *count);
		(*count)++;
		ustr += length;
	}
	return (array);
}

// Need to know if I need to keep a copy of the original input array for view reset
void	fdf_read(const char *str, const char *charset, t_vars *vars)
{
	char			*buffer;
	const size_t	total_memory = fdf_read_size(str);
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
	vars->ptr = fdf_split(buffer, charset, &(vars->length));
	fdf_init(buffer, '\n', vars);
	free(buffer);
	close(fd);
}
