/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:14:14 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 16:14:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static uint64_t state[2];

uint64_t splitmix64(uint64_t seed)
{
	uint64_t result = (seed += 0x9E3779B97f4A7C15);
	result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
	result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
	return (result ^ (result >> 31));
}

// Exponent at 127 = 1 - 2
// Exponent at 126 = 0.5 - 1
// Need to set exponent's MSB to 0, and if 127 

static inline float fast_itof(uint32_t value)
{
	float result;
	value &= 0b10000000011111111111111111111111; // 0x807FFFFF
	value |= 0b00111111000000000000000000000000; // 0x3F000000
	memcpy(&result, &value, 4);
	return (result);
}

static inline float slow_itof(uint64_t value)
{
	return (float)((value >> 32) / 2147483648.0 - 1.0);
}

uint32_t xoroshiro128(void)
{
	const uint64_t s0 = state[0];
	uint64_t s1 = state[1];
	const uint32_t result = (uint32_t)((s0 + s1) >> 32);

	s1 ^= s0;
	state[0] = ((s0 << 24) | (s0 >> 40)) ^ s1 ^ (s1 << 16);
	state[1] = (s1 << 37) | (s1 >> 27);

	return (result);
}

uint64_t xoroshiro128_64(void)
{
	const uint64_t s0 = state[0];
	uint64_t s1 = state[1];
	const uint64_t result = s0 + s1;

	s1 ^= s0;
	state[0] = ((s0 << 24) | (s0 >> 40)) ^ s1 ^ (s1 << 16);
	state[1] = (s1 << 37) | (s1 >> 27);

	return result;
}

void jump(void)
{
	static const uint64_t JUMP[2] = {0xdf900294d8f554a5, 0x170865df4b3201fc};
	uint64_t s0 = 0;
	uint64_t s1 = 0;
	for(int i = 0; i < 4; i++)
		for(int b = 0; b < 64; b++)
		{
			if (JUMP[i] & UINT64_C(1) << b)
			{
				s0 ^= state[0];
				s1 ^= state[1];
			}
			xoroshiro128();
		}
	state[0] = s0;
	state[1] = s1;
}

int main()
{
	uint64_t seed = 0xfedcba9876543210;
	state[0] = splitmix64(seed);
	state[1] = splitmix64(state[0]);

	for (int32_t i = 0; i < 10; i++)
	{
		printf("%f\n", fast_itof(xoroshiro128()));
	}
}