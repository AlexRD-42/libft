/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:57 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 21:51:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_parse_base(char *str, int k);
int	ft_find(char *str, char c);
int	ft_parse_number(char *str, char *base, int *i, int *sign);
int	ft_atoi_base(char *str, char *base);

char	*ft_fill_string(int number, char *num_str, char *base, int num_digits)
{
	int	i;
	int	sign;
	int	radix;

	i = 0;
	radix = ft_parse_base(base, 0);
	sign = -1 * (number < 0) + (number >= 0);
	while (i < (num_digits + (number < 0)))
	{
		num_str[i] = base[sign * (number % radix)];
		number = number / radix;
		i++;
	}
	if (sign == -1)
		num_str[i++] = '-';
	num_str[i] = 0;
	reverse_string(num_str);
	return (num_str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;
	int	num;
	int	base_length;

	num = 0;
	n = ft_parse_number(str, base, &i, &sign);
	base_length = ft_parse_base(base, 0);
	if (base_length == -1)
		return (0);
	while (i < n)
		num = num * base_length + ft_find(base, str[i++]);
	return (sign * num);
}

int	ft_parse_number(char *str, char *base, int *i, int *sign)
{
	int	n;

	*i = 0;
	*sign = 1;
	while (str[*i] != 0 && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32))
		*i += 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
	n = *i;
	while (str[n] != 0 && (ft_find(base, str[n]) != -1))
		n++;
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*num_str;
	int		number;
	int		radix_old;
	int		radix_new;
	int		num_digits;

	radix_old = ft_parse_base(base_from, 0);
	radix_new = ft_parse_base(base_to, 0);
	if (radix_old <= 1 || radix_new <= 1)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	num_digits = ft_num_digits(number, radix_new);
	num_str = (char *) malloc(num_digits + 1 + (number < 0));
	if (num_str == NULL)
		return (NULL);
	return (ft_fill_string(number, num_str, base_to, num_digits));
}

#include <stdio.h>
int main()
{
	printf("%s\n", ft_convert_base("4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-255", "0123456789", "01234567"));
	printf("%s\n", ft_convert_base("-127", "0123456789", "01"));
	// ft_convert_base("-127", "0123456789", "fff");
	// ft_convert_base("-12x7", "012326789", " aushda");
	// ft_convert_base("12x7", "0123267x879", "123");
}