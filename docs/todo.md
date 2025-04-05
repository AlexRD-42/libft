# Standardize const char // char const

# Group functions by category

# Comment possible edge cases

# Remember to cast int c to unsigned char (stupid)

# Need better definition for trim and split



int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);