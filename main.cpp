#include <iostream>

#include <cstdlib> //Librer�a para poder usar la funci�n rand o srand.

#include <ctime> //Librer�a para utilizar la hora actual como valor semilla en el srand

using namespace std;

// Declaraci�n de variables
char continuar = 's';
int jugadores = 0;
char jugador1[15];
char jugador2[15];
char jugador3[15];
int tabla = 0;
int matrizj1[3][3];
int matrizj2[3][3];
int matrizj3[3][3];
int tombola();
int ns = 0;
void imp_tombola();
int vect[100];
void carton(int matriz[][3], int tabla);
void imp_carton(int matriz[][3]);
int nf;
int nc;
void revisar_carton(int matriz[][3], int nf, int nc, int resultado_multi);
char marcar = 's';
bool ganador(int matriz[][3]);

//Cuerpo del programa

int main() {
  srand(time(0));//Utilizo srand para que cada vez que se ejecute el programa se cree una salida diferente de n�meros aleatorios.
  cout << " |_______Bienvenido al juego de Bingo_________|" << endl;
  cout << endl;
  // Inicio con bucle para poder continuar el juego si el usuario lo desea.
  while (continuar == 's' || continuar == 'S') {
    cout << endl;
    cout << "Digite la cantidad de jugadores (2 o 3)" << endl;
    cin >> jugadores;
   while (jugadores !=2 && jugadores !=3) {
    cout << "Solo pueden jugar minimo 2 y maximo 3 jugadores" << endl;
    cout << endl;
    cout << "Digite la cantidad de jugadores (2 o 3)" << endl;
    cin >> jugadores;
    cout << endl;
  }


    if (jugadores == 2) {
      cout << "Digite el nombre del primer jugador" << endl;
      cin >> jugador1;
      cout << "Digite el nombre del segundo jugador" << endl;
      cin >> jugador2;
    } else {
      cout << "Digite el nombre del primer jugador" << endl;
      cin >> jugador1;
      cout << "Digite el nombre del segundo jugador" << endl;
      cin >> jugador2;
      cout << "Digite el nombre del tercer jugador" << endl;
      cin >> jugador3;
    }
    cout <<endl;
    cout << "indique la tabla del 1 al 9 con la que desean jugar" << endl;
    cin >> tabla;
    cout <<endl;
    while (tabla<1 || tabla>9){
        cout << "Debe digitar una tabla entre 1 y 9" << endl;
        cout <<endl;
        cin >> tabla;
    }

    //Genero un condicional para generar el juego de acuerdo con la cantidad de jugadores.

    if (jugadores == 2) {
      // Llamado de funciones para el llenado e impresi�n de los respectivos cartones de los jugadores.
      carton(matrizj1, tabla);
      cout <<endl;
      cout << "Carton de " << jugador1 << endl;
      cout << endl;
      imp_carton(matrizj1);
      cout << endl;
      carton(matrizj2, tabla);
      cout << "Carton de " << jugador2 << endl;
      cout << endl;
      imp_carton(matrizj2);
      cout << endl;

      // Bucle para que se genere t�mbola siempre que los cartones a�n no sean ganadores.
      while (ganador(matrizj1) == false && ganador(matrizj2) == false && ns<=19) {
        int resultado_multi = tombola(); //Llamo a la funci�n t�mbola, para mostrarle a los jugadores la tabla de multiplicar.

        // Condicional, para consultar al jugador si desea marcar un n�mero en su cart�n.
        cout << jugador1 << " " << "Desea marcar su carton? (Digite S o N) " << endl;
        cin >> marcar;
        while (marcar != 's' && marcar != 'S' && marcar != 'n' && marcar != 'N'){
          cout << jugador1 << " " << "Debe digitar S o N" << endl;
          cin >> marcar;
        }

        if (marcar == 's' || marcar == 'S') {
          cout << jugador1 << " " << "indique la fila y columna donde se encuentra el resultado" << endl;
          cout << "Fila: ";
          cin >> nf;
          cout << "Columna: ";
          cin >> nc;
          revisar_carton(matrizj1, nf, nc, resultado_multi);
        }
        cout <<endl;
        cout << "Carton de " << jugador1 << endl;
        cout << endl;
        imp_carton(matrizj1);
        cout << endl;

        cout << jugador2 << " " << "Desea marcar su carton? (Digite S o N) " << endl;
        cin >> marcar;
        while (marcar != 's' && marcar != 'S' && marcar != 'n' && marcar != 'N'){
          cout << jugador2 << " " << "Debe digitar S o N" << endl;
          cin >> marcar;
        }
        if (marcar == 's' || marcar == 'S') {
          cout << jugador2 << " " << "Indique la fila y columna donde se encuentra el resultado" << endl;
          cout << "Fila: ";
          cin >> nf;
          cout << "Columna: ";
          cin >> nc;
          revisar_carton(matrizj2, nf, nc, resultado_multi);
        }
        cout <<endl;
        cout << "Carton de " << jugador2 << endl;
        cout << endl;
        imp_carton(matrizj2);
        cout << endl;
        //Se llama funci�n para imprimir de manera acumulativa, cada n�mero que ha salido en la t�mbola.
        cout << "Los numeros que han salido son: ";
        imp_tombola();
        cout << endl;


        //Revision de cartones para determinar si existen ganadores o empates en el juego de 2 jugadores.

        if (ganador(matrizj1) == true && ganador(matrizj2) == true) {
          cout << "Hay un empate entre los jugadores: " << jugador1 << "y" << jugador2 << endl;
        }
        if (ganador(matrizj1) == true && ganador(matrizj2) == false) {
          cout << "El ganador del juego es: " << jugador1 << endl;
        }
        if (ganador(matrizj1) == false && ganador(matrizj2) == true) {
          cout << "El ganador del juego es: " << jugador2 << endl;
        }
        if (ns >19 && ganador(matrizj1) == false && ganador(matrizj2) == false) {
          cout << endl;
          cout << "No hay ningun ganador del Bingo "<< endl;
        }
    }

      //Juego para tres jugadores
    } else {
      // Llamado de funciones para el llenado e impresi�n de los respectivos cartones de los jugadores.
      carton(matrizj1, tabla);
      cout <<endl;
      cout << "Carton de " << jugador1 << endl;
      cout << endl;
      imp_carton(matrizj1);
      cout << endl;
      carton(matrizj2, tabla);
      cout << "Carton de " << jugador2 << endl;
      cout << endl;
      imp_carton(matrizj2);
      cout << endl;
      carton(matrizj3, tabla);
      cout << "Carton de " << jugador3 << endl;
      cout << endl;
      imp_carton(matrizj3);
      cout << endl;

      // Bucle para que se genere t�mbola siempre que los cartones a�n no sean ganadores.

      while (ganador(matrizj1) == false && ganador(matrizj2) == false && ganador(matrizj3) == false && ns<=19) {
        int resultado_multi = tombola(); //Llamo a la funci�n t�mbola, para mostrarle a los jugadores la tabla de multiplicar.

        // Condicional, para consultar al jugador si desea marcar un n�mero en su cart�n.
        cout << jugador1 << " " << "Desea marcar su carton? (Digite S o N) " << endl;
        cin >> marcar;
        while (marcar != 's' && marcar != 'S' && marcar != 'n' && marcar != 'N') {
          cout << jugador1 << " " << "Debe digitar S o N " << endl;
          cin >> marcar;
        }
        if (marcar == 's' || marcar == 'S') {
          cout << jugador1 << " " << "indique la fila y columna donde se encuentra el resultado" << endl;
          cout << "Fila: ";
          cin >> nf;
          cout << "Columna: ";
          cin >> nc;
          revisar_carton(matrizj1, nf, nc, resultado_multi);
        }
        cout <<endl;
        cout << "Carton de " << jugador1 << endl;
        cout << endl;
        imp_carton(matrizj1);
        cout << endl;

        cout << jugador2 << " " << "Desea marcar su carton? (S o N) " << endl;
        cin >> marcar;
        while (marcar != 's' && marcar != 'S' && marcar != 'n' && marcar != 'N') {
          cout << jugador2 << " " << "Debe digitar S o N " << endl;
          cin >> marcar;
        }
        if (marcar == 's' || marcar == 'S') {
          cout << jugador2 << " " << "indique la fila y columna donde se encuentra el resultado" << endl;
          cout << "Fila: ";
          cin >> nf;
          cout << "Columna: ";
          cin >> nc;
          revisar_carton(matrizj2, nf, nc, resultado_multi);
        }
        cout <<endl;
        cout << "Carton de " << jugador2 << endl;
        cout << endl;
        imp_carton(matrizj2);
        cout << endl;

        cout << jugador3 << " " << "Desea marcar su carton? (S o N) " << endl;
        cin >> marcar;
        while (marcar != 's' && marcar != 'S' && marcar != 'n' && marcar != 'N') {
          cout << jugador3 << " " << "Debe digitar S o N " << endl;
          cin >> marcar;
        }
        if (marcar == 's' || marcar == 'S') {
          cout << jugador3 << " " << "indique la fila y columna donde se encuentra el resultado" << endl;
          cout << "Fila: ";
          cin >> nf;
          cout << "Columna: ";
          cin >> nc;
          revisar_carton(matrizj3, nf, nc, resultado_multi);
        }
        cout <<endl;
        cout << "Carton de " << jugador3 << endl;
        cout << endl;
        imp_carton(matrizj3);
        cout << endl;

        // Muestro n�meros que han salido en la t�mbola acumulados,con la respectiva funci�n.
        cout << "Los numeros que han salido son: ";
        imp_tombola();
        cout << endl;

        //Revision de cartones para determinar si existen ganadores o empates, seg�n juego para tres jugadores.

        if (ganador(matrizj1) == true && ganador(matrizj2) == true && ganador(matrizj3) == true) {
          cout << "Hay un empate entre los jugadores: " << jugador1 << "," << jugador2 << "y" << jugador3 << endl;
        }
        if (ganador(matrizj1) == true && ganador(matrizj2) == true && ganador(matrizj3) == false) {
          cout << "Hay un empate entre los jugadores: " << jugador1 << "y" << jugador2 << endl;
        }
        if (ganador(matrizj1) == true && ganador(matrizj3) == true && ganador(matrizj2) == false) {
          cout << "Hay un empate entre los jugadores: " << jugador1 << "y" << jugador3 << endl;
        }
        if (ganador(matrizj2) == true && ganador(matrizj3) == true && ganador(matrizj1) == false) {
          cout << "Hay un empate entre los jugadores: " << jugador2 << "y" << jugador3 << endl;
        }

        if (ganador(matrizj1) == true && ganador(matrizj2) == false && ganador(matrizj3) == false) {
          cout << "El ganador del juego es: " << jugador1 << endl;
        }
        if (ganador(matrizj2) == true && ganador(matrizj1) == false && ganador(matrizj3) == false) {
          cout << "El ganador del juego es: " << jugador2 << endl;
        }
        if (ganador(matrizj3) == true && ganador(matrizj2) == false && ganador(matrizj1) == false) {
          cout << "El ganador del juego es: " << jugador3 << endl;
        }
         if (ns >19 && ganador(matrizj1) == false && ganador(matrizj2) == false && ganador(matrizj3) == false) {
          cout << endl;
          cout << "No hay ningun ganador del Bingo "<< endl;
        }

      }

    }
    //Bucle para que el usuario digite S o N y continue jugando o salga del programa.
    cout << endl;
    cout << "Desea continuar jugando (Digite S o N) " << endl;
    cin >> continuar;
    while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
      cout << "Debe digitar S o N " << endl;
      cin >> continuar;
      jugadores = 0;
    }
    jugadores = 0;//Restablezco jugadores a cero, para poder ingresar al b�cle que solicita la cantidad de jugadores, en caso de que deseen seguir jugando.
    ns=0; //Restablezco el contador del vector para que arranque de nuevo en la casilla cero.
  }

  return 0;
}

// En adelante se crean las funciones que ser�n llamadas y utilizadas a lo largo del programa para las distintas funcionalidades.

//Funci�n para que no se repita el n�mero que sale en la t�mbola.
bool norepetir_tomb(int resultado_multi) {
  for (int v = 0; v < ns; v++) {
    if (resultado_multi == vect[v]) return false;
  }
  return true;
}

//Funci�n de t�mbola, que genera multiplicaciones aleatorias de acuerdo con la tabla elegida por los jugadores y retorna el resultado de la multiplicaci�n.
int tombola() {
  int multiplicando = 1 + (rand() % 20); //Con esta funci�n rand, se generan n�meros aleatorios entre 1 y 20.
  int resultado_multi = multiplicando * tabla;
  while (norepetir_tomb(resultado_multi) == false) {
    multiplicando = 1 + (rand() % 20);
    resultado_multi = multiplicando * tabla;
  }
  cout << endl;
  cout << " " << multiplicando << "*" << tabla << " = ?" << endl;
  cout << endl;
  vect[ns] = resultado_multi;
  ns += 1;
  return resultado_multi;
}

//Funci�n para imprimir los n�meros que salen en la t�mbola, por medio de un vector que los acumula.
void imp_tombola() {
  for (int v = 0; v <ns; v++) {
    cout << vect[v] << " ";
  }
}

// Funci�n booleana, utilizada para asegurar que dentro de un mismo cart�n, no se repita un n�mero.
bool norepetir(int matriz[][3], int rest_aleatorio) {
  for (int f = 0; f < 3; f++) {
    for (int c = 0; c < 3; c++) {
      if (rest_aleatorio == matriz[f][c]) {
        return false;
      }
    }
  }
  return true;
}

//Funci�n para recorrer y llenar una matriz con resultados de multiplicaci�n aleatorios y sin repetir, que ser�n los cartones de cada jugador.
void carton(int matriz[][3], int tabla) {
  for (int f = 0; f < 3; f++) {
    for (int c = 0; c < 3; c++) {
      int rest_aleatorio = (1 + (rand() % 20)) * tabla;
      while (norepetir(matriz, rest_aleatorio) == false) {
        rest_aleatorio = (1 + (rand() % 20)) * tabla;
      }
      matriz[f][c] = rest_aleatorio;
    }
  }
}

//Funci�n para imprimir las matrices (cartones) de los jugadores.
void imp_carton(int matriz[][3]) {
  for (int f = 0; f < 3; f++) {
    for (int c = 0; c < 3; c++) {
      printf("|%3d| ", matriz[f][c]); // Utilizo printf, para poder imprimir la matriz de forma organizada con espacios de tres d�gitos en cada casilla.
    }
    cout << "\n";
  }
}

//Funci�n para revisar el cart�n de los jugadores, validar si la respuesta es correcta y cambiar los digitos a cero o enviar mensaje de error.
void revisar_carton(int matriz[][3], int nf, int nc, int resultado_multi) {
  if (resultado_multi == matriz[nf][nc]) {
    matriz[nf][nc] = 0;
  } else {
    cout <<endl;
    cout << "Su respuesta es incorrecta" << endl;
  }

}

//Funci�n booleana que retorne false cuando la matriz sea distinta de cero y as� saber si existe o no un ganador.
bool ganador(int matriz[][3]) {
  for (int f = 0; f < 3; f++) {
    for (int c = 0; c < 3; c++) {
      if (matriz[f][c] != 0) {
        return false;
      }
    }
  }
  return true;
}
