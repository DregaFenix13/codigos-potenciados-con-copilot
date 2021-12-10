 //pireamide centrada 4.1 whit copilt

#include <iostream>
using namespace std;

//se hace el menu principal


int main()
{//dentro del menu se le pide al usuario el alto de la piramide
	int alto,j=0,m=0;
	
	cout << "ingrese el alto de la piramide" << endl;
	cin >> alto;
	int espacio = alto +5;
	
	
	//se crea un ciclo que va a imprimir la piramide
	//se crea el contaddor de los pisos
	for (int i = 0; i < alto; i++)
	{
		//se crea un ciclo que va a imprimir los espacios menos el ultimo
		for (int j = 0; j < espacio-1; j++)
		{
			cout << " ";
		}
	
		//se crea un ciclo que va a imprimir los asteriscos
	for (int k = 0; k < i + 1; k++)
		{
		
			cout << "*";
		}
		for (int n =0; n < i ; n++)
		{
			
			cout << "*";
		}
	
		//se imprime un salto de linea
		cout << endl;

		//se le resta uno al espacio para que se vuelva a imprimir	
		espacio--;

	}	
	
	
	// bucle para imprimir una torre de 3 asteriscos de ancho
	for (int i = 0; i < alto/3; i++)
	{
		//bucle que imprime espacios
		for (int j = 0; j < espacio-1; j++)
        {
            cout << " ";
        }
        //bucle que imprime asteriscos
        for (int k = 0; k < 3; k++)
        {
            cout << "*";
        }
        //salto de linea
        cout << endl;
        //se le resta uno al espacio para que se vuelva a imprimir
        espacio--;
    }
	return 0;
}