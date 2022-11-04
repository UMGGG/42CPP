NAME = megaphone
GCC = clang++
GCCFLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
