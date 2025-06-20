/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:18:38 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/21 11:17:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include <stdint.h>
# include <stddef.h>

# ifndef EPS
#  define EPS 0.00000011920929f
#endif

typedef struct s_matrix
{
	float		*data;
	uint32_t	rows;
	uint32_t	cols;
}	t_matrix;

#endif