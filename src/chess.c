#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define CHESS_DARK (Color){ 111,115,210, 255 }
#define CHESS_SELECTED (Color){ 244,244, 43, 255 }
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
    char color[6]; // BLACK, WHITE, or F
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

int *convert_mouse_coordinates_to_cell(int mX, int mY){

    int *cell_info = (int*)malloc(2*sizeof(int));
    int row_number;
    int col_number;
    
    // Checking x coordinate ==> col_number
    int x_start_bound = 0;
    int x_end_bound = CELL_WIDTH;
    int x_index = 0;

    // Checking y coordinate ==> row_number
    int y_start_bound = 0;
    int y_end_bound = CELL_HEIGHT;
    int y_index = 0;

    while (x_end_bound <= WINDOW_WIDTH){
        if(mX >= x_start_bound && mX <= x_end_bound){
            col_number = x_index;
            break;
        }
        x_start_bound += CELL_WIDTH;
        x_end_bound += CELL_WIDTH;
        x_index += 1;
    }

    while (y_end_bound <= WINDOW_HEIGHT){
        if(mY >= y_start_bound && mY <= y_end_bound){
            row_number = y_index;
            break;
        }
        y_start_bound += CELL_HEIGHT;
        y_end_bound += CELL_HEIGHT;
        y_index += 1;
    }

    // Setting the return data, [0] => row number, [1] => column number
    cell_info[0] = row_number;
    cell_info[1] = col_number;
    
    return cell_info;

}

int main(void) {

    SetTraceLogLevel(LOG_ERROR);
    // LOG_ALL: 0
    // LOG_TRACE: 1
    // LOG_DEBUG: 2
    // LOG_INFO: 3
    // LOG_WARNING: 4
    // LOG_ERROR: 5
    // LOG_FATAL: 6
    // LOG_NONE: 7

    struct Cell chess_board [BOARD_WIDTH][BOARD_HEIGHT];
    int selected_row = -1;
    int selected_col = -1;
    int mouseX;
    int mouseY;

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

                chess_board[row][col].x = currentX;
                chess_board[row][col].y = currentY;
                if(row == selected_row && col == selected_col){
                    DrawRectangle(currentX, currentY, CELL_WIDTH, CELL_HEIGHT, CHESS_SELECTED);
                }
                else if(cellIsDark){
                    DrawRectangle(currentX, currentY, CELL_WIDTH, CELL_HEIGHT, CHESS_DARK);
                }else{
                    DrawRectangle(currentX, currentY, CELL_WIDTH, CELL_HEIGHT, CHESS_LIGHT);
                }

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

        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouseX = GetMouseX();
            mouseY = GetMouseY();
            int *cell_info = convert_mouse_coordinates_to_cell(mouseX, mouseY);
            int rowSelected = cell_info[0];
            int colSelected = cell_info[1];
            struct Cell selectedCell = chess_board[rowSelected][colSelected];
            printf("Cell: %c%d\n", selectedCell.letter, selectedCell.number);
            printf("Occupancy: %s %s\n", selectedCell.occupiedPiece.color, selectedCell.occupiedPiece.name);
            
            // Updates the selected values which will render a yellow color of the cell when drawn again
            selected_row = rowSelected;
            selected_col = colSelected;

            free(cell_info);
        }
        

        EndDrawing();
        
        // // Freeing all the textures from the array and the pointer to the malloc
        for(int i = 0; i < sizeOfUsedTexturesArray; i++){
            UnloadTexture(ptrUsedTextures[i]);
        }
        free(ptrUsedTextures);
     }

    CloseWindow();

    return 0;
}





           
