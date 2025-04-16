// void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
// {
// 	char		*dst;
// 	const char	*src;

// 	dst = (char *) dst_void;
// 	src = (const char *) src_void;
// 	if (dst == src)
// 		return (dst_void);
// 	while (n > 0)
// 	{
// 		*dst++ = *src++;
// 		n--;
// 	}
// 	return (dst_void);
// }

void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
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