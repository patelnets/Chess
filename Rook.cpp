#include "Rook.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <iostream>

using namespace std;

Rook::Rook(Team team, string position, ChessBoard* board):Piece(team, position, board){
  name = "Rook";
}
Rook::~Rook(){}


bool Rook::is_move_valid(string targetPosition) const {

  int rowDifference = row_difference(targetPosition);
  int colDifference = col_difference(targetPosition);

  bool isValidRowMove = abs(colDifference) ==  0;
  bool isValidColMove = abs(rowDifference) ==  0;

  if (!isValidRowMove && !isValidColMove)
    return false;


  string tempPosition = position;
  if (isValidRowMove){
    for (int row=1; row < abs(rowDifference); row++){
      tempPosition[1] = position[1] - row*(rowDifference/abs(rowDifference));
      if (!chessBoard->is_position_empty(tempPosition))
        return false;
    }
  }

  tempPosition = position;
  if (isValidColMove){
    for (int col=1; col < abs(colDifference); col++){
      tempPosition[0] = position[0] - col*(colDifference/abs(colDifference));
      if (!chessBoard->is_position_empty(tempPosition))
        return false;
    }
  }



  return true;
}
