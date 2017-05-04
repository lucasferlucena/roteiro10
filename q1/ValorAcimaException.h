#ifndef VALORACIMAEXCEPTION_
#define VALORACIMAEXCEPTION_


#include <iostream>
#include <exception>
#include <string>


class ValorAcimaException: public std::exception{
public:
	ValorAcimaException(void){}

	virtual const char* what(){
		return "Valor Acima";
	}

};
#endif