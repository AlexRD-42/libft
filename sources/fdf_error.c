/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:32:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/18 15:29:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

// Remember to free and close fds
// Maybe an Enum would be better
// static const char *error[] = {
// 	"Error: Number of columns differ",
// 	"Error: Failed to allocate memory",
// 	"Error: Read values do not match",};