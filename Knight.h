#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "ChessBoard.h"

class Knight: public Piece{

public:
  Knight(Team team, std::string position, ChessBoard* board);
  virtual ~Knight();

  virtual bool is_move_valid(std::string targetPosition) const;
};



#endif
