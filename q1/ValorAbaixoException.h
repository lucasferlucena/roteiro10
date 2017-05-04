#ifndef VALORABAIXOEXCEPTOIN_
#define VALORABAIXOEXCEPTOIN_


#include <iostream>
#include <exception>
#include <string>


class ValorAbaixoException: public std::exception{
public:
	ValorAbaixoException(void){}

	virtual const char* what(){
		return "Valor Abaixo";
	}

};
#endif