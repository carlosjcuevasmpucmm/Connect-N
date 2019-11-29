#include <stdio.h>
#include <stdlib.h>
#include "game.h"



int main()
{
    //fichas para ganar
    int n;
    printf("Introduzca n\n");
    scanf("%d", &n);//& quita el warning
//        int n = 4;
        char turn = '2';
    //filas y columnas del juego, segun criterios de la asignacion
    int rows = n+2;
    int columns = n+3;

    //Arreglo bidimensional del juego, utilizando punteros.
    char** game_board = (char**) malloc (rows*sizeof(char*));
    for (int i = 0; i< rows; i++){
      game_board[i] = (char*) malloc(columns*sizeof(char));
    }

//    game_board[0][0]= '1';
//    printf("%c", game_board[0][0]);

    //Crea el tablero
    setup(game_board, rows, columns);

    //Imprime el juego inicialmente
    print_game(game_board,rows,columns);


    //Correra hasta tener un ganador

   do{
         if (turn=='2'){
            turn='1';
        }
        else {
            turn='2';
        }
        make_move(game_board,rows,columns,turn);
        print_game(game_board,rows,columns);

    }
    while(!check_winner(game_board,rows,columns,n,turn));



    return 0;
}
