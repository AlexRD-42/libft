/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:11:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:50:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILENAME_H			// All header files must have header guards
# define FILENAME_H			// Yes, a space is needed after define

# include <bloated_lib.h>	// Includes go at the beginning of the file

# define macro(X) (x)	// Macro Funcs are forbidden (and must be UPPER CASE)
# define TRUE 0			// If you are an evil, but norm compliant person

// Space, not tab, after union, enum, struct and typedef keywords
union u_union
{
	float		f32;
	uint32_t	u32; // This is a very useful union by the way
};

typedef int8_t	t_i8;		// If you are a rust person
t_i8			g_global;	// Forbidden unless stated otherwise

typedef struct s_struct
{
	u_union		my_union_var;
	enum e_enum
	{
		var1,		// 0 by default
		var2 = 3,	// 1 by default
	}	my_enum_var;
}	t_structtype; // This constructor must be tab aligned
#endif