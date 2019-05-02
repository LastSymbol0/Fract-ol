NAME= fractol

MLX= -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC=	fract_set.c \
		fract_img.c \
		fract_fdf.c \
		fract_main.c \
		fract_line.c \
		fract_utils.c \
		fract_color.c \
		fract_fract.c \
		fract_fract2.c \
		fract_dragon.c  \
		fract_controls.c \
		fract_control_utils.c \
		./libft/libft.a

OBJ = $(SRC:%.c=%.o)

FLAGS = -g -Wall -Wextra -Werror

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