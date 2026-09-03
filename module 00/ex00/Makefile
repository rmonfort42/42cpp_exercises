NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
