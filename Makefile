NAME	=	minitalk.a
SRC	=	libft/ft_atoi.c libft/ft_isascii.c libft/ft_memcmp.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strtrim.c \
libft/ft_bzero.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_putnbr_fd.c libft/ft_striteri.c  libft/ft_strmapi.c libft/ft_substr.c \
libft/ft_calloc.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_tolower.c \
libft/ft_isalnum.c libft/ft_itoa.c libft/ft_memset.c libft/ft_split.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_toupper.c \
libft/ft_isalpha.c libft/ft_memchr.c libft/ft_putchar_fd.c libft/ft_strchr.c libft/ft_strlcpy.c libft/ft_strrchr.c \
printf/ft_printf.c printf/param_checker.c  printf/polymorophic_itoa.c printf/unsigned.c printf/signed.c printf/itoh.c \
libft/ft_putstr.c  printf/itop.c server_utils.c 

CFLAGS =  -Wall -Wextra -Werror
CC = gcc
OBJ	=	$(SRC:.c=.o)
$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)
all: $(NAME) client server
	
client:
	gcc  $(CFLAGS) minitalk.a client.c -o client

server:
	gcc  $(CFLAGS) minitalk.a server.c -o server

clean:
	rm -f *.o
	rm -f libft/*.o
	rm -f printf/*.o

fclean: clean 
	@rm -f $(NAME) client server
re: fclean all

	
# .PHONY: 
