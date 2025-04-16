#include "../include/libft.h"
#include "../include/hres_timer.h"

#define TOSTRING(x) STRINGIFY(x)
#define STRINGIFY(x) #x

#define num_runs 100
#define num_iter 20

#define fnc	2
#define fn0 ft_fibonacci
#define fn1 ft_rfibonacci
#define fn2
#define fn3
#define FN_NAME(n) fn##n
#define printfn(x) printf("%s: %f ns\n", TOSTRING(FN_NAME(x)), printns(get_avg(results[x], num_runs)));

static float	resf = 0.0f;
static int32_t	resi = 0;
static int64_t	resl = 0;

int64_t	ft_fibonacci(int64_t index);
int64_t	ft_rfibonacci(int64_t index);
// void		fn2();
// void		fn3();

void	res_set(void)
{
	resf = 0.0001f;
	resi = 1;
	resl = 0;
}

uint64_t benchmark_rng(uint32_t fn_index)
{
	res_set();
	uint64_t start = ns();

	switch (fn_index)
	{
		case 0:
			for (uint64_t i = 0; i < num_iter; i++)
				fn0(resl++);
			break;
		case 1:
			for (uint64_t i = 0; i < num_iter; i++)
				fn1(resl++);;
			break;
		case 2:
			for (uint64_t i = 0; i < num_iter; i++)
				;
			break;
		case 3:
			for (uint64_t i = 0; i < num_iter; i++)
				;
			break;
		default:
			break;
	}
	return (ns() - start);
}

double get_avg(uint64_t *ptr, uint64_t n)
{
	uint64_t sum = 0;
	for (uint64_t i = n/10; i < n; i++)
		sum += ptr[i];
	return (((double)(sum)) / (n - n/10));
}

int main()
{
	int32_t i, start, fn_index;
	uint64_t (*results)[num_runs] = malloc(num_runs * fnc * sizeof(uint64_t));

	srand(ns());
	for (uint64_t run = 0; run < num_runs; run++) 
	{
		start = rand();
		for (i = start; i < start + fnc; i++)
		{
			fn_index = i % fnc;
			results[fn_index][run] = benchmark_rng(fn_index);
		}
    }

	for (i = 0; i < fnc; i++)
		printfn(i);
	printf("\n%f, %d, %lld", resf, resi, resl);
	free(results);
}
