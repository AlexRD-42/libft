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

#ifndef LIBFT_H
# define LIBFT_H

// Includes	and Structs ------------------------------------------------------
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

# include <stdio.h> // New
# include <string.h> // New
# include <limits.h> // New

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
//----------------------------------------------------------------------------

// Prototypes: Char Information ----------------------------------------------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c); // Deprecated
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int c); // New
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

// Prototypes: Utilities -------------------------------------------------------
void	ft_swap(char *a, char *b);
void	ft_gswap(void *a_void, void *b_void, size_t size);
void	ft_bubble_sort(void *array_void, size_t array_size, size_t data_size);
void	ft_reverse(void *array_void, size_t size);
int32_t	ft_memrcmp(const void *addr1_void, const void *addr2_void, size_t data_size);
//----------------------------------------------------------------------------

// Prototypes: Strings -------------------------------------------------------
int		ft_atoi(const char *num_str);
size_t	ft_strlen(const char *str);
int32_t	ft_strcmp(const char *str1, const char *str2); // New
int32_t	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, const char *src); // New
char	*ft_strncpy(char *dst, const char *src, size_t n); // New
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strcat(char *dst, const char *src); // New
char	*ft_strncat(char *dst, const char *src, size_t n); // New
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_replace(char *str, unsigned char to_find, unsigned char c); // New
//----------------------------------------------------------------------------

// Prototypes: Memory --------------------------------------------------------
void	*ft_memchr(const void *addr_void, int c, size_t n);
int		ft_memcmp(const void *addr1_void, const void *addr2_void, size_t n);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t n);
void	*ft_memmove(void *dst_void, const void *src_void, size_t n);
void	*ft_memset(void *dst_void, int c, size_t n);
void	ft_bzero(void *addr_void, size_t n);
void	*ft_calloc(size_t array_size, size_t data_size);
//----------------------------------------------------------------------------

// Prototypes: File Operations -----------------------------------------------
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//----------------------------------------------------------------------------

// Prototypes: Linked Lists --------------------------------------------------
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//----------------------------------------------------------------------------
#endif
