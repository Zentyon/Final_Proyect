#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>


using namespace std;

class notepad{
protected:
  int day, mont, year;
public:
  
  void save();
  void read();
  void edit();
 };


void notepad :: save(){
   ofstream nota;
   string info;

   nota.open("new_note.txt", ios::out); //abre el archivo
   if(nota.fail()){
       cout << "No se puede abrir el archivo";
       exit(1);
   }

   nota << "Hola Mundo!\n";

   cout << "Descripcion: ";
   getline(cin, info);

   nota << info;

   nota.close(); //cierra el archivo
 }

void notepad :: read(){
  ifstream nota;
  string texto;

  nota.open("new_note.txt", ios :: in);

  if(nota.fail()){
    cout << "no se pudo leer el archivo";
    exit(1);
  }

  while (!nota.eof()) { // eof : mientras no sea el final del archivo
    getline(nota, texto);
    cout << texto << endl;
  }
  nota.close();
}

void notepad :: edit(){
  ofstream nota;
  string texto;

  nota.open("new_note.txt", ios::app);

  if(nota.fail()){
    cout << "no se pudo leer el archivo";
    exit(1);
  }

  cout << "\n Edita la wea: ";

  getline(cin,texto);

  nota << texto << endl;

  nota.close();
}

int main(){
  notepad user;



  user.save();
  user.read();
  user.edit();
  user.read();

  return 0;
}
