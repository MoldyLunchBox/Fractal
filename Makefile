NAME = fractol
INC = includes/frog_tol.h
OBJ = src/frog_tol.o src/mandel.o src/screenshot.o src/julia.o src/tree.o src/events.o src/init_n_square.o src/mandel_norm_bs.o src/error.o 
LIB = libft/libft.a
FLAGS =  -Werror -Wall -Wextra 

all: $(LIB) $(NAME)

%.o : %.c $(INC)
	@cc $(FLAGS) -c -o $@ $< -I $(INC)

$(NAME): $(OBJ)
	@cc  $(OBJ) -o $@ -lmlx -framework OpenGL -framework AppKit $(LIB)
	@printf "\033[0;32m"
	@printf "BINARY CREATED\n"
	@printf "\033[0;0m"

$(LIB): 
	@make -C libft

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@printf "\033[0;32m"
	@printf "OBJETCS REMOVED\n"
	@printf "\033[0;0m"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@printf "\033[0;32m"
	@printf "BINARY REMOVED\n"
	@printf "\033[0;0m"

re: fclean all
