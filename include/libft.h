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

# include <stdio.h>		// New
# include <limits.h>	// New
# include <math.h>		// New

#define COPY_FLOOR 16
#ifdef __SIZEOF_POINTER__
    #define WORD_SIZE __SIZEOF_POINTER__
#else
	typedef t_ptr uint32_t
    #define WORD_SIZE 4
	#define PAGE_SIZE 4096
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_div 
{
	uint32_t	quot;
	uint32_t	rem;
}	t_div;

typedef union u_type32
{
	uint32_t	ui;
	int32_t		i;
	uint8_t		b[4];
	float		f;
}	t_32;

typedef union u_type64
{
	uint64_t	ul;
	int64_t		l;
	double		d;
	float		f[2];
	uint32_t	ui[2];
	int32_t		i[2];
	uint8_t		b[8];
}	t_64;

//----------------------------------------------------------------------------

// Prototypes: Char Information ----------------------------------------------
int8_t	ft_isalpha(int c);
int8_t	ft_isdigit(int c);
int8_t	ft_isalnum(int c); // Deprecated
int8_t	ft_isascii(int c);
int8_t	ft_isprint(int c);
int8_t	ft_toupper(int c);
int8_t	ft_tolower(int c);
int8_t	ft_isspace(int c); // New
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
int64_t		ft_atoi(const char *num_str);
size_t	ft_strlen(const char *str);
int32_t	ft_strcmp(const char *str1, const char *str2); // New
int32_t	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *str, unsigned char c);
char	*ft_strrchr(const char *str, unsigned char c);
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
char	*ft_itoa(int64_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_replace(char *str, unsigned char to_find, unsigned char c); // New
char 	*ft_strpbrk(const char *str, const char *charset); // New
//----------------------------------------------------------------------------

// Prototypes: Memory --------------------------------------------------------
void	*ft_memchr(const void *addr_void, uint8_t byte, size_t n);
int		ft_memcmp(const void *addr1_void, const void *addr2_void, size_t n);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t n);
void	*ft_memmove(void *dst_void, const void *src_void, size_t n);
void	*ft_memset(void *dst_void, uint8_t byte, size_t n);
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
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//----------------------------------------------------------------------------
#endif
