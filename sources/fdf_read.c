/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:11:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/22 11:48:35 by adeimlin         ###   ########.fr       */
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
t_fdf	fdf_atoi(const uint8_t *ustr, size_t count)
{
	t_fdf					fdf;
	int32_t					sign;
	static const uint8_t	lut[256] = {
	['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
	['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
	['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,
	['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

	sign = (*ustr == '-') - (*ustr != '-');
	ustr += (*ustr == '-') || (*ustr == '+');
	fdf.index = count;
	fdf.height = 0;
	fdf.color = 0;
	while (lut[*ustr] || *ustr == '0')
		fdf.height = fdf.height * 10 - lut[*ustr++];
	fdf.height *= sign;
	if (*ustr++ == ',')
	{
		ustr += (ustr[0] == '0' && (ustr[1] == 'x' || ustr[1] == 'X')) << 1;
		while (lut[*ustr] || *ustr == '0')
			fdf.color = (fdf.color << 4) + lut[*ustr++];
	}
	return (fdf);
}

static
t_fdf	*fdf_split(const char *str, const char *charset, size_t *count)
{
	t_fdf			*array;
	size_t			length;
	uint8_t			lut[256];
	const uint8_t	*ustr = (const uint8_t *) str;
	const size_t	tokens = ft_count_tokens(str, ft_setlut256(lut, charset), NULL);

	array = malloc(tokens * sizeof(t_fdf) * 2);
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
	*count *= (*count == tokens);	// Error catching
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
	vars->fdf = fdf_split(buffer, charset, &(vars->length));
	vars->vec =  (t_vec3 *) (vars->fdf + vars->length);
	fdf_init(buffer, '\n', vars);
	free(buffer);
	close(fd);
}
