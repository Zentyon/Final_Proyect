#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;


class notepad{
protected:
  int day, mont, year;
  string aviso = "This is a Test";
public:

  void save();
  void read();
  void edit();
  void popup();
 };


void notepad :: save(){
   ofstream nota;
   string info;

   nota.open("new_note.txt", ios::out); //abre el archivo
   if(nota.fail()){
       cout << "No se puede abrir el archivo";
       exit(1);
   }
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

void notepad :: popup(){
  // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
int msgboxID = MessageBox(
        NULL,
        aviso.c_str(),
        "AVISO IMPORTANTE",
        MB_ICONASTERISK
    );
}


int main(){
  notepad user;

  user.save();
  user.read();
  user.edit();
  user.read();

  user.popup();

  return 0;
}
