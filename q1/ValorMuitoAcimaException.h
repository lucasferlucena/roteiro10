#ifndef VALORMUITOACIMAEXCEPTION_
#define VALORMUITOACIMAEXCEPTION_


#include <iostream>
#include <exception>
#include <string>


class ValorMuitoAcimaException: public std::exception{
public:
	ValorMuitoAcimaException(void){}

	virtual const char* what(){
		return "Valor Muito Acima";
	}
};

#endif