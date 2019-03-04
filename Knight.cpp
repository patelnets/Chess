#include "Knight.h"
#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

Knight::Knight(Team team, string position, ChessBoard* board):Piece(team, position, board){
  name = "Knight";
}

Knight::~Knight(){}

bool Knight::is_move_valid(string targetPosition) const {

  int rowDifference = row_difference(targetPosition);
  int colDifference = col_difference(targetPosition);

  bool isValidMove = (abs(rowDifference) == 2 && abs(colDifference) == 1) || (abs(rowDifference) == 1 && abs(colDifference) == 2);

  return isValidMove;
}
