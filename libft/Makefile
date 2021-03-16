NAME= libft.a
INC = libft.h
OBJ= ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memccpy.o \
	ft_strlen.o \
	ft_memmove.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strcpy.o \
	ft_strdup.o \
	ft_strcat.o \
	ft_strncat.o \
	ft_strlcat.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strstr.o \
	ft_strnstr.o \
	ft_strcmp.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isprint.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_strncpy.o \
	ft_isascii.o \
	ft_memalloc.o \
	ft_memdel.o \
	ft_strnew.o \
	ft_strdel.o \
	ft_strclr.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strequ.o \
	ft_strnequ.o \
	ft_strsub.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_strsplit.o \
	ft_itoa.o \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putstr.o \
	ft_putendl.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_lstnew.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstiter.o \
	ft_lstmap.o \
	 ft_free2dm.o \
	 ft_intlen.o \
	 ft_putnbrnl.o \
	 ft_split4fil.o \
	 ft_str_is_uppercase.o \
	 ft_swap.o \
	 ft_skipchar.o \
	 get_next_line.o\


all: $(NAME)

%.o : %.c $(INC)
	@cc $(FLAGS) -c -o $@ $< -I $(INC)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\033[0;32m"
	@printf "LIBFT.a CREATED\n"
	@printf "\033[0;0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

