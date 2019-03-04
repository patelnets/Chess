#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "ChessBoard.h"

class Bishop: public Piece{
  public:
    Bishop(Team const team, std::string position, ChessBoard* board);
    virtual ~Bishop();

    virtual bool is_move_valid(std::string const targetPosition) const;
};



#endif
