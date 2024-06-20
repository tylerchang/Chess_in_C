#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define CHESS_DARK (Color){ 111,115,210, 255 }
#define CHESS_LIGHT (Color){ 157,172,255, 255 }

const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const double CELL_WIDTH = WINDOW_WIDTH / 8;
const double CELL_HEIGHT = WINDOW_HEIGHT / 8;

const char bRookPath[] = "../assets/black-rook.png";
const char bKnightPath[] = "../assets/black-knight.png";
const char bBishopPath[] = "../assets/black-bishop.png";
const char bQueenPath[] = "../assets/black-queen.png";
const char bKingPath[] = "../assets/black-king.png";
const char bPawnPath[] = "../assets/black-pawn.png";

const char wRookPath[] = "../assets/white-rook.png";
const char wPawnPath[] = "../assets/white-pawn.png";
const char wKingPath[] = "../assets/white-king.png";
const char wKnightPath[] = "../assets/white-knight.png";
const char wBishopPath[] = "../assets/white-bishop.png";
const char wQueenPath[] = "../assets/white-queen.png";


struct Piece{
    char name[40]; // name of a piece or FREE
    char color[6]; // BLACK, WHITE, or FREE
    char iconPath[64];
};

struct Cell{
    int number;
    char letter;
    struct Piece occupiedPiece;
    double x; // x coordinate of upper left corner of cell
    double y; // y coordinate of upper left corner of cell
};

void print_chess_board(struct Cell (*ptrBoard)[8][8]){

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            printf("| %f-", (*ptrBoard)[i][j].x);
            printf("%f,", (*ptrBoard)[i][j].y);
            
            printf(" %s-", (*ptrBoard)[i][j].occupiedPiece.color);
            printf("%s |", (*ptrBoard)[i][j].occupiedPiece.name);
        }
        printf("\n");
        printf("_____________________________________________________________________________________________________________________________\n");
    }
}

void initialize_chess_board(struct Cell(*ptrBoard)[8][8]){ 

        for(int row = 0; row<BOARD_WIDTH; row++){
        for(int column = 0; column<BOARD_HEIGHT; column++){
            
            int row_number = 8 - row;
            (*ptrBoard)[row][column].number = row_number;
            switch (column){
                case 0: 
                    (*ptrBoard)[row][column].letter = 'a';
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bRookPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);

                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wRookPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                        
                    }
                    break;
                case 1: 
                    (*ptrBoard)[row][column].letter = 'b';
                    
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKnightPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);

                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wKnightPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }
                    break;
                case 2: 
                    (*ptrBoard)[row][column].letter = 'c';
                    
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bBishopPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);

                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wBishopPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }                    
                    break;
                case 3: 
                    (*ptrBoard)[row][column].letter = 'd';

                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "QUEEN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bQueenPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "QUEEN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wQueenPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }                    
                    break;
                case 4: 
                    (*ptrBoard)[row][column].letter = 'e';
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KING");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKingPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KING");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wKingPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }                    
                    break;
                case 5: 
                    (*ptrBoard)[row][column].letter = 'f';

                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bBishopPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wBishopPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }                    
                    break;
                case 6: 
                    (*ptrBoard)[row][column].letter = 'g';
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKnightPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wKnightPath);
                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }                    
                    break;  
                case 7: 
                    (*ptrBoard)[row][column].letter = 'h';
                    if(row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bRookPath);
                    }
                    else if(row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(row_number == 1){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wRookPath);

                    }
                    else{
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "FREE");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "F");
                    }
                    break;                                                                                                    
            }
        }
    }
}

int main(void) {

    struct Cell chess_board [BOARD_WIDTH][BOARD_HEIGHT];
    initialize_chess_board(&chess_board);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Drawing the grid and attaching coordinates to chess_board Cells
        int row = 0;
        int col = 0;
        int currentY = 0;
        int currentX = 0;
        bool cellIsDark = false;
        while(row<8){
            while(col<8){
                if(cellIsDark){
                    DrawRectangle(currentX, currentY, CELL_WIDTH, CELL_HEIGHT, CHESS_DARK);
                }else{
                    DrawRectangle(currentX, currentY, CELL_WIDTH, CELL_HEIGHT, CHESS_LIGHT);
                }
                chess_board[row][col].x = currentX;
                chess_board[row][col].y = currentY;
                cellIsDark = !cellIsDark;
                currentX += CELL_WIDTH;
                col+=1;
            }
            cellIsDark = !cellIsDark;
            currentY += CELL_HEIGHT;
            currentX = 0.0;
            col = 0;
            row+=1;
        }

        // Drawing the initial pieces and keeping track of all textures used, dynamically allocating more memory everytime a new texture is used
        Texture2D *ptrUsedTextures = (Texture2D*) malloc(sizeof(Texture2D));
        int sizeOfUsedTexturesArray = 1;
        for(int i = 0; i<BOARD_HEIGHT; i++){
            for(int j = 0; j<BOARD_WIDTH; j++){
                if(strcmp(chess_board[i][j].occupiedPiece.name, "FREE") != 0){

                    Image image = LoadImage(chess_board[i][j].occupiedPiece.iconPath);
                    ImageResize(&image, CELL_WIDTH, CELL_HEIGHT);
                    Texture2D texture = LoadTextureFromImage(image);
                    UnloadImage(image);
                    DrawTexture(texture, chess_board[i][j].x, chess_board[i][j].y, WHITE);

                    ptrUsedTextures[ ((sizeof(Texture2D)*sizeOfUsedTexturesArray) / sizeof(Texture2D)) - 1] = texture;
                    ptrUsedTextures = (Texture2D*) realloc(ptrUsedTextures, sizeof(Texture2D) + (sizeOfUsedTexturesArray*sizeof(Texture2D)));
                    sizeOfUsedTexturesArray +=1;
                }
            }
        }

        EndDrawing();
        
        // Freeing all the textures from the array and the pointer to the malloc
        for(int i = 0; i < sizeOfUsedTexturesArray; i++){
            UnloadTexture(ptrUsedTextures[i]);
        }
        free(ptrUsedTextures);
     }


    CloseWindow();

    return 0;
}





           
