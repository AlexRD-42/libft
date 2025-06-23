# Configuration ------------------------------- #
NAME = main
INC_PATH = sources/includes libraries/mlx
OBJ_PATH = sources/obj
LIBS = libraries/mlx/libmlx_Linux.a
VPATH = sources sources/core sources/string sources/math sources/iostream sources/utils
# Files --------------------------------------- #
SRCS = core_allocation.c mem_basic.c mem_copy.c mem_find.c mem_swap.c \
io_basic.c io_convert.c io_convert_base.c io_gnl.c io_printf.c \
float_math.c float_limits.c int_limits.c int_math.c int_primes.c int_range.c \
str_basic.c char_bools.c str_bools.c str_copy.c str_find.c str_join.c str_operations.c str_utils.c \
array_sort.c list_utils.c rng.c lookup_tables.c\
fdf_main.c cmlx_functions.c cmlx_events.c fdf_draw.c fdf_read.c fdf_math.c fdf_init.c
# Flags --------------------------------------- #
# For now turn off -Wsign-conversion
# CC = cc -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto=auto -fstrict-aliasing
CC = gcc-13 -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto=auto -fstrict-aliasing -lXext -lX11 -lm -lz
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wduplicated-branches -Wduplicated-cond
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math
# --------------------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

debug: $(OBJS)
	@$(MAKE) fclean
	@$(MAKE) all "CC=$(CC) $(DEBUG) $(SANITIZERS)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug