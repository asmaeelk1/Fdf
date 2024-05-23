CC			= cc 
CFLAGS		= -Wall -g -Wextra -Werror -I includes 
RM			= rm -rf
MKDIR		= mkdir -p

NAME		= fdf

SRCS		= $(wildcard mandatory/*.c)
SRCS_DIRS	= $(dir $(SRCS))

BIN_DIR     = bin/
OBJS		= $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_DIRS	= $(dir $(OBJS))

INCLUDES	= includes/fdf.h


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	$(CC) $(CFLAGS)  -c $< -o $@ 

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all