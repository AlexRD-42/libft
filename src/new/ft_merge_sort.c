#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void merge(int32_t *arr, int32_t *temp, int32_t left, int32_t right)
{
	int32_t			i;
	int32_t			j;
	int32_t			k;
	const int32_t	mid = left + (right - left) / 2;

	i = left;
	while (i <= mid)
	{
		temp[i] = arr[i];
		i++;
	}
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (temp[i] <= arr[j])
			arr[k] = temp[i++];
		else
			arr[k] = arr[j++];
		k++;
	}
	while (i <= mid)
		arr[k++] = temp[i++];
}

void recurse(int32_t *arr, int32_t *temp, int32_t left, int32_t right)
{
	int32_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		recurse(arr, temp, left, mid);
		recurse(arr, temp, mid + 1, right);
		merge(arr, temp, left, right);
	}
}

void	merge_sort(int32_t *array, size_t length)
{
	int32_t	buffer[4096];
	int32_t	*ptr;

	if (length > 4096)
	{
		ptr = (int32_t *)malloc(length * sizeof(int32_t));
		if (ptr == NULL)
			return ;
	}
	else
		ptr = buffer;
	recurse(array, ptr, 0, length - 1);
	if (length > 4096)
		free(ptr);
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}