NAME= fractol

MLX= -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC=	src/fract_set.c \
		src/fract_img.c \
		src/fract_fdf.c \
		src/fract_main.c \
		src/fract_line.c \
		src/fract_utils.c \
		src/fract_utils2.c \
		src/fract_color.c \
		src/fract_fract.c \
		src/fract_fract2.c \
		src/fract_dragon.c  \
		src/fract_controls.c \
		src/fract_control_utils.c \
		src/fract_color_presets.c \
		src/fract_color_presets2.c \
		./libft/libft.a

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = fract.h



all: $(NAME)

$(NAME): 
	@make -C ./libft/
	@gcc -o $(NAME) $(SRC) $(FLAGS) $(MLX) -I $(INCLUDES)
	@echo "\x1b[32m Success build"

norme:
	norminette

clean:
	@rm -f $(OBJ)
	@make fclean -C ./libft/
	@echo "\x1b[32m Success clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all