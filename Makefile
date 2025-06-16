# Configuration ------------------------------- #
NAME = main
INC_PATH = sources/includes
OBJ_PATH = sources/obj
VPATH = sources sources/core sources/string sources/math sources/iostream sources/utils
# Files --------------------------------------- #
SRCS = core_allocation.c mem_basic.c mem_copy.c mem_find.c \
io_basic.c io_convert.c io_convert_base.c \
float_math.c int_log.c int_math.c int_primes.c \
str_basic.c str_bools.c str_bools2.c str_copy.c str_find.c str_join.c str_operations.c str_utils.c \
utils_array_info.c utils_info.c utils_list.c utils_rng.c utils_sort_array.c utils_swap.c
# Flags --------------------------------------- #
CC = cc -Wall -Wextra -I$(INC_PATH) -flto=auto -fstrict-aliasing
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wsign-conversion -Wswitch-default -Wduplicated-branches -Wduplicated-cond 
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math
# --------------------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

debug: $(OBJS)
	$(CC) $(DEBUG) $(SANITIZERS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug