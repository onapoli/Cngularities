NAME = pipeline

CC_FLAGS = -Wall -Wextra -Werror

SRCS = main.c init.c free.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) good_pipeline.o
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) good_pipeline.o

bad: $(OBJS) bad_pipeline.o
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) bad_pipeline.o

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) good_pipeline.o bad_pipeline.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

