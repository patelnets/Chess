#include "King.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <iostream>
#include <string>

using namespace std;

King::King(Team team, string position, ChessBoard* board):Piece(team, position, board){
  name = "King";
}

King::~King(){}

bool King::is_move_valid(string targetPosition) const {

  int rowDifference = row_difference(targetPosition);
  int colDifference = col_difference(targetPosition);

  bool isValidRowMove = abs(rowDifference) == 1 && colDifference ==0;
  bool isValidColMove = abs(colDifference) == 1 && rowDifference ==0;
  bool isValidDiagMove = abs(rowDifference) == 1 && abs(colDifference) ==1;

  return (isValidRowMove || isValidColMove || isValidDiagMove);
}

bool King::is_check() const {

  Piece* attackingPiecePtr = NULL;
  for(auto mapPiece : chessBoard->pieces){
    attackingPiecePtr = mapPiece.second;
    if (attackingPiecePtr && attackingPiecePtr->get_team() != team){
      if (attackingPiecePtr->is_move_valid_any_piece(position) && attackingPiecePtr->is_move_valid(position))
        return true;
    }
  }

  return false;
}


bool King::is_checkmate(){
  if (!is_check())
    return false;

  /* The king is checkmate if the following three conditions hold:
     - if the checking piece cannot be captured
     - if the king cannot move itself out of check
     - if a piece in the King's team can make a move to get the King out of check.*/
  Piece* piecePtr = NULL;
  for(auto piece : chessBoard->pieces){
    piecePtr = piece.second;
    if (piecePtr && piecePtr->get_team() == team){
      for(char row = '1'; row <= '8'; row++) {
        for(char col = 'A'; col <= 'H'; col++) {
          string tempPosition;
          tempPosition.push_back(col);
          tempPosition.push_back(row);
            if (piecePtr->is_move_valid_any_piece(tempPosition) && piecePtr->is_move_valid(tempPosition) && piecePtr->is_simulated_move_valid(tempPosition))
              return false;
        }
      }
    }
  }

  return true;
}
