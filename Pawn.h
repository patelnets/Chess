#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "ChessBoard.h"

class Pawn: public Piece{

public:
  Pawn(Team team, std::string position, ChessBoard* board);
  virtual ~Pawn();

  virtual bool is_move_valid(std::string targetPosition) const;
};



#endif
