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
    char color[6]; // "B", "W", or "F"
    char iconPath[64];
};

struct Cell{
    int number;
    char letter;
    struct Piece occupiedPiece;
    double x; // x coordinate of upper left corner of cell
    double y; // y coordinate of upper left corner of cell
    int cell_row;
    int cell_col;
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
            int chess_row_number = 8 - row;
            (*ptrBoard)[row][column].number = chess_row_number;
            (*ptrBoard)[row][column].cell_row = row;
            (*ptrBoard)[row][column].cell_col = column;
            switch (column){
                case 0: 
                    (*ptrBoard)[row][column].letter = 'a';
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bRookPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);

                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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
                    
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKnightPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);

                    }
                    else if(chess_row_number == 1){
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
                    
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bBishopPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);

                    }
                    else if(chess_row_number == 1){
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

                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "QUEEN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bQueenPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KING");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKingPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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

                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "BISHOP");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bBishopPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "KNIGHT");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bKnightPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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
                    if(chess_row_number == 8){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "ROOK");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bRookPath);
                    }
                    else if(chess_row_number == 7){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "B");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, bPawnPath);
                    }
                    else if(chess_row_number == 2){
                        strcpy((*ptrBoard)[row][column].occupiedPiece.name, "PAWN");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.color, "W");
                        strcpy((*ptrBoard)[row][column].occupiedPiece.iconPath, wPawnPath);
                    }
                    else if(chess_row_number == 1){
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
    bool cell_is_selected = false;
    bool is_white_turn = true;

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
                if(cell_is_selected == true && row == selected_row && col == selected_col){
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
        
        // Cell selection
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            // If something is already selected for the next move
            if(cell_is_selected == true){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    int *target_cell_info = convert_mouse_coordinates_to_cell(GetMouseX(), GetMouseY());
                    int target_row = target_cell_info[0];
                    int target_col = target_cell_info[1];
                    free(target_cell_info);
                    struct Cell target_cell = chess_board[target_row][target_col];
                    struct Cell selected_cell = chess_board[selected_row][selected_col];

                    printf("Target Cell: %c%d\n", target_cell.letter, target_cell.number);
                    printf("Row: %d, Column: %d\n", target_cell.cell_row, target_cell.cell_col);
                    printf("Target Cell Occupancy: %s %s\n\n", target_cell.occupiedPiece.color, target_cell.occupiedPiece.name);

                    printf("Selected Cell: %c%d\n", selected_cell.letter, selected_cell.number);
                    printf("Row: %d, Column: %d\n", selected_cell.cell_row, selected_cell.cell_col);
                    printf("Occupancy: %s %s\n", selected_cell.occupiedPiece.color, selected_cell.occupiedPiece.name);

                    // Check if move is valid, work in progress
                    // bool validMove = check_move(&target_cell, &selected_cell)
                    bool validMove = true;

                    if(validMove){
                        // Execute move
                        chess_board[target_row][target_col].occupiedPiece = chess_board[selected_row][selected_col].occupiedPiece;
                        strcpy(chess_board[selected_row][selected_col].occupiedPiece.name, "FREE");
                        strcpy(chess_board[selected_row][selected_col].occupiedPiece.color, "F");
                        strcpy(chess_board[selected_row][selected_col].occupiedPiece.iconPath, "");
                    }

                    // Deselect
                    selected_row = -1;
                    selected_col = -1;
                    cell_is_selected = false;
                    
                    if(is_white_turn){
                        is_white_turn = false;
                    }else{
                        is_white_turn = true;
                    }
                    

                }
            } // else see if there is something new to select
            else{
                int *cell_info = convert_mouse_coordinates_to_cell(GetMouseX(), GetMouseY());
                int parsed_row = cell_info[0];
                int parsed_col = cell_info[1];
                free(cell_info);
                struct Cell selected_cell = chess_board[parsed_row][parsed_col];
                printf("Selected Cell: %c%d\n", selected_cell.letter, selected_cell.number);
                printf("Row: %d, Column: %d\n", selected_cell.cell_row, selected_cell.cell_col);
                printf("Occupancy: %s %s\n\n", selected_cell.occupiedPiece.color, selected_cell.occupiedPiece.name);
                
                // Updates the selected values which will render a yellow color of the cell when drawn again, selecting another blank square will deselect
                if(strcmp(selected_cell.occupiedPiece.name, "FREE") != 0){
                    if((is_white_turn && strcmp(selected_cell.occupiedPiece.color, "W") == 0) || (!is_white_turn && strcmp(selected_cell.occupiedPiece.color, "B") == 0)){
                        selected_row = parsed_row;
                        selected_col = parsed_col;
                        cell_is_selected = true;
                    }
                }

            }
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

