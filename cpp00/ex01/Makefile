NAME = phonebook
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror
SRCS = PhoneBook.cpp Contact.cpp main.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
