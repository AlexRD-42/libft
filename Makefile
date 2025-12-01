# Configuration ------------------------------- #
NAME = main
BUILD_PATH = build
INC_PATH = includes
OBJ_PATH = $(BUILD_PATH)/obj
BIN = $(BUILD_PATH)/$(NAME)
VPATH = sources sources/core sources/string sources/math sources/iostream sources/utils \
sources/tests

# Files --------------------------------------- #
LIBS =
SRCS = ft_buffer.c
# SRCS = core_allocation.c memory.c mem_find.c mem_swap.c \
# io_basic.c io_put.c io_convert.c io_convert_base.c io_gnl.c io_printf.c \
# float_math.c float_limits.c int_limits.c int_math.c int_primes.c int_range.c \
# string.c char_bools.c str_bools.c str_copy.c str_find.c str_join.c str_operations.c str_utils.c \
# array_sort.c list_utils.c rng.c lookup_tables.c
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

# Flags --------------------------------------- #
CC = clang
CFLAGS = -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto -fstrict-aliasing
LFLAGS =
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wsign-conversion
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math

# Pattern Rule -------------------------------- #
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking Rule -------------------------------- #
$(BIN): $(OBJS) | $(BUILD_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(LFLAGS)

# Linking Rule
# $(NAME): $(OBJS)
# 	ar rcs -o $@ $(OBJS)

# Directory Rule ------------------------------ #
$(OBJ_PATH):
	@mkdir -p $@
$(BUILD_PATH):
	@mkdir -p $@

# Phonies ------------------------------------- #
all: $(BIN)

debug: CFLAGS += $(DEBUG) $(SANITIZERS)
debug: clean $(BIN)

fast: CFLAGS += $(FAST)
fast: clean $(BIN)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re fast debug
