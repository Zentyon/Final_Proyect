#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <vector>

using namespace std;


struct datos {
	int day, month, year;
	string title;
	vector<string> text;
};


class notepad {
	protected:
		int day, mont, year;
	public:

		void save();
		datos read();
};

void notepad :: save() {
	ofstream nota("new_note.txt");
	string info;

	if(nota.fail()) {
		cout << "No se puede abrir el archivo";
		exit(1);
	}

	cout << "Fecha separada por espacios: ";
	getline(cin, info);

	string title;

	cout << "Titulo: ";
	getline(cin, title);
	nota << info << endl;
	nota << title << endl;

	cout << "Ingrese su mensaje: " << endl;

	string message = "...";
	while(message != "")
	{
		getline(cin, message);
		nota << message << endl;
	}

	nota.close(); //cierra el archivo
}

datos notepad :: read() {
	ifstream nota("new_note.txt");
	string texto;
	vector<string> aviso;

	if(!nota.is_open()) {
		cout << "no se pudo leer el archivo";
		exit(1);
	}

	int day, month, year;
	nota >> day >> month >> year;

	string titulo;
	nota.ignore();

	getline(nota, titulo);

	while (getline(nota, texto)) { // eof : mientras no sea el final del archivo
		aviso.push_back(texto);
		cout << texto << endl;
	}

	nota.close();

	return datos {
		day, month, year, titulo, aviso
	};
}


int main() {
	notepad user;

	user.save();
	datos recibidos = user.read();

	//user.edit();
	user.read();
	cout << "Fecha:  " << recibidos.day << '/' << recibidos.month << '/' << recibidos.year << '\n';
	cout << "Titulo: " << recibidos.title << '\n';
	cout << "Mensaje:\n";
	for(string linea_del_aviso: recibidos.text)
		cout << linea_del_aviso << '\n';

}
