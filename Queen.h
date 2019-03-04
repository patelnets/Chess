#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "ChessBoard.h"

class Queen: public Piece{

public:
  Queen(Team team, std::string position, ChessBoard* board);
  virtual ~Queen();

  virtual bool is_move_valid(std::string targetPosition) const;
};



#endif
