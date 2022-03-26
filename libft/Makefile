NAME = libft.a
HEADER = $(NAME:.a=.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
GCC = gcc -c -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
		$(GCC) $<

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
