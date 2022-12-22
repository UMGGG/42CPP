#include "Convertor.hpp"

bool    isnan_float(float f) // nan == nan은 false로 나오므로 확인 가능
{
    return (f != f);
}

bool    isinf_float(float f) // inf나 -inf는 무엇을 곱하든 부호만 바뀔수있고 그대로기때문에 2를곱해도 그대로면 0이거나 inf임
{
    return (f != 0 && f * 2 == f);
}

bool    isnan_double(double d)
{
    return (d != d);
}

bool    isinf_double(double d)
{
    return (d != 0 && d * 2 == d);
}

void Convertor::checkInput()
{
	if (this->_input == "NULL")
	{
		std::cout << "input is null ";
		throw Convertor::excep();
	}
	if(this->_input == "nan" || this->_input == "nanf"
	 || this->_input == "inf" || this->_input == "-inf" || this->_input == "+inf"
	 || this->_input == "inff" || this->_input == "-inff" || this->_input == "+inff")
		this->_type = NAN_INF;
	else if (this->_input.length() == 1 && (this->_input[0] == '+' || this->_input[0] == '-'
	|| this->_input[0] == '.' || this->_input[0] == 'f' )) // +,-,.,f 중 하나만 있다면 CHAR
	{
		this->_type = CHAR;
	}
	else if (this->_input.find_first_of("+-") != this->_input.find_last_of("+-"))
	{
		this->_type = ERROR; // +,-가 하나 이상 있다면 ERROR +123-11
	}
	else if (this->_input.find_first_of("+-") != std::string::npos &&
	this->_input.find_first_of("+-") != 0) // +,-가 존재하는데 첫 +,-가 처음에 있지않으면 ERROR 0+3123
	{
		this->_type = ERROR;
	}
	else if (this->_input.find_first_not_of("+-0987654321") == std::string::npos)
	{
		this->_type = INT; // +,-,숫자만 있으면 INT
	}
	else if (this->_input.find_first_not_of("+-0987654321.") == std::string::npos)
	{
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") || // .이 여러개 0.2.3
		isdigit(this->_input[this->_input.find_first_of(".") + 1]) == false ||// .뒤에 숫자가 아니거나 아무것도 없는경우 0.
		this->_input.find_first_of(".") == 0) // .이 가장 처음 있는 경우 .0123
		{
			this->_type = ERROR;
		}
		else
		{
			this->_type = DOUBLE; // +,-,숫자,. 만 있으면 DOUBLE
		}
	}
	else if (this->_input.find_first_not_of("+-0987654321.f") == std::string::npos)
	{
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") || // .이 여러개0.0.0f
		this->_input.find_first_of("f") != this->_input.find_last_of("f") || // f가 여러개 0.0ff
		this->_input[this->_input.find_first_of(".") + 1] == 'f' || // .뒤에 f가 오는경우 0.f
		this->_input[this->_input.find_first_of("f") + 1] != '\0' || // f가 끝에있지않는경우
		this->_input.find_first_of(".") == 0) // .이 가장 처음 있는 경우 .0123
		{
			this->_type = ERROR;
		}
		else
		{
			this->_type = FLOAT; // +,-,숫자,.,f 만 있으면 FLOAT
		}
	}
	else if (this->_input.length() == 1 && isprint(this->_input[0]) == true) // 길이가 1이고 출력가능한 문자라면 CHAR
	{
		this->_type = CHAR;
	}
	else
	{
		this->_type = ERROR;
	}
}

void Convertor::startConvert()
{
	if (this->_type == CHAR)
	{
		this->_char = static_cast<unsigned char>(this->getInput()[0]);
		this->_int = static_cast<int>(this->getChar());
		this->_float = static_cast<float>(this->getChar());
		this->_double = static_cast<double>(this->getChar());
	}
	else if (this->_type == INT)
	{
		this->_double = strtod(this->_input.c_str(), NULL);
		this->_int = static_cast<int>(this->getDouble());
		this->_float = static_cast<float>(this->getDouble());
		this->_char = static_cast<unsigned char>(this->getInt());
	}
	else if (this->_type == FLOAT)
	{
		this->_double = strtod(this->_input.c_str(), NULL);
		this->_float = static_cast<float>(this->getDouble());
		this->_char = static_cast<unsigned char>(this->getFloat());
		this->_int = static_cast<int>(this->getFloat());
	}
	else if (this->_type == DOUBLE)
	{
		this->_double = strtod(this->_input.c_str(), NULL);
		this->_char = static_cast<unsigned char>(this->getDouble());
		this->_int = static_cast<int>(this->getDouble());
		this->_float = static_cast<float>(this->getDouble());
	}
	else if (this->_type == NAN_INF)
		return ;
	else
		throw Convertor::excep();
}

void Convertor::printConvert()
{
	float float_ipart = 0.0;
	float float_fpart = 0.0;
	double double_ipart = 0.0;
	double double_dpart = 0.0;
	//CHAR
	if (this->_type != NAN_INF && this->_double >= 0 && this->_double <= CHAR_MAX)
	{
		if (isprint(this->_char))
			std::cout << "char: " << this->_char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
	//INT
	if (this->_type != NAN_INF && this->_double >= std::numeric_limits<int>::min() && this->_double <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << this->_int << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	//FLOAT
	if (this->_type != NAN_INF && !isnan_float(this->_float) && !isinf_float(this->_float))
	{ // 실수는 오버플로우나 언더플로우시 값이 돌지않고 inf로 변하게됨
		float_fpart = modf(this->_float, &float_ipart);
		if (float_fpart == 0.0)
			std::cout << "float: " << this->_float << ".0f" << std::endl;
		else
			std::cout << "float: " << this->_float << "f" << std::endl;
	}
	else if (this->_type != NAN_INF)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		if (this->_input == "nan" || this->_input == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->_input[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else if (this->_input[0] == '-')
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;
	}
	//DOUBLE
	if (this->_type != NAN_INF && !isnan_double(this->_double) && !isinf_double(this->_double))
	{
		double_dpart = modf(this->_double, &double_ipart);
		if (double_dpart == 0.0)
			std::cout << "double: " << this->_double << ".0" << std::endl;
		else
			std::cout << "double: " << this->_double << std::endl;
	}
	else if(this->_type != NAN_INF)
	{
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (this->_input == "nan" || this->_input == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->_input[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else if (this->_input[0] == '-')
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: inf" << std::endl;
	}
}

Convertor::Convertor()
{
}

Convertor::Convertor(const std::string input): _input(input)
{
	checkInput();
	startConvert();
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

int Convertor::getType() const
{
	return (this->_type);
}

const char* Convertor::excep::what(void) const throw()
{
	return ("Can't convert");
}
