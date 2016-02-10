NAME	=	fdf

SRC		= 	main.c \
			map.c \
			fdf.c \
			helper.c
			
LIBFT	= libft/libft.a
MLX		= mlx/libmlx.a

LIBSDIR	= -L ./lib

LIBS	= -lft -lmlx

INC		= ./inc/

OBJ		= $(SRC:.c=.o)

CC		= gcc

CCFLAGS	= -Wall -Werror -Wextra

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) $(FRAMEWORK) $(LIBSDIR) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I $(INC) -c $< -o $@ 

$(LIBFT):
	@make -C libft
	cp ./libft/libft.a ./lib/
	cp ./libft/includes/libft.h ./inc/

$(MLX):
	@make -C mlx
	cp ./mlx/libmlx.a ./lib/
	cp ./mlx/mlx.h ./inc

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@make -C mlx clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@/bin/rm -rf ./lib/libft.a
	@/bin/rm -rf ./lib/libmlx.a
	@/bin/rm -rf ./inc/mlx.h
	@/bin/rm -rf ./inc/libft.h

re: fclean all

.PHONY: all clean fclean re
