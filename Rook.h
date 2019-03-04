#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "ChessBoard.h"

class Rook: public Piece{

public:
  Rook(Team team, std::string position, ChessBoard* board);
  virtual ~Rook();

  virtual bool is_move_valid(std::string targetPosition) const;
};

#endif
