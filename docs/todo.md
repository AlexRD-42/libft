# Improve ft_power for perfect squares

# fused multiply add

# learn about brace encapsulation (for loops, or just {})

# Learn about loop unrolling

# https://graphics.stanford.edu/~seander/bithacks.html

// Use:
remainder = n & (sizeof(uintptr_t) - 1);
words = n >> log2(sizeof(uintptr_t));  // e.g., n >> 3 for 8-byte words

# asd
 Determining if an integer is a power of 2

unsigned int v; // we want to see if v is a power of 2
bool f;         // the result goes here 

f = (v & (v - 1)) == 0;

Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:

f = v && !(v & (v - 1));
