#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Piece.h"
#include "King.h"
#include <string>
#include <map>

class Piece;
class King;
class Queen;
class Bishop;
class Knight;
class Rook;
class Pawn;

class ChessBoard{

  bool gameEnded = false;
  Team playerTurn = white;

  King   *blackKing,    *whiteKing;
  Queen  *blackQueen,   *whiteQueen;

  Bishop *blackBishopC, *blackBishopF, *whiteBishopC, *whiteBishopF;
  Knight *blackKnightB, *blackKnightG, *whiteKnightB, *whiteKnightG;
  Rook   *blackRookA,   *blackRookH,   *whiteRookA,   *whiteRookH;

  Pawn   *blackPawnA,   *blackPawnB,   *blackPawnC, *blackPawnD,
         *blackPawnE,   *blackPawnF,   *blackPawnG, *blackPawnH,
         *whitePawnA,   *whitePawnB,   *whitePawnC, *whitePawnD,
         *whitePawnE,   *whitePawnF,   *whitePawnG, *whitePawnH;

  //Adds the pieces to the map
  void insert_pieces();

  //Creates the pieces on the heap
  void create_pieces();

  //Frees the pieces memory from the heap
  void delete_pieces();

  //Resets the pieces to their initial positions
  void reset_pieces();

  /*Checks if given positions match that of a castle move and if so changes kingPtr to point
    to the king piece address and changes the value of queenSideCastle depending on if it is queen side or not*/
  bool is_castle_move(std::string sourcePosition, std::string targetPosition, Piece*& kingPtr, bool& queenSideCastle);

  /*Checks if the given castle move determined by the kingPtr and queenSideCastle is valid or not
  and if it is then updates the rookPtr to point to the address of the rook that is involved with the move*/
  bool is_castle_move_valid(Piece* kingPtr, bool queenSideCastle, Piece*& rookPtr);

  /*Performs the castle move by updating the map and the position of the pieces*/
  void execute_castle_move(Piece* kingPtr, Piece* rookPtr);

  /*Switches the turn of the team*/
  void change_team();

  public:
    /*Map which connects the string position to a piece pointer*/
    std::map<std::string, Piece*> pieces;

    ChessBoard();
    ~ChessBoard();

    /*Checks if the given position is empty*/
    bool is_position_empty(std::string position);

    /*Checks if the given position is on the board*/
    bool is_position_on_board(std::string position);

    /*Checks if the requested move is valid and if so executes it*/
    bool submitMove(std::string sourcePosition, std::string targetPosition);

    /*Checks if the game has reached a stalemate. If it has then it ends the game*/
    bool is_stalemate();

    /*Checks if black king is in check*/
    bool is_black_in_check() const ;

    /*Checks if white king is in check*/
    bool is_white_in_check() const ;

    /*Resets the board to the beginning, ie starting a new game */
    void resetBoard();

    /*Returns the team whose turn it is*/
    Team get_current_team_turn();

    /*Returns the opposition of the team whose turn it is*/
    Team get_opposition_team();


    /*Returns the pointer to the piece which at the given position. If no piece is found then it returns NULL*/
    Piece* get_piece_at_position(std::string position);

};


#endif
