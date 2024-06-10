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

LIBMLX = MLX/build/libmlx42.a
LIBMLX_INC = -IMLX/include/MLX42 -Iinclude
MLXFLG = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLXFLG) $(LIBMLX)  -o $(NAME)

$(BIN_DIR)%.o: %.c $(INCLUDES)
	@$(MKDIR) $(OBJS_DIRS)
	$(CC) $(CFLAGS) $(LIBMLX_INC)  -c $< -o $@ 

clean:
	@$(RM) $(BIN_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all