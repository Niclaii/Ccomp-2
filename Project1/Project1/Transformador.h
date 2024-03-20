#pragma once
#include <iostream>

using namespace std;

void PonerContador(int& numero, int& contadorI, int& contadorV, int& contadorX, int& contadorL, int& contadorC, int& contadorD, int& contadorM, int& contador_V, int& contador_X)
{
	if (9000 <= numero && numero <= 9999)
	{
		contador_X = 9;
		numero = numero - 9000;
	}
	else
	{
		for (int i{ 0 }; numero >= 10000; i++)
		{
			contador_X++;
			numero -= 10000;
		};
	}
	int a{ 0 };
	bool repeticion{ true };
	do 
	{
		
		if (4000 <= numero && numero <= 4999)
		{
			contador_V = 9;
			numero = numero - 4000;
		}
		else
		{
			for (int i{ 0 }; numero >= 5000; i++)
			{
				contador_V++;
				numero -= 5000;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);

	a = 0;
	repeticion = false;

	do
	{
		if (900 <= numero && numero <= 999)
		{
			contadorM = 9;
			numero = numero - 900;
		}
		else
		{
			for (int i{ 0 }; numero >= 1000; i++)
			{
				contadorM++;
				numero -= 1000;
			};
		}

		if (a == 3)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
	
	a = 0;
	repeticion = false;

	do
	{
		if (900 <= numero && numero <= 999)
		{
			contadorD = 9;
			numero = numero - 900;
		}
		if (400 <= numero && numero <= 499)
		{
			contadorD = 5;
			numero = numero - 400;
		}
		else
		{
			for (int i{ 0 }; numero >= 500; i++)
			{
				contadorD++;
				numero -= 500;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
		
	a = 0;
	repeticion = false;

	do
	{
		if (90 <= numero && numero <= 99)
		{
			contadorC = 9;
			numero = numero - 90;
		}
		else
		{
			for (int i{ 0 }; numero >= 100; i++)
			{
				contadorC++;
				numero -= 100;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
	
	a = 0;
	repeticion = false;

	do
	{
		if (90 <= numero && numero <= 99)
		{
			contadorL = 9;
			numero = numero - 90;
		}
		else if (40 <= numero && numero <= 49)
		{
			contadorL = 5;
			numero = numero - 40;
		}
		else
		{
			for (int i{ 0 }; numero >= 50; i++)
			{
				contadorL++;
				numero -= 50;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
	
	a = 0;
	repeticion = false;

	do
	{
		if (numero == 9)
		{
			contadorX = 9;
			numero = numero - 9;
		}
		else
		{
			for (int i{ 0 }; numero >= 10; i++)
			{
				contadorX++;
				numero -= 10;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
	
	a = 0;
	repeticion = false;

	do 
	{
		if (numero == 9)
		{
			contadorV = 9;
			numero = numero - 9;
		}
		else
		{
			for (int i{ 0 }; numero >= 5; i++)
			{
				contadorV++;
				numero -= 5;
			};
		}
		if (a == 2)
		{
			repeticion = false;
		}
		a++;
	} while (repeticion == true);
	
	a = 0;
	repeticion = false;

	for (int i{ 0 }; numero >= 1; i++)
	{
		contadorI++;
		numero -= 1;
	};

	numero = 0;
}

void CantidadDeLetras(int &contadorI, int &contadorV, int &contadorX, int &contadorL, int &contadorC, int &contadorD, int &contadorM, int& contador_V, int& contador_X)
{	
	if (contador_X < 4) //contador _X
	{
		bool a{ true };
		for (int i{ 0 }; contador_X > 0; i++)
		{
			contador_X--;
			if (a == true)
			{
				cout << 'X';
				a = false;
			}
			else
			{
				cout << 'M';
			}
		}
	}
	else
	{
		cout << 'M' << 'X';
	}

	if (contador_V < 4) //contador _V
	{
		bool a{ true };
		for (int i{ 0 }; contador_V > 0; i++)
		{
			contador_V--;
			if (a == true)
			{
				cout << 'V';
				a = false;
			}
			else
			{
				cout << 'M';
			}
		}
	}
	else
	{
		cout << 'M' << 'V';
	}

	if (contadorM < 4) //contador M
	{
		for (int i{ 0 }; contadorM > 0; i++)
		{
			contadorM--;
			cout << 'M';
		}
	}
	else
	{
		cout << 'C'<<'M';
	}

	if (contadorD < 4)  // CONTADOR D
	{
		bool a{true};
		for (int i{ 0 }; contadorD > 0; i++)
		{
			contadorD--;
			if (a == true)
			{
				cout << 'D';
				a = false;
			}
			else
			{
				cout << 'C';
			}
		}
	}
	else if (contadorD == 9)
	{
		cout << 'C' << 'M';
	}
	else 
	{
		cout << 'C' << 'D';
	}

	if (contadorC < 4) //CONTADOR C
	{
		for (int i{ 0 }; contadorC > 0; i++)
		{
			contadorC--;
			cout << 'C';
		}
	}
	else
	{
		cout << 'X'<<'C';
	}

	if (contadorL < 4) //CONTADOR L
	{
		bool a{ true };
		for (int i{ 0 }; contadorL > 0; i++)
		{
			contadorL--;
			if (a == true)
			{
				cout << 'L';
				a = false;
			}
			else
			{
				cout << 'X';
			}
		}
	}
	else if (contadorL == 9)
	{
		cout << 'X' << 'C';
	}
	
	else 
	{
		cout << 'X'<<'L';
	}

	if (contadorX < 4) // CONTADOR X
	{
		for (int i{ 0 }; contadorX > 0; i++)
		{
			contadorX--;
			cout<<'X';
		}
	}
	else
	{
		cout << 'I'<<'X';
	}

	if (contadorV < 4) // CONTADOR V
	{
		bool a{ true };
		for (int i{ 0 }; contadorV > 0; i++)
		{
			contadorV--;
			if (a == true)
			{
				cout << 'V';
				a = false;
			}
			else
			{
				cout << 'I';
			}
		}
	}
	else if(contadorV == 9)
	{
		cout << 'I' << 'X';
	}
	else
	{
		cout << 'I' << 'V';
	}

	if (contadorI < 4) // CONTADOR I
	{
		for (int i{0}; contadorI > 0; i++)
		{
			contadorI--;
			cout << 'I';
		}
	}
	else if (contadorI == 4)
	{
		cout << 'I' << 'V';
	}
	return;
}