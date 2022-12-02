#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
			std::string ideas[100];
	public:
			Brain();
			Brain(const Brain &brain);
			Brain &operator=(const Brain &brain);
			~Brain();
			void setIdeas(std::string str, int i);
			void setAllIdeas(std::string str);
			std::string getIdeas(int i) const;
};


#endif
