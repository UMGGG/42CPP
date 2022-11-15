#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3
# define TOTAL_NUM_OF_LEVEL 4

class Harl
{
	private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
	public:
			Harl();
			void complain(std::string level);
			~Harl();
};

#endif
