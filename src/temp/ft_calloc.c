#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

void	*ft_memset(void *dst_void, uint8_t byte, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *) dst_void;
	while (n > 0)
	{
		*dst = byte;
		dst++;
		n--;
	}
	return (dst_void);
}

void	*ft_calloc(size_t arr_size, size_t type_size)
{
	void	*array;

	array = (void *) malloc (arr_size * type_size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, type_size * arr_size);
	return (array);
}

int main()
{
	int *ptr = 0;
	ft_calloc(100, ((size_t)1<<(sizeof(size_t)* 8 - 1)) + 1);
	if (ptr)
		printf("bolina"); 
}