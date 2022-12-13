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
auto today(){ return(system("DATE/T"));} //Fecha de del sistema

class heart //Clase Raíz
{
  protected:
    int nothing = 0;
  public:
    int size = 0;
    string actual;
    heart(){size = load_setup();}
    int load_setup(){
      string str;
      int num = 0, size = str.size();
      ifstream base;
      base.open("setup.txt", ios :: in);
        getline(base, str);
        for(int i = 0; i < str.size(); i++) {
        num *= 10;
        num += str[i]-'0';
      }
      base.close();
      return num;
    }   //Carga el valor del setup como int

    void save_setup(int input){
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
    }   //Guarda el valor del setup como string

    string current(){
      ifstream add;
      add.open("setup.txt", ios :: in);
      getline(add,actual);
      add.close();
      return actual;
    };  //Carga el valor del setup como string
};

class notepad : public heart{
protected:
  string day, month, year;
  string aviso = "This is a Test";
	string title;
	string texto;
	string linea;
  string nombre;
public:
  void save();
  void read(int);
  void delit(int);
  void popup();
  void name(int);
};   //Clase Heredada

 void notepad :: save(){
    fflush(stdin);
    save_setup(1);
    nombre = current() + ".txt";
    ofstream nota;
    nota.open(nombre.c_str(), ios::out); //abre el archivo

    cout << "\t--NUEVA NOTA--\n" << endl;
    cout << "Titulo: ";
      getline(cin, title); nota << title	<< '\n';
    cout << "Day: ";
      getline(cin, day);		nota << day	<< '\n';
    cout << "Month: ";
      getline(cin, month);	nota << month << '\n';
    cout << "Year: ";
      getline(cin, year);	nota << year << '\n';
    cout << "Descripcion: ";
      getline(cin, texto);	nota << texto << '\n';

    nota.close(); //cierra el archivo

 }

 void notepad :: read(int c){
  fflush(stdin);
  system("CLS");
  stringstream s;
  s << c;
  string str =  s.str() + ".txt";
  ifstream nota;
  nota.open(str.c_str(), ios :: in);

  if(nota.fail()){
    cout << "no se pudo leer el archivo\n";
  }

  else{
    getline(nota, title); cout << title << endl;
    getline(nota, day); cout << day << "/";
    getline(nota , month); cout << month  << "/";
    getline(nota, year); cout << year << endl;
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

 void notepad :: delit(int c){
   stringstream s;
   s << c;
   string str =  s.str() + ".txt";
   remove(str.c_str());
  system("CLS");
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

 void notepad :: name(int temp){
  stringstream s;
  s << temp;
  ifstream nota;
  string str =  s.str() + ".txt";
  nota.open(str.c_str(), ios :: in);
  getline(nota,nombre);
  nota.close();
  cout << nombre;
}


int main(){

  int n_obj = 0;
  int option = 1;
  int submenu = 0;
  cout << "\n\tWellcome!\n" << endl;
  cout << "Today is: "; cout << today() << endl;

do {
  heart user; //inicializa setup
  notepad *notas;
  notas = new notepad[1000];

    cout << "\nQue deseas hacer?\n\t1- Agregar nueva nota \n\t2- Ver notas guardadas\n\t3- Eliminar nota\n\t0- Salir\n\n\tTeclea el numero de la opcion:";
    cin >> option;

    switch (option){
      case 0: exit(-1);
            break;
      case 1:
            system("CLS");
            (notas+n_obj) -> save();
            n_obj++;
            fflush(stdin);
            break;
      case 2:
            system("CLS");
            cout<<"\n------------------------------------------------------"<<endl;
            cout<<" LISTA DE NOTAS "<<endl;
            cout<<"------------------------------------------------------"<<endl;
            n_obj = user.size;
            for (int i = 0; i < n_obj; i++)
            { cout << "Nota " << i+1 << ":";
            (notas+i) -> name(i+1);
            cout << "\n";
            }
            cout << "\n\nIntroduce el numero de nota que deseas leer: ";
            cin >> submenu;
            (notas)->read(submenu);
                  system("CLS");
            fflush(stdin);
            break;
      case 3:
          system("CLS");
          cout<<"\n------------------------------------------------------"<<endl;
          cout<<" LISTA DE NOTAS "<<endl;
          cout<<"------------------------------------------------------"<<endl;
          n_obj = user.size;
          for (int i = 0; i < n_obj; i++)
          { cout << "Nota " << i+1 << ":";
          (notas+i) -> name(i+1);
          cout << "\n";
          }
          cout << "\n\nIntroduce el numero de nota que deseas Eliminar: ";
          cin >> submenu;
          (notas)->delit(submenu);
          cout << "Nota Eliminada\n";
          fflush(stdin);
            break;
      default: cout << "Opcion invalida, Intenta de nuevo: ";
      }
      delete [ ] notas;
    }
  while (option !=0);

}
