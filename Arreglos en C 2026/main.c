#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <stdio.h>

void recorrer();
void por_parametro();
void retornar();
void coordenadas();
void por_parametro_2();
void por_parametro_bidimensional();
void puntajes();
void tamanio_del_arreglo();

// ===== UTILIDADES =====
// Limpia el buffer de entrada (stdin)
void limpiar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// Limpia pantalla dependiendo del sistema operativo
void limpiar_pantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Lee un entero validando entrada
int leer_entero(const char *mensaje) {
  int valor;
  int resultado;

  do {
      printf("%s", mensaje);
      resultado = scanf("%d", &valor);
       if (resultado != 1) {
          printf("Entrada inválida. Debe ingresar un número.\n");
          limpiar_buffer();
      }
  } while (resultado != 1);

  limpiar_buffer(); // limpia \n restante
  return valor;
}

// Lee opción s/n validando
char leer_sn(const char *mensaje) {
  char c;

  while (1) {
      printf("%s", mensaje);

      if (scanf(" %c", &c) != 1) {
          limpiar_buffer();
          continue;
      }

      limpiar_buffer();

      if (c == 's' || c == 'S' || c == 'n' || c == 'N') {
          return c;
      }

      printf("Entrada inválida. Ingrese 's' o 'n'.\n");
  }
}

int main() {

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  int opcion;
  char repetir;

  do {
      limpiar_pantalla();

      printf("=== MENÚ DE PRUEBAS - ARREGLOS EN C ===\n");
      printf("1. Recorrer arreglo\n");
      printf("2. Pasar arreglo por parámetro\n");
      printf("3. Retornar arreglo\n");
      printf("4. Coordenadas (arreglo bidimensional)\n");
      printf("5. Pasar arreglo (versión 2)\n");
      printf("6. Pasar arreglo bidimensional\n");
      printf("7. Puntajes\n");
      printf("8. Tamaño del arreglo\n");
      printf("0. Salir\n");

      opcion = leer_entero("Seleccione una opción: ");

      limpiar_pantalla();

      switch (opcion) {
          case 1: recorrer(); break;
          case 2: por_parametro(); break;
          case 3: retornar(); break;
          case 4: coordenadas(); break;
          case 5: por_parametro_2(); break;
          case 6: por_parametro_bidimensional(); break;
          case 7: puntajes(); break;
          case 8: tamanio_del_arreglo(); break;
          case 0:
              printf("Saliendo...\n");
              return 0;
          default:
              printf("Opción inválida. Debe ser entre 0 y 8.\n");
              break;
      }

      repetir = leer_sn("\n¿Desea ejecutar otra opción? (s/n): ");

  } while (repetir == 's' || repetir == 'S');

  printf("¡Gracias por usar el programa!\n");
  return 0;
}