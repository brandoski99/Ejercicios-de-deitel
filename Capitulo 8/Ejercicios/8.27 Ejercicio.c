#include <stdio.h>
double atof(const char *ptrN); // Convierte la cadena ptrN a double.
int atoi(const char *ptrN);    // Convierte la cadena ptrN a int.
long atol(const char *ptrN);   // Convierte la cadena ptrN a long int.
double strtod(const char *ptrN,
              char **ptrFinal); // Convierte la cadena ptrN a double.
long strtol(const char *ptrN, char **ptrFinal,
            int base); // Convierte la cadena ptrN a long.
unsigned long strtoul(const char *ptrN, char **ptrFinal,
                      int base); // Convierte la cadena ptrN a unsigned long
int main() {
  char string[100];
  char *leftlovers;
  fgets(string, sizeof(string), stdin);
  printf("los numeros son: %.2f\n", strtod(string, &leftlovers));
  printf("El resto de la cadena: %s", leftlovers);
  return 0;
}

double atof(const char *ptrN) {
  float result = 0.0;
  float fraction = 1.0;
  int i = 0;
  int sign = 1;

  // Si encuentra un espacio lo ignora
  while (ptrN[i] == ' ') {
    i++;
  }
  // Asigna el signo negativo
  if (ptrN[i] == '-') {
    sign = -1;
    i++;
  } else if (ptrN[i] == '+') { // Asigna el signo positivo
    i++;
  }

  // Convierte los caracteres a numeros
  while (ptrN[i] >= '0' && ptrN[i] <= '9') {
    result = result * 10.0 + (ptrN[i] - '0');
    i++;
  }
  // Si encuentra un punto flotante agrega la parte decimal
  if (ptrN[i] == '.') {
    i++;
    while (ptrN[i] >= '0' && ptrN[i] <= '9') {
      fraction /= 10.0;
      result += (ptrN[i] - '0') * fraction; // Agrega el digito decimal
      i++;
    }
  }
  // retornar numero y aplicar signo
  return result * sign;
}

int atoi(const char *ptrN) {
  int result = 0;
  int i = 0;
  int sign = 1;

  // Si encuentra un espacio lo ignora
  while (ptrN[i] == ' ') {
    i++;
  }
  // Asigna el signo negativo
  if (ptrN[i] == '-') {
    sign = -1;
    i++;
  } else if (ptrN[i] == '+') { // Asigna el signo positivo
    i++;
  }

  // Convierte los caracteres a numeros
  while (ptrN[i] >= '0' && ptrN[i] <= '9') {
    result = result * 10 + (ptrN[i] - '0');
    i++;
  }

  // retornar numero y aplicar signo
  return result * sign;
}

long atol(const char *ptrN) {
  long result = 0;
  int i = 0;
  int sign = 1;

  // Si encuentra un espacio lo ignora
  while (ptrN[i] == ' ') {
    i++;
  }
  // Asigna el signo negativo
  if (ptrN[i] == '-') {
    sign = -1;
    i++;
  } else if (ptrN[i] == '+') { // Asigna el signo positivo
    i++;
  }

  // Convierte los caracteres a numeros
  while (ptrN[i] >= '0' && ptrN[i] <= '9') {
    result = result * 10 + (ptrN[i] - '0');
    i++;
  }

  // retornar numero y aplicar signo
  return result * sign;
}
double strtod(const char *ptrN, char **ptrFinal) {
  double result = 0.0;
  double fraction = 1.0;
  int i = 0;
  int sign = 1;

  // Si encuentra un espacio lo ignora
  while (ptrN[i] == ' ') {
    i++;
  }
  // Asigna el signo negativo
  if (ptrN[i] == '-') {
    sign = -1;
    i++;
  } else if (ptrN[i] == '+') { // Asigna el signo positivo
    i++;
  }

  // Convierte los caracteres a numeros
  while (ptrN[i] >= '0' && ptrN[i] <= '9') {
    result = result * 10.0 + (ptrN[i] - '0');
    i++;
  }
  // Si encuentra un punto flotante agrega la parte decimal
  if (ptrN[i] == '.') {
    i++;
    while (ptrN[i] >= '0' && ptrN[i] <= '9') {
      fraction /= 10.0;
      result += (ptrN[i] - '0') * fraction; // Agrega el digito decimal
      i++;
    }
  }

  // Verifica que ptrFinal no sea NULL
  if (ptrFinal) {
    if (ptrN[i] != '\0') {
      *ptrFinal = (char *)&ptrN[i];
    } else {
      *ptrFinal = NULL;
    }
  }
  // retornar numero y aplicar signo
  return result * sign;
}
