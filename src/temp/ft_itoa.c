#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

char	*ft_itoa(int64_t n)
{
	const int8_t	sign = (int8_t) ((n >= 0) - (n < 0));
	char			str[21];
	char			*ptr;

	ptr = str + 20;
	*ptr = 0;
	*(--ptr) =  (sign * (int8_t) (n % 10)) + '0';
	n  = sign * (n / 10);
	while (n != 0)
	{
		*(--ptr) = (int8_t) (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	return (strdup(ptr));
}

int main()
{
	char *str = ft_itoa (1000);
}