#include <stdio.h>
#include <string.h>

struct cliente {
  char apellido[15];
  char nombre[15];
  int numeroCliente;
  struct {
    char numeroTelefonico[11];
    char direccion[50];
    char ciudad[15];
    char estado[3];
    char codigoPostal[6];
  } personal;
} registroCliente, *ptrCliente = &registroCliente;

int main() {
  // a
  strcpy(registroCliente.apellido, "Machado");
  // b
  strcpy(ptrCliente->apellido, "Corina");
  // c
  scanf("%14s", registroCliente.nombre);
  // d
  scanf("%14s", ptrCliente->nombre);
  // e
  registroCliente.numeroCliente = 10;
  // f
  ptrCliente->numeroCliente = 01;
  // g
  scanf("%10s", registroCliente.personal.numeroTelefonico);
  // h
  scanf("%10s", ptrCliente->personal.numeroTelefonico);
  // i
  fgets(registroCliente.personal.direccion,
        sizeof(registroCliente.personal.direccion), stdin);
  // j
  fgets(ptrCliente->personal.direccion, sizeof(ptrCliente->personal.direccion),
        stdin);
  // k
  registroCliente.personal.ciudad;
  // l

  ptrCliente->personal.ciudad;
  // m
  registroCliente.personal.estado;
  // n
  ptrCliente->personal.estado;
  // o
  registroCliente.personal.codigoPostal;
  // p
  ptrCliente->personal.codigoPostal;
  return 0;
}
