NAME = account
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror
SRCS = Account.cpp test.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
