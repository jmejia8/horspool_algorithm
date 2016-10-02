#include <iostream>
#include <fstream>
#include <string>

#include "tools.h"


int search (string pattern, string file_name){
	// Apertura del texto
	ReadData Text(file_name);
	
	// Tabla de saltos en los símbolos
	Table table(pattern);

	int skip, i;
	int pattern_len = pattern.length();
	int line_len;

	// Encuentra patron por linea en el archivo de
	// texto
	string line = Text.readLine();

	cout << ">>> Starting search." << endl;


	do{
		line_len = line.length();

		skip = 0;

		// por cada línea, busca el patron deseado
		while (line_len - skip >= pattern_len){
			i = pattern_len - 1;

			// Verifica que con el salto dato
			// estemos encontrado un concidencia
			// con el patrón
			while ( i >= 0 && line[skip + i] == pattern[i]){
				i--;
			}

			// En caso de encontrarse el patrón muestra
			// la línea donde fue  hallado
			if (i < 0){
				cout << "\n>>>> Text found it in:\n" << line << endl;
				cout << "Column: " << skip << endl;
				Text.closeFile();
				return skip;
			}

			// realiza el salto requerido según 
			// esté en la tabla
			char caracter = line[skip + pattern_len - 1];
			skip += table.getValue(caracter);

		}

		line = Text.readLine();

	} while(line.length() > 0);


	cout << ">>> Text not found. :(" << endl;

	Text.closeFile();

	return 0;
}

int main(int argc, char const *argv[])
{
	// cadena que se buscará
	string pattern = "God created the heaven";

	// texto donde se debe buscar
	string file_name = "text/sample.txt";

	search(pattern, file_name);

	return 0;
}