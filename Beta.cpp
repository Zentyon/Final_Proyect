#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;
auto today(){ return(system("DATE/T"));}


class nucleo
{
  protected:
    int nothing = 0;
  public:
    int size = 0;
    nucleo(){size = load_setup();}
    int load_setup(){

      string str;
      int num = 0, size = str.size();

      ifstream base;
      base.open("setup.txt", ios :: in);

        getline(base, str);
        cout << str<< '\n';
        for(int i = 0; i < str.size(); i++) {
        num *= 10;
        num += str[i]-'0';
      }
      base.close();
      return num;
    }

    void save_setup( int input){
        string str;
        int num = load_setup();
        ofstream save;
          stringstream s;
          save.open("setup.txt", ios::out);
          num = num + input;
          s << num;
          str = s.str();
          save << str;
        save.close();
    }
};

class notepad : public nucleo{
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

    /*cout << "Escribe el Titulo: ";
    getline(cin, title);

    archivo.open(title.c_str(), ios::out);*/

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





int main(){
  nucleo user;
  int *quant;
  int max = user.size;
  quant = new int[max];


   //cad = new int[cantidad];

  int option = 1;
  cout << "\n\tWellcome!\n" << endl;
  cout << "Today is: "; cout << today() << endl;

do {
    cout << "\nQue deseas hacer?\n\t1- Agregar nueva nota \n\t2- Ver notas guardadas\n\t3- Eliminar nota\n\t0- Salir\n\n\tTeclea el numero de la opcion:";
    cin >> option;

    switch (option){
      case 0: exit(-1);
            break;
      case 1:
            system("CLS");
            notas[i].save();
            break;
      case 2:
            system("CLS");
            notas[i].read();
            break;
      case 3:
          system("CLS");
            cout << "Eliminado"<< endl;
            notas[i].delit();
            break;
      default: cout << "Opcion invalida, Intenta de nuevo: ";
      }
    }
  while (option !=0);

}
