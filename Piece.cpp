#include "Piece.h"
#include "ChessBoard.h"
#include <iostream>
#include <string>

using namespace std;

Piece::Piece(Team team, string position, ChessBoard* chessBoard):team(team),position(position),chessBoard(chessBoard){}

Piece::~Piece(){}

string Piece::get_position() const {
  return position;
}

void Piece::set_position(string newPosition){
  position = newPosition;
}

const int Piece::row_difference(string other) const {
  return position[1]- other[1];
}
const int Piece::col_difference(string other) const {
  return position[0]- other[0];
}

Team Piece::get_team() const {
  return team;
}

string Piece::get_team_name() const {
  if (team == black)
    return "Black";
  return "White";
}

bool Piece::get_is_first_move() const {
  return firstMove;
}

string Piece::get_name() const {
  return name;
}

void Piece::first_move_completed(){
  firstMove = false;
}

bool Piece::is_move_valid_any_piece(string targetPosition) const {

  if(!chessBoard->is_position_on_board(targetPosition))
    return false;

  if (position == targetPosition)
      return false;

  Piece *targetPiecePtr = NULL;

  if (!chessBoard->is_position_empty(targetPosition)){
    targetPiecePtr = chessBoard->get_piece_at_position(targetPosition);
    if (team == targetPiecePtr->get_team())
      return false;
  }
  return true;
}

void Piece::change_position(string newPosition){
    chessBoard->pieces[newPosition] =  chessBoard->pieces[position];
    chessBoard->pieces[position] = NULL;
    position = newPosition;
}

bool Piece::is_simulated_move_valid(string targetPosition){
  bool isSimValid = true;

  const bool targetPieceExists = !chessBoard->is_position_empty(targetPosition);
  Piece* targetPiecePtr = NULL;
  if (targetPieceExists)
    targetPiecePtr = chessBoard->get_piece_at_position(targetPosition);

  string oldPosition = position;
  chessBoard->pieces[targetPosition] =  chessBoard->pieces[position];
  chessBoard->pieces[position] = NULL;
  position = targetPosition;

  if (team == black)
    isSimValid = !chessBoard->is_black_in_check();
  else
    isSimValid = !chessBoard->is_white_in_check();

  chessBoard->pieces[oldPosition] =  chessBoard->pieces[targetPosition];
  position = oldPosition;
  if (targetPieceExists){
    chessBoard->pieces[targetPosition] = targetPiecePtr;
  }
  else
    chessBoard->pieces[targetPosition] = NULL;

  return isSimValid;
}
