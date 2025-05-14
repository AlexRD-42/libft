#include <stdint.h>
#include <stddef.h>

static void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((uintptr_t) dst < (uintptr_t) src)
	{
		while (n-- > 0)
			*dst++ = *src++;
	}
	else
	{
		dst += n - 1;
		src += n - 1;
		while (n-- > 0)
			*dst-- = *src--;
	}
	return (dst_void);
}

void	ft_memswap(void *a_void, void *b_void, size_t size)
{
	unsigned char	buffer[256];
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) a_void;
	b = (unsigned char *) b_void;
	while (size >= sizeof(buffer))
	{
		ft_memmove(buffer, a, sizeof(buffer));
		ft_memmove(a, b, sizeof(buffer));
		ft_memmove(b, buffer, sizeof(buffer));
		a += sizeof(buffer);
		b += sizeof(buffer);
		size -= sizeof(buffer);
	}
	ft_memmove(buffer, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, buffer, size);
}

// Word by Word approach
void	ft_memwswap(void *a_void, void *b_void, size_t size)
{
	uintptr_t		tword;
	uint8_t			tbyte;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) a_void;
	b = (unsigned char *) b_void;
	while (size >= sizeof(void*))
	{
		tword = *((uintptr_t *) a);
		*((uintptr_t *)a) = *((uintptr_t *)b);
		*((uintptr_t *)b) = tword;
		a += sizeof(void*);
		b += sizeof(void*);
		size -= sizeof(void*);
	}
	while (size > 0)
	{
		tbyte = *a;
		*a++ = *b;
		*b++ = tbyte;
		size--;
	}
}

// Byte by Byte approach
void	ft_membswap(void *a_void, void *b_void, size_t size)
{
	unsigned char	buffer;
	unsigned char	*a;
	unsigned char	*b;

	if ((uintptr_t) a_void < (uintptr_t) b_void)
	{
		a = (unsigned char *) a_void;
		b = (unsigned char *) b_void;
	}
	else
	{
		a = (unsigned char *) b_void;
		b = (unsigned char *) a_void;
	}
	while (size > 0)
	{
		buffer = *a;
		*a++ = *b;
		*b++ = buffer;
		size--;
	}
}

#include <stdio.h>

int	main(void)
{
	int32_t array[64] = {
		0,  1,  2,  3,  4,  5,  6,  7,
		8,  9, 10, 11, 12, 13, 14, 15,
	   16, 17, 18, 19, 20, 21, 22, 23,
	   24, 25, 26, 27, 28, 29, 30, 31,
	   32, 33, 34, 35, 36, 37, 38, 39,
	   40, 41, 42, 43, 44, 45, 46, 47,
	   48, 49, 50, 51, 52, 53, 54, 55,
	   56, 57, 58, 59, 60, 61, 62, 63};

	ft_memswap(array, array + 4, 8*4);

	for (int i=0;i<64;i++)
		printf("%d, ", array[i]);
}