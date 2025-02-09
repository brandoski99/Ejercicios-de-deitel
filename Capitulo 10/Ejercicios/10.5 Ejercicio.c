#include <stdint.h>
#include <stdio.h>
/* A */
struct inventario {
  char nombreParte[30];
  int numeroParte;
  float precio;
  int almacen;
  int resurtir;
};

/* B */
union datos {
  char c;
  short s;
  long b;
  float f;
  double d;
};

/* C */
struct direccion {
  char direccionCalle[25];
  char ciudad[20];
  char estado[3];
  char codigoPostal[6];
};

/* D */
struct estudiante {
  char nombre[15];
  char apellido[15];
  struct direccion direccionCasa;
};

/* E */
struct prueba {
  short int a : 1;
  short int b : 1;
  short int c : 1;
  short int d : 1;
  short int e : 1;
  short int f : 1;
  short int g : 1;
  short int h : 1;
  short int i : 1;
  short int j : 1;
  short int k : 1;
  short int l : 1;
  short int m : 1;
  short int n : 1;
  short int o : 1;
  short int p : 1;
};

int main() {
  printf("%ld", sizeof(short int));
  return 0;
}
