#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;

auto date()
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss <<  put_time(&tm, "%d-%m-%Y");
    auto str = oss.str();
    return str;
}


struct datos {
	int day, month, year;
	string title;
	vector<string> text;
};

class notepad {
protected:
  string day, mont, year;
  string aviso = "This is a Test";
	string title;
	string texto;
	string linea;
public:

  void save();
  void read();
  void delit();
  void popup();
 };


 void notepad :: save(){
    ofstream nota;
    nota.open("new_note.txt", ios::out); //abre el archivo
    if(nota.fail()){
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    cout << "\t\tNueva Nota\n";
      getline(cin, linea);
    cout << "Titulo: ";
      getline(cin, title); nota << title	<< '\n';
 	  cout << "Day: ";
 	    getline(cin, day);		nota << day	<< '\n';
 	  cout << "Month: ";
 	    getline(cin, mont);	nota << mont << '\n';
 	  cout << "Year: ";
 	    getline(cin, year);	nota << year << '\n';
 	  cout << "Descripcion: ";
 	    getline(cin, texto);	nota << texto << '\n';

    nota.close(); //cierra el archivo
 }


/*datos notepad :: read() {
	ifstream nota("new_note.txt");
	vector<string> aviso;

	if(!nota.is_open()) {
		cout << "no se pudo leer el archivo";
		//exit(1);
	}

  string titulo;
	nota.ignore();

	int day, month, year;
	nota >> day >> month >> year;


	getline(nota, titulo);

	while (getline(nota, texto)) { // eof : mientras no sea el final del archivo
		aviso.push_back(texto);
		cout << texto << endl;
	}

	nota.close();

	return datos {
		day, month, year, titulo, aviso
	};
}*/

void notepad :: read(){
  ifstream nota;
  nota.open("new_note.txt", ios :: in);

  if(nota.fail()){
    cout << "no se pudo leer el archivo\n";
  }
  
  else{
    while (getline(nota,linea)) {
      texto = texto + linea + '\n';
    }
    cout << texto << endl;
  }
  nota.close();

  cout << "Presiona ENTER para continuar" << '\n';
  getch ();
  system("CLS");
}


void notepad :: delit(){
  remove("new_note.txt");
}

void notepad :: popup(){
  // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
int msgboxID = MessageBox(
        NULL,
        aviso.c_str(),
        "AVISO IMPORTANTE",
        MB_ICONASTERISK
    );
}


/*int interfaz :: mainMenu(){


}

int interfaz :: menu1(){
  system ("CLS");
}
*/

int main(){
  notepad user;

  int option = 1;
  cout << "\n\tWellcome!\n" << endl;
  cout << "Today is: " << date() << endl;

do {
    cout << "\nQue deseas hacer?\n\t1- Agregar nueva nota \n\t2- Ver notas guardadas\n\t3- Eliminar nota\n\t0- Salir\n\n\tTeclea el numero de la opcion:";
    cin >> option;

    switch (option){
      case 0: exit(-1);
            break;
      case 1:
            system("CLS");
            user.save();
            break;
      case 2:
            system("CLS");
            user.read();
            break;
      case 3:
          system("CLS");
            cout << "Eliminado"<< endl;
            user.delit();

            break;
      default: cout << "Opcion invalida, Intenta de nuevo: ";
      }
    }
  while (option !=0);

  return 0;
}
