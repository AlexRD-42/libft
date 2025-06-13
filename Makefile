# Configuration ------------------------------- #
NAME = main
SRC_PATH = sources
INC_PATH = $(SRC_PATH)/includes
OBJ_PATH = $(SRC_PATH)/obj
VPATH = $(SRC_PATH) $(SRC_PATH)/core $(SRC_PATH)/string $(SRC_PATH)/math $(SRC_PATH)/iostream
CC = cc -Wall -Wextra -g -I$(INC_PATH)
SRCS = core_allocation.c core_swap.c mem_basic.c mem_copy.c mem_find.c \
str_basic.c str_bools.c str_copy.c str_find.c str_join.c str_operations.c \
list_utils.c sort_array.c io_basic.c io_convert.c
# --------------------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) 

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re