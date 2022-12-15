#include "Convertor.hpp"

void Convertor::checkInput()
{
	if(this->_input == "nan" || this->_input == "nanf"
	 || this->_input == "inf" || this->_input == "-inf" || this->_input == "+inf"
	 || this->_input == "inff" || this->_input == "-inff" || this->_input == "+inff")
		this->_type = NAN_INF;
	else if (this->_input.length() == 1 && (this->_input[0] == '+' || this->_input[0] == '-'
	|| this->_input[0] == '.' || this->_input[0] == 'f' )) // +,-,.,f 중 하나만 있다면 CHAR
		this->_type = CHAR;
	else if (this->_input.find_first_of("+-") != this->_input.find_last_of("+-"))
		this->_type = ERROR; // +,-가 하나 이상 있다면 ERROR
	else if (this->_input.find_first_not_of("+-0987654321") == std::string::npos)
		this->_type = INT; // +,-,숫자만 있으면 INT
	else if (this->_input.find_first_not_of("+-0987654321.") == std::string::npos)
	{
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") || // .이 여러개 0.2.3
		isdigit(this->_input[this->_input.find_first_of(".") + 1]) == false // .뒤에 숫자가 아니거나 아무것도 없는경우 0.
		)
			this->_type = ERROR;
		this->_type = DOUBLE; // +,-,숫자,. 만 있으면 DOUBLE
	}
	else if (this->_input.find_first_not_of("+-0987654321.f") == std::string::npos)
	{
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") || // .이 여러개
		this->_input.find_first_of("f") != this->_input.find_last_of("f") || // f가 여러개
		)
			this->_type = ERROR; // +,-,숫자,.,f 만 있지만 .이 하나가 아니면 에러
		this->_type = FLOAT; // +,-,숫자,.,f 만 있으면 FLOAT
	}
	else if (this->_input.length() == 1 &&
	isprint(this->_input[0]) == true) // 길이가 1이고 출력가능한 문자라면 CHAR
		this->_type = CHAR;
}

Convertor::Convertor()
{
}

Convertor::Convertor(const std::string input): _input(input)
{
}

Convertor::Convertor(const Convertor &c): _input(c.getInput())
{
	*this = c;
}

Convertor &Convertor::operator=(const Convertor &c)
{
	if (this == &c)
		return (*this);
	this->_input = c.getInput();
	this->_char = c.getChar();
	this->_input = c.getInt();
	this->_double = c.getDouble();
	this->_int = c.getInt();
	return (*this);
}

Convertor::~Convertor()
{
}

// --------------getter----------------
std::string Convertor::getInput() const
{
	return (this->_input);
}

float Convertor::getFloat() const
{
	return (this->_float);
}

char Convertor::getChar() const
{
	return (this->_char);
}

double Convertor::getDouble() const
{
	return (this->_double);
}

int Convertor::getInt() const
{
	return (this->_int);
}
