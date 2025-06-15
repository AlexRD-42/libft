/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:11:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:35:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Includes	and Structs ------------------------------------------------------
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//----------------------------------------------------------------------------


// Prototypes: Core ----------------------------------------------------------
void	*ft_calloc(size_t arr_size, size_t type_size);
void	*ft_realloc(void *src, size_t src_size, size_t dst_size);
void	**ft_free_array(void *array, size_t length);

//----------------------------------------------------------------------------

// Prototypes: Math --------------------------------------------------------
int64_t	ft_sqrt(int64_t number);
int64_t	ft_power(int64_t number, int64_t power);
int64_t	ft_fibonacci(int64_t index);
int64_t	ft_isprime(int64_t number);
int64_t	ft_factorial(int64_t number);
float	ft_average(float *array, uint32_t size);
int64_t	ft_log(int64_t number, int64_t base); // Note: this function is incomplete
//----------------------------------------------------------------------------

// Prototypes: Utilities -----------------------------------------------------

//----------------------------------------------------------------------------

// Prototypes: Char Information ----------------------------------------------
uint8_t	ft_isalpha(int c);
uint8_t	ft_isdigit(int c);
uint8_t	ft_isascii(int c);
uint8_t	ft_isprint(int c);
uint8_t	ft_isspace(int c);
uint8_t	ft_ischarset(const char c, const char *charset);
//----------------------------------------------------------------------------

// Prototypes: Sort ----------------------------------------------------------
void	ft_bubble_sort(int32_t *array, size_t length);
void	ft_selection_sort(int32_t *array, size_t length);
void	ft_insertion_sort(int32_t *array, size_t length);
//----------------------------------------------------------------------------

// Prototypes: Strings -------------------------------------------------------
size_t	ft_strlen(const char *str);
int32_t	ft_strcmp(const char *str1, const char *str2); // New
int32_t	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strcat(char *dst, const char *src); // New
char	*ft_strncat(char *dst, const char *src, size_t n); // New
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
// char	**ft_split(char const *s, char c);
size_t	ft_replace(char *str, unsigned char to_find, unsigned char c); // New
size_t	ft_count_words(const char *str, const char c);
size_t	ft_count_tokens(const char *str, const char *charset, size_t *bytes);
//----------------------------------------------------------------------------

// Prototypes: String Find ---------------------------------------------------
char	*ft_strchr(const char *str, unsigned char c);
char	*ft_strrchr(const char *str, unsigned char c);
char	*ft_strfind(const char *str, const char *charset, unsigned char ref);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_strnstr(const char *str, const char *substr, size_t length);
//----------------------------------------------------------------------------

// Prototypes: String Copy ---------------------------------------------------
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t length);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *str, size_t start, size_t length);
//----------------------------------------------------------------------------

// Prototypes: Memory --------------------------------------------------------
void	*ft_memchr(const void *ptr_void, uint8_t byte, size_t length);
int64_t	ft_memcmp(const void *ptr1_void, const void *ptr2_void, size_t length);
int64_t	ft_memrcmp(const void *ptr1_void, const void *ptr2_void, size_t length);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	*ft_memset(void *dst_void, uint8_t byte, size_t n);
//----------------------------------------------------------------------------

// Prototypes: Input/Output --------------------------------------------------
void	ft_putstr(const char *str, int fd);
void	ft_putnbr(int64_t number, int fd);
int64_t	ft_atoi(const char *num_str);
char	*ft_itoa(int64_t number);
//----------------------------------------------------------------------------

// Prototypes: Linked Lists --------------------------------------------------
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//----------------------------------------------------------------------------
#endif
