#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "ChessBoard.h"


class King: public Piece{
  public:
    King(Team team, std::string position, ChessBoard* board);
    virtual ~King();

    virtual bool is_move_valid(std::string targetPosition) const;

    /* Checks if the king is in check */
    bool is_check() const;

    /* Checks if the king is in checkmate */
    bool is_checkmate();
};



#endif
