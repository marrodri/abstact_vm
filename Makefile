
NAME = abstract_vm

SRC = main.cpp src/Double.cpp src/Float.cpp src/Int8.cpp src/Int16.cpp\
		src/Int32.cpp src/Abstract_vm.cpp src/Operand_factory.cpp src/Lexer.cpp\
		src/Op_exceptions.cpp src/VM_exceptions.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.cpp
	@clang++ -I ./includes/ -c  $< -o $@ -g

$(NAME): $(OBJ)
	@clang++ -I ./includes/ $(OBJ) $(CFLAGS) -o  $(NAME) -g

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all