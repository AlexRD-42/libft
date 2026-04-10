/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:25:07 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/11 10:17:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#ifndef FT_STDIO_BUFSIZE
# define FT_STDIO_BUFSIZE 4096
#endif

// typedef struct s_iovec
// {
// 	const void	*ptr;
// 	size_t		length;
// }	t_vec;

// typedef struct s_vec
// {
// 	union
// 	{
// 		const void	*kptr;
// 		void		*ptr;
// 	};
// 	// wptr?
// 	size_t		length;
// }	t_vec;

// struct
// {
// 	char		*data;
// 	uint32_t	offset;
// 	uint32_t	total;
// };

typedef struct s_vec
{
	char	*ptr;
	char	*wptr;
	char	*end;
}	t_vec;

#endif