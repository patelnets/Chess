#include "Bishop.h"
#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

Bishop::Bishop(Team const team, string position, ChessBoard* board):Piece(team, position, board){
  name = "Bishop";
}
Bishop::~Bishop(){}

bool Bishop::is_move_valid(string const targetPosition) const {

  int rowDifference = row_difference(targetPosition);
  int colDifference = col_difference(targetPosition);

  if (abs(rowDifference) != abs(colDifference))
    return false;

  string tempCurrentPosition = position;
  for (int row=1; row < abs(rowDifference); row++){
    tempCurrentPosition[1] =  position[1] - row*(rowDifference/abs(rowDifference));
    tempCurrentPosition[0] =  position[0] - row*(colDifference/abs(colDifference));
    if(!chessBoard->is_position_empty(tempCurrentPosition)){
      return false;
    }
  }

  return true;
}
