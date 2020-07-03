
NAME = abstract_vm
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp Double.cpp Float.cpp Int8.cpp Int16.cpp\
		Int32.cpp Abstract_vm.cpp Operand_factory.cpp Lexer.cpp\
		Op_exceptions.cpp VM_exceptions.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.cpp
	@clang++ -c  $< -o $@

$(NAME): $(OBJ)
	@clang++ $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all