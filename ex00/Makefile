NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = $(patsubst %.cpp,%.o,$(SRC))

.PHONY: all debug clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

debug: $(OBJ)
	$(CC) $(CFLAGS) -std=c++98 $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *~
	rm -f *.out

fclean: clean
	rm -f $(NAME)
	rm -f debug

re: fclean all
