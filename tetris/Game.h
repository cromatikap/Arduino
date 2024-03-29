//
// Created by raphael on 01/03/17.
//
#include <Adafruit_NeoMatrix.h>

#ifndef KENTRIS_GAME_H
#define KENTRIS_GAME_H

#define ROWS 10
#define COLUMNS 6

#define DIR_DOWN 0
#define DIR_LEFT 1
#define DIR_RIGHT 2
#define ROTATE 3

#define L_PIN 2
#define C_PIN 4
#define R_PIN 7


class Game {
private:
    int currentPieceKind, currentPieceRotation;
    int score;
    uint16_t staticBlocks[ROWS][COLUMNS];
    int currentPieceX, currentPieceY;

public:
    Adafruit_NeoMatrix neoMatrix = Adafruit_NeoMatrix(ROWS, COLUMNS, 6,
                                                      NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT +
                                                      NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                                                      NEO_GRB + NEO_KHZ800);
public:
    void drawCurrentPiece();
    void drawStaticBlocks();
    void setup();
    void reset();
    void drawBoard();
    void createNewPiece();
    void requestDown();
    void requestLeft();
    void requestRight();
    void requestRotate();
    bool canDo(int action, bool allowOutOfMatrix = false);
    uint16_t getStaticBlock(int x, int y);
    void transformToStaticBlock();
    void lost();
    void deleteFullRows();
    void deleteRow(int n);
    bool isRowFull(int y);
    bool isCurrentPieceClashing();
};

#endif //KENTRIS_GAME_H
