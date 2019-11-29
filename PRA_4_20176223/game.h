#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

//Crear el tablero, junto con su diseno. Trabaja con print_game para estilizar.
void setup (char** g, int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            g[i][j] = '|'; //necesita de print_game para estilizarlo
        }
    }


}

//Imprimir el tablero
void print_game(char** game, int r, int c) {

    //Asiste al jugador para colocar fichas
    for (int j = 0; j<c;j++){
        printf("%d ",j);
    }
    printf("\n");

    for(int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            printf("%c ", game[i][j]); //estiliza cada espacio de ficha
        }
        printf("\n");
    }

}

void make_move(char** game, int r, int c, char t){

    int j;



    //Si es jugador, leelo y hasta que sea un valor admitioo
    if (t=='1'){
        do {
            scanf("%d", &j);
        }
        while(j>c || j<0);
    }
    //si es cpu, numero entre 0 y ultima columna
    else {
        int lower = 0, upper = c-1;

        srand(time(0));

        j = rand()% (upper+1 - lower) + lower;
        printf("CPU plays %d \n", j);
    }
        //Verifica donde va la jugada en la columna.
        //Compara con "vacio"=='|', porque asi se diseno el tablero
        //Se recorre desde el mas alto, osea, ultima fila.
        for (int i=r-1;i>=0;--i){
            if (game[i][j]=='|'){
                game[i][j]= t;
                break;
            }
        }
}

void switch_turn(char turn){


}


bool check_hor(char** game, int r, int c, int n, char t){

    int cnt=0;

    for (int i =0;i<r;i++){
        for (int j=0;j<c;j++){
            if (j+1 <= c && j-1>=0){
                //printf("entro rango");
                if ( (game[i][j]==game[i][j-1]) && (game[i][j]!='|') ){
                        cnt++;
                       // printf("cnt hor %d \n", cnt);
                        if (cnt==n-1){
                            printf("Gano P%c, Hor\n", t);
                            return true;
                        }
                }
                else {
                    cnt=0;
                }
            }
        }
        cnt=0;
    }
    return false;

}

bool check_ver(char** game, int r, int c, int n, char t){

    int cnt=0;

    for (int j =0;j<c;j++){
        for (int i=0;i<r;i++){
            if (i+1 <= r && i-1>=0){
                //printf("entro rango");
                if ( (game[i][j]==game[i-1][j]) && (game[i][j]!='|') ){
                        cnt++;
                        //printf("cnt ver %d \n", cnt);
                        if (cnt==n-1){
                            printf("Gano P%c, Ver\n", t);
                            return true;
                        }
                }
                else {
                    cnt=0;
                }
            }
        }
        cnt=0;
    }
    return false;

}

//Dispara arriba y derecha, buscando ganador
bool check_diag_r(char** game, int r, int c, int n, char t){

    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            //Dode estes parado mas n, debe estar dentro del tablero.
            //Necesitas n columnas disponibles para acertar.
            if ((j+n<=c) && (i-n >=-1) ){

                int cnt=0;
                //Que tan lejos va el disparo
                for(int k=1;k<n;k++){
                   // printf("%d, %d \n", i,j);
                    if ((game[i][j]==game[i-k][j+k]) && (game[i-k][j+k]!='|') ){
                        cnt++;
                        //printf("cnt diag %d \n", cnt);
                        if (cnt==n-1){
                            printf("Gano P%c, Diag r\n", t);
                            return true;
                        }
                    }
                    else {
                        cnt = 0;
                    }

                }
            }
        }
    }
    return false;

}

//Dispara arriba y derecha, buscando ganador
bool check_diag_l(char** game, int r, int c, int n,char t){

    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            //Dode estes parado mas n, debe estar dentro del tablero.
            //Necesitas n columnas disponibles para acertar.


             if ((j-n>=-1) && (i-n >=-1) )
                {

                int cnt=0;
                //Que tan lejos va el disparo
                for(int k=1;k<n;k++){
                    //printf("\n %d, %d \n", i,j);
                    if ((game[i][j]==game[i-k][j-k]) && (game[i-k][j-k]!='|') ){
                        cnt++;
                        //printf("\n %d, %d \n", i,j);
                        //printf("cnt diag L %d \n", cnt);
                        if (cnt==n-1){
                            printf("Gano P%c, Diag L\n", t);
                            return true;
                        }
                    }
                    else {
                        cnt = 0;
                    }

                }
            }
        }
    }
    return false;

}


bool check_winner(char**game, int r, int c, int n, char turn){

if (check_hor(game,r,c,n,turn) ||
    check_ver(game,r,c,n,turn) ||
    check_diag_r(game,r,c,n,turn) ||
    check_diag_l(game,r,c,n,turn)){

    return true;
    }
else{
    return false;
}

}




