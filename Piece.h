#ifndef PIECE_H
#define PIECE_H

#include <string>

enum Team {black, white};

class ChessBoard;

class Piece{
  protected:
    Team const team;
    std::string position;
    ChessBoard* const chessBoard;
    bool firstMove = true;

    Piece(Team team, std::string position, ChessBoard* board);
    std::string name;

  public:
    virtual ~Piece();

    /*Chnges the position of the piece on the map and its own member. Removes piece at the newPosition is there is one*/
    void change_position(std::string newPosition);

    /*Sets position to newPosition*/
    void set_position(std::string newPosition);

    /*Pure virtual function which checks if a move is valid for each piece taking into account their own rules*/
    virtual bool is_move_valid(std::string targetPosition) const = 0;

    /*Checks if the tragetPosition is on the board and that the piece is not attacking its own team or itself*/
    bool is_move_valid_any_piece(std::string targetPosition) const;

    /*Simulates a move and checks if that puts its teams king in check */
    bool is_simulated_move_valid(std::string targetPosition);

    /*Changes firsMove to false*/
    void first_move_completed();

    /*Gives the difference in rows between the position other and this piece*/
    const int row_difference(std::string other) const;

    /*Gives the difference in colums between the position other and this piece*/
    const int col_difference(std::string other) const;

    /*These return the value of the respective data members*/
    std::string get_position() const;
    Team get_team() const;
    std::string get_name() const;
    std::string get_team_name() const;
    bool get_can_castle() const;
    bool get_is_first_move() const;


};



#endif
