#include <iostream>
#include <exception>
#include "ValorAbaixoException.h"
#include "ValorAcimaException.h"
#include "ValorMuitoAcimaException.h"
#include "TestaValidaNumero.h"

using namespace std;

void TestaValidaNumero::validaNumero(int num){
	if(num <= 0)
		throw ValorAbaixoException();
	if(num > 100 && num < 1000)
		throw ValorAcimaException();
	if(num >= 1000)
		throw ValorMuitoAcimaException();

	if(num > 0 && num <= 100)
		cout << "numero normal"<< endl;
}