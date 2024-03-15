#pragma once

void CantidadDeLetras(int contadorI, int contadorV, int contadorX, int contadorL, int contadorC, int contadorD, int contadorM)
{
	string NumeroRomano;

	if (contadorM < 4) //contador M
	{
		for (int i; contadorM > 0; i++)
		{
			contadorM--;
			NumeroRomano + 'M';


		}
	}
	else
	{
		NumeroRomano + "IV";
	}
	if (contadorD < 4)  // CONTADOR D
	{
		bool a{true};
		for (int i; contadorD > 0; i++)
		{
			contadorD--;
			if (a == true)
			{
				NumeroRomano + 'D';
				a = false;
			}
			else
			{
				NumeroRomano + 'C';
			}
		}
	}
	else
	{
		NumeroRomano + "CD";
	}
	if (contadorC < 4) //CONTADOR C
	{
		for (int i; contadorC > 0; i++)
		{
			contadorC--;
			NumeroRomano + 'C';


		}
	}
	else
	{
		NumeroRomano + "XC";
	}
	if (contadorL < 4) //CONTADOR L
	{
		bool a{ true };
		for (int i; contadorL > 0; i++)
		{
			contadorL--;
			if (a == true)
			{
				NumeroRomano + 'L';
				a = false;
			}
			else
			{
				NumeroRomano + 'X';
			}
		}
	}
	else
	{
		NumeroRomano + "IV";
	}
	if (contadorX < 4) // CONTADOR X
	{
		for (int i; contadorX > 0; i++)
		{
			contadorX--;
			NumeroRomano + 'X';

		}
	}
	else
	{
		NumeroRomano + "IX";
	}
	if (contadorV < 4) // CONTADOR V
	{
		bool a{ true };
		for (int i; contadorV > 0; i++)
		{
			contadorV--;
			if (a == true)
			{
				NumeroRomano + 'V';
				a = false;
			}
			else
			{
				NumeroRomano + 'I';
			}
		}
	}
	else
	{
		NumeroRomano + "IV";
	}

	if (contadorI < 4) // CONTADOR I
	{
		for (int i; contadorI > 0; i++)
		{
			contadorI--;
			NumeroRomano + 'I';
		}
	}









}


void Verificador(int contadorI, int contadorV, int contadorX, int contadorL, int contadorC, int contadorD, int contadorM)
{



	if (contadorM < 4)
	{

	}






};

