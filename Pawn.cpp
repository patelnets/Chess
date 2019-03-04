#include "Pawn.h"
#include "Piece.h"
#include "ChessBoard.h"

using namespace std;

Pawn::Pawn(Team team, string position, ChessBoard* board):Piece(team, position, board){
  name = "Pawn";
}
Pawn::~Pawn(){}

bool Pawn::is_move_valid(string targetPosition) const {
  int rowDifference = row_difference(targetPosition);
  int colDifference = col_difference(targetPosition);

  bool pieceAtTarget = !chessBoard->is_position_empty(targetPosition);
  Piece* targetPiecePtr = NULL;
  if (pieceAtTarget)
    targetPiecePtr = chessBoard->get_piece_at_position(targetPosition);

  bool goesForward = false;
  if (team == white)
    goesForward = rowDifference < 0;
  else
    goesForward = rowDifference > 0;

  bool isValidRowMove = !pieceAtTarget && goesForward && abs(rowDifference) == 1 && colDifference ==0;
  bool isValidDiagMove = goesForward && abs(rowDifference) == 1 && abs(colDifference) ==1 && pieceAtTarget && targetPiecePtr->get_team() != team;
  bool isValidFirstMove = firstMove &&  !pieceAtTarget && goesForward && abs(rowDifference) == 2 && colDifference == 0;

  if (isValidFirstMove){
    string inPathPosition = position;
    inPathPosition[1] -= rowDifference/abs(rowDifference);
    isValidFirstMove = chessBoard->is_position_empty(inPathPosition);
  }

  bool validMove = isValidRowMove || isValidDiagMove || isValidFirstMove;

  return validMove;
}
