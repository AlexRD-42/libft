/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:34:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:35:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRINGS_H
# define LIBFT_STRINGS_H

# include <stdint.h>
# include <stddef.h>

// Prototypes: Strings -------------------------------------------------------
size_t		ft_strlen(const char *str);
int32_t		ft_strncmp(const char *str1, const char *str2, size_t length);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t		ft_strlcat(char *dst, const char *src, size_t dst_size);
// Prototypes: String Bools --------------------------------------------------
uint8_t		ft_isalpha(int32_t c);
uint8_t		ft_isdigit(int32_t c);
uint8_t		ft_isspace(int32_t c);
uint8_t		ft_isprint(int32_t c);
uint8_t		ft_isascii(int32_t c);
uint8_t		ft_ischarset(const char c, const char *charset);
// Prototypes: String Copy ---------------------------------------------------
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t length);
char		*ft_strdup(const char *src);
char		*ft_substr(const char *str, size_t start, size_t length);
// Prototypes: String Find ---------------------------------------------------
const char	*ft_strchr(const char *str, uint8_t c);
const char	*ft_strrchr(const char *str, uint8_t c);
const char	*ft_strfind(const char *str, const char *charset, uint8_t ref);
const char	*ft_strstr(const char *str, const char *substr);
const char	*ft_strnstr(const char *str, const char *substr, size_t length);
// Prototypes: String Join ---------------------------------------------------
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t length);
char		*ft_strjoin(const char *src1, const char *src2);
// Prototypes: String Operations ---------------------------------------------
char		**ft_split(const char *str, const char c);
int32_t		\
*ft_split_numbers(const char *str, const char *charset, size_t *count);
char		\
**ft_arena_split(const char *str, const char *charset, size_t *count);
char		*ft_strtrim(const char *str, const char *charset);
size_t		ft_replace(char *str, uint8_t old_char, uint8_t new_char);
// Prototypes: String Utils --------------------------------------------------
size_t		ft_count_words(const char *str, const char c);
size_t		ft_count_tokens(const char *str, const uint8_t *lut, size_t *bytes);
//----------------------------------------------------------------------------

#endif
