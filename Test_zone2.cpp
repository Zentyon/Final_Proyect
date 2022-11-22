#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <vector>

using namespace std;
class notepad{
protected:
  string day, mont, year;
  string aviso = "This is a Test";
	string title;
	string texto;
	string linea;
public:

  void save();
  void read();
 };


void notepad :: save(){
   ofstream nota;
   nota.open("new_note.txt", ios::out); //abre el archivo
   if(nota.fail()){
       cout << "No se puede abrir el archivo";
       exit(1);
   }
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
void notepad :: read(){
  ifstream nota;

  nota.open("new_note.txt", ios :: in);

  if(nota.fail()){
    cout << "no se pudo leer el archivo";
    exit(1);
  }

  while (getline(nota,linea)) {
    texto = texto + linea + '\n';
  }
  nota.close();
	cout << texto << endl;
}



int main(){
  notepad user;
  user.read();

  return 0;
}
