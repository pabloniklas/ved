/*
  Modulo Principal.

   Utiliza las librerias ncurses, las cuales se obtienen de:
   ftp://invisible-island.net/ncurses/win32/mingw32-20140308.zip
   Descomprimir y copiar en: "C:\Program Files (x86)\CodeBlocks\MinGW"

 Linkeditar agreando las librerias: menuw, ncursesw.-

 20140308 - PSRN - Version Inicial.
 20140404 - PSRN - Se comento el pedido de clave.
 20140427 - PSRN - Se incorpora las llamadas a las funciones de volcado de archivos y purgado de listas.

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ncursesw/curses.h>
#include <ncursesw/menu.h>

#include "libs/tui.h"

#include "sistema.h"

/*#include "listas.h"
#include "pilasycolas.h"
*/

int main() {
    int opcion = 0, opcion_usuario = 0, opcion_administrador = 0;

    //Creo el menuVertical.
    char *opciones_iniciales[] = {
            "Usuario registrado", "Usuario no registrado", "Administrador", "Creditos", "Salir"
    };

    char *opciones_administrador[] = {
            "Informe completo de salas y peliculas",
            "Listar los usuarios del sistema",
            "Procesar la cola de compra y la pila de reserva de entradas",
            "Agregar peliculas en una determinada sala",
            "Eliminar aquellas peliculas que no tienen ventas de entradas",
            "Volver"
    };

    char *opciones_usuario_registrado[] = {
            "Reservar entrada",
            "Comprar entrada",
            "Consultar las peliculas de cada sala y la disponibilidad de asientos",
            "Volver"
    };

    char *opciones_usuario_noregistrado[] = {
            "Comprar entrada",
            "Consultar las peliculas de cada sala y la disponibilidad de asientos",
            "Volver"
    };

    ncurses_init();
    limpiar_terminal(TITULO_SISTEMA, VERSION_SISTEMA);

    do {
        msgStatus("Menu general del sistema.");
        opcion = menuVertical(5, opciones_iniciales);

        switch (opcion) {

            case 1:
                do {
                    msgStatus("Menu de usuario registrado.");
                    opcion_usuario = menuVertical(4, opciones_usuario_registrado);

                    switch (opcion_usuario) {

                        case 1:
                            ///Reservar entradas.
                            ///reservarEntradas();

                            break;

                        case 2:
                            ///Comprar entradas.
                            ///comprarEntradas();

                            break;

                        case 3:
                            ///Consultar peliculas y disponibilidad de asientos.
                            ///mostrarSalasyPeliculas();

                            break;


                    }
                } while (opcion_usuario != 4);

                break;


                ///Menu Usuario no registrado
            case 2:
                do {
                    msgStatus("Menu de usuario NO registrado.");
                    opcion_usuario = menuVertical(3, opciones_usuario_noregistrado);

                    switch (opcion_usuario) {

                        case 1:
                            ///Comprar entradas.
                            ///comprarEntradas();

                            break;

                        case 2:
                            ///Consultar peliculas y disponibilidad de asientos.
                            ///mostrarSalasyPeliculas();

                            break;

                    }
                } while (opcion_usuario != 3);

                break;

                ///Menu Administrador
            case 3:
                do {
                    msgStatus("Menu de administrador.");
                    opcion_administrador = menuVertical(6, opciones_administrador);

                    switch (opcion_administrador) {

                        case 1:
                            ///Informe completo de salas y peliculas (disponibles y no disponibles).
                            ///mostrarSalasyPeliculas();

                            break;

                        case 2:
                            ///Listar los usuarios del sistema (sin administrador).
                            ///mostrarUsuarios();

                            break;

                        case 3:
                            ///Procesar la cola de compra y la pila de reserva de entradas.
                            ///procesarReservasyCompras();

                            break;

                        case 4:
                            ///Agregar peliculas en una determinada sala.
                            ///altaPeliculas();

                            break;

                        case 5:
                            ///Eliminar aquellas pel�culas que no tienen ventas de entradas.
                            ///eliminaPeliculasSinReservas();

                            break;

                    }
                } while (opcion_administrador != 6);

                break;

                //Creditos
            case 4:
                creditos();
                break;

        }
    } while (opcion != 5);

    ///volcadoArchivos();
    ///purgarListasSalasyPeliculas();
    ///purgarListaUsuarios();

    //presiona_tecla();

    ncurses_terminate();
    printf("Ejecucion terminada.\n");
    printf("(c) 2021 by pN S0f7w4r3.\n");
    printf("--------------------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}

