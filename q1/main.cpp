#include <iostream>
#include <exception>
#include <string>
#include "TestaValidaNumero.h"
#include "ValorAbaixoException.h"
#include "ValorAcimaException.h"
#include "ValorMuitoAcimaException.h"

using namespace std;

int main()
{
	TestaValidaNumero a;

	try{
		a.validaNumero(1900);
	}
	catch(ValorAbaixoException &ex){
		cout << ex.what() << endl;
	}
	catch(ValorAcimaException &ex){
		cout << ex.what() << endl;
	}
	catch(ValorMuitoAcimaException &ex){
		cout << ex.what() << endl;
	}

}