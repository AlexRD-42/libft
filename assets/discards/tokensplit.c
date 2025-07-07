static
char	**init_split(const char *str, const char c, size_t *offset)
{
	char	**str_array;
	size_t	bytes;
	size_t	count;

	count = ft_count_words(str, c, &bytes);
	str_array = malloc(bytes + count + (count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	*offset = (count + 1) * sizeof(char *);
	str_array[count] = NULL;
	return (str_array);
}

// Problems: Arena malloc doesn't allow partial frees
char	**ft_split(const char *str, const char c)
{
	char		**str_array;
	const char	*ostr;
	size_t		offset;
	size_t		i;

	str_array = init_split(str, c, &offset);
	if (str_array == NULL)
		return (NULL);
	i = 0;
	while (*str != 0)
	{
		while (*str != 0 && *str == c)
			str++;
		ostr = str;
		while (*str != c && *str != 0)
			str++;
		if (ostr != str)
		{
			str_array[i] = ft_memcpy((char *) str_array + offset, ostr, str - ostr);
			str_array[i++][str - ostr] = 0;
			offset += str - ostr + 1;
		}
	}
	return (str_array);
}