#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include <iostream>
#include <string>

using namespace std;

ChessBoard::ChessBoard(){
  create_pieces();
  insert_pieces();
  cout << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard(){
  delete_pieces();
}

void ChessBoard::create_pieces(){
  whiteKing = new King(white, "E1" ,this);
  blackKing = new King(black, "E8" ,this);

  whiteQueen = new Queen(white, "D1",this);
  blackQueen = new Queen(black, "D8",this);

  whiteBishopC = new Bishop(white, "C1",this);
  whiteBishopF = new Bishop(white, "F1",this);
  blackBishopC = new Bishop(black, "C8",this);
  blackBishopF = new Bishop(black, "F8",this);

  whiteKnightB = new Knight(white, "B1",this);
  whiteKnightG = new Knight(white, "G1",this);
  blackKnightB = new Knight(black, "B8",this);
  blackKnightG = new Knight(black, "G8",this);

  whiteRookA = new Rook(white, "A1",this);
  whiteRookH = new Rook(white, "H1",this);
  blackRookA = new Rook(black, "A8",this);
  blackRookH = new Rook(black, "H8",this);

  whitePawnA = new Pawn(white, "A2",this);
  whitePawnB = new Pawn(white, "B2",this);
  whitePawnC = new Pawn(white, "C2",this);
  whitePawnD = new Pawn(white, "D2",this);
  whitePawnE = new Pawn(white, "E2",this);
  whitePawnF = new Pawn(white, "F2",this);
  whitePawnG = new Pawn(white, "G2",this);
  whitePawnH = new Pawn(white, "H2",this);
  blackPawnA = new Pawn(black, "A7",this);
  blackPawnB = new Pawn(black, "B7",this);
  blackPawnC = new Pawn(black, "C7",this);
  blackPawnD = new Pawn(black, "D7",this);
  blackPawnE = new Pawn(black, "E7",this);
  blackPawnF = new Pawn(black, "F7",this);
  blackPawnG = new Pawn(black, "G7",this);
  blackPawnH = new Pawn(black, "H7",this);
}


void ChessBoard::insert_pieces(){
  pieces[(blackKing->get_position())] = blackKing;
  pieces[(whiteKing->get_position())] = whiteKing;

  pieces[(blackQueen->get_position())] = blackQueen;
  pieces[(whiteQueen->get_position())] = whiteQueen;

  pieces[(blackBishopC->get_position())] = blackBishopC;
  pieces[(blackBishopF->get_position())] = blackBishopF;
  pieces[(whiteBishopC->get_position())] = whiteBishopC;
  pieces[(whiteBishopF->get_position())] = whiteBishopF;

  pieces[(blackKnightB->get_position())] = blackKnightB;
  pieces[(blackKnightG->get_position())] = blackKnightG;
  pieces[(whiteKnightB->get_position())] = whiteKnightB;
  pieces[(whiteKnightG->get_position())] = whiteKnightG;

  pieces[(blackRookA->get_position())] = blackRookA;
  pieces[(blackRookH->get_position())] = blackRookH;
  pieces[(whiteRookA->get_position())] = whiteRookA;
  pieces[(whiteRookH->get_position())] = whiteRookH;


  pieces[(blackPawnA->get_position())] = blackPawnA;
  pieces[(blackPawnB->get_position())] = blackPawnB;
  pieces[(blackPawnC->get_position())] = blackPawnC;
  pieces[(blackPawnD->get_position())] = blackPawnD;
  pieces[(blackPawnE->get_position())] = blackPawnE;
  pieces[(blackPawnF->get_position())] = blackPawnF;
  pieces[(blackPawnG->get_position())] = blackPawnG;
  pieces[(blackPawnH->get_position())] = blackPawnH;

  pieces[(whitePawnA->get_position())] = whitePawnA;
  pieces[(whitePawnB->get_position())] = whitePawnB;
  pieces[(whitePawnC->get_position())] = whitePawnC;
  pieces[(whitePawnD->get_position())] = whitePawnD;
  pieces[(whitePawnE->get_position())] = whitePawnE;
  pieces[(whitePawnF->get_position())] = whitePawnF;
  pieces[(whitePawnG->get_position())] = whitePawnG;
  pieces[(whitePawnH->get_position())] = whitePawnH;

  for (char col='A'; col <= 'H' ;col++){
    for (char row='3'; col <= '6' ;col++){
      pieces[string(1,col) + string(1,row)] = NULL;
    }
  }
}

void ChessBoard::delete_pieces(){
  delete whiteKing;
  delete blackKing;

  delete whiteQueen;
  delete blackQueen;

  delete whiteBishopC;
  delete whiteBishopF;
  delete blackBishopC;
  delete blackBishopF;

  delete whiteKnightB;
  delete whiteKnightG;
  delete blackKnightB;
  delete blackKnightG;

  delete whiteRookA;
  delete whiteRookH;
  delete blackRookA;
  delete blackRookH;

  delete whitePawnA;
  delete whitePawnB;
  delete whitePawnC;
  delete whitePawnD;
  delete whitePawnE;
  delete whitePawnF;
  delete whitePawnG;
  delete whitePawnH;
  delete blackPawnA;
  delete blackPawnB;
  delete blackPawnC;
  delete blackPawnD;
  delete blackPawnE;
  delete blackPawnF;
  delete blackPawnG;
  delete blackPawnH;

  pieces.clear();
}

void ChessBoard::reset_pieces(){
  delete_pieces();
  create_pieces();
  insert_pieces();
}

void ChessBoard::resetBoard() {
  playerTurn = white;
  reset_pieces();
  gameEnded = false;
  cout << "A new chess game is started!" << endl;
}

bool ChessBoard::is_black_in_check() const {
  return blackKing->is_check();
}

bool ChessBoard::is_white_in_check() const {
  return whiteKing->is_check();
}

Team ChessBoard::get_current_team_turn() {
  return playerTurn;
}

Team ChessBoard::get_opposition_team(){
  return playerTurn == white ? black: white;
}

void ChessBoard::change_team(){
  playerTurn = playerTurn == white ? black: white;
}

bool ChessBoard::is_position_empty(string position){
  if (pieces[position] == NULL)
    return true;
  return false;
}

bool ChessBoard::is_castle_move(string sourcePosition, string targetPosition, Piece*& kingPtr, bool& queenSideCastle){
  if (is_position_empty(sourcePosition))
    return false;

  kingPtr = get_piece_at_position(sourcePosition);
  if ((kingPtr->get_position()[0] != 'E') && (!kingPtr->get_is_first_move()))
    return false;

  int rowDifference = kingPtr->row_difference(targetPosition);
  int colDifference = kingPtr->col_difference(targetPosition);

  if (rowDifference != 0 && colDifference != 2)
    return false;

  queenSideCastle = colDifference > 0 ? true: false;

  return true;
}

bool ChessBoard::is_castle_move_valid(Piece* kingPtr, bool queenSideCastle, Piece*& rookPtr){

  if (kingPtr->get_team() == black? blackKing->is_check(): whiteKing->is_check())
    return false;

  string rookPosition = kingPtr->get_position();
  if (queenSideCastle)
    rookPosition[0] = 'A';
  else
    rookPosition[0] = 'H';


  if (is_position_empty(rookPosition))
    return false;
  else
    rookPtr = get_piece_at_position(rookPosition);

  if (!rookPtr->get_is_first_move())
    return false;


  // Check if path is free
  string tempPosition;
  if (queenSideCastle){
    for (char col='B'; col <= 'D'; col++){
      tempPosition = string(1,col) + kingPtr->get_position()[1];
      if (!is_position_empty(tempPosition))
        return false;
    }
  }
  else {
    for (char col='F'; col <= 'G'; col++){
      tempPosition = string(1,col) + kingPtr->get_position()[1];
      if (!is_position_empty(tempPosition))
        return false;
    }
  }

  // is king path in check
  string kingPathPosition = kingPtr->get_position();
  if (queenSideCastle)
    kingPathPosition[0] = 'D';
  else
    kingPathPosition[0] = 'F';

  Piece* piecePtr;
  for(auto piece : pieces){
    piecePtr = piece.second;
    if (piecePtr && piecePtr->get_team() != kingPtr->get_team()){
      if (piecePtr->is_move_valid_any_piece(kingPathPosition) && piecePtr->is_move_valid(kingPathPosition) && piecePtr->is_simulated_move_valid(kingPathPosition))
        return false;
    }
  }

  //move the rook to its new positions and check if valid
  string rookOldPosition = rookPtr->get_position();
  string rookNewPosition = rookPtr->get_position();

  string kingOldPosition = kingPtr->get_position();
  string kingNewPosition = kingPtr->get_position();

  if (queenSideCastle){
    rookNewPosition[0] = 'D';
    kingNewPosition[0] = 'C';
  }
  else {
    rookNewPosition[0] = 'F';
    kingNewPosition[0] = 'G';
  }

  pieces[rookNewPosition] =  pieces[rookOldPosition];
  pieces[rookOldPosition] = NULL;
  rookPtr->set_position(rookNewPosition);

  bool castlingValid = true;
  if (!kingPtr->is_simulated_move_valid(kingNewPosition)){
    castlingValid = false;
  }

  pieces[rookOldPosition] =  pieces[rookNewPosition];
  pieces[rookNewPosition] = NULL;
  rookPtr->set_position(rookOldPosition);

  return castlingValid;
}

void ChessBoard::execute_castle_move(Piece* kingPtr, Piece* rookPtr){

  //move the rook and king to their new positions
  string rookOldPosition = rookPtr->get_position();
  string rookNewPosition = rookPtr->get_position();

  string kingOldPosition = kingPtr->get_position();
  string kingNewPosition = kingPtr->get_position();

  if (rookOldPosition[0] == 'A'){
    rookNewPosition[0] = 'D';
    kingNewPosition[0] = 'C';
  }
  else {
    rookNewPosition[0] = 'F';
    kingNewPosition[0] = 'G';
  }

  pieces[rookNewPosition] =  pieces[rookOldPosition];
  pieces[rookOldPosition] = NULL;
  rookPtr->set_position(rookNewPosition);

  pieces[kingNewPosition] =  pieces[kingOldPosition];
  pieces[kingOldPosition] = NULL;
  kingPtr->set_position(kingNewPosition);
}

Piece* ChessBoard::get_piece_at_position(string position){
  for(auto piece : pieces){
      if(piece.second && piece.second->get_position() == position)
        return piece.second;
  }
  return NULL;
}

bool ChessBoard::is_position_on_board(string position){
  if (position.size() != 2)
    return false;
  if (position[0] < 'A' || position[0] > 'H' || position[1] < '1' || position[1] > '8')
    return false;
  return true;
}

bool ChessBoard::is_stalemate(){
  Piece* pieceptr = NULL;
  string tempPosition;

  for(auto piece : pieces){
    pieceptr = piece.second;
    if (pieceptr && pieceptr->get_team() == playerTurn){
      for (char row = '1'; row <= '8'; row++){
        for (char col = 'A'; col <= 'H'; col++) {
          tempPosition = string(1,col) + string(1,row);
          if (pieceptr->is_move_valid_any_piece(tempPosition) && pieceptr->is_move_valid(tempPosition) && pieceptr->is_simulated_move_valid(tempPosition))
            return false;
        }
      }
    }
  }

  return true;
}


bool ChessBoard::submitMove(string sourcePosition, string targetPosition){
  if (gameEnded){
    cout << "The game is already over!" << endl;
    return false;
  }

  if(!is_position_on_board(sourcePosition) || !is_position_on_board(targetPosition)){
    cout << "Not a valid position" << endl;
    return false;
  }

  if(is_position_empty(sourcePosition)) {
    cout << "There is no piece at position " << sourcePosition << "!" << endl;
    return false;
  }

  if (sourcePosition == targetPosition){
    cout << "Can't make moves to the same position" << endl;
    return false;
  }

  Piece *sourcePiece = NULL;
  sourcePiece = get_piece_at_position(sourcePosition);


  if (sourcePiece->get_team() != playerTurn){
    cout << "It is not "<< sourcePiece->get_team_name() << "'s turn to move!" << endl;
    return false;
  }

  Piece* kingPtr, * rookPtr = NULL;
  bool castleMove = false;
  bool queenSideCastle;
  if (is_castle_move(sourcePosition, targetPosition, kingPtr, queenSideCastle) && is_castle_move_valid(kingPtr, queenSideCastle, rookPtr)){
    execute_castle_move(kingPtr, rookPtr);
    cout << sourcePiece->get_team_name() << " performed castle move" << endl;
    castleMove = true;
  }

  Piece *targetPiece = NULL;
  if (!castleMove && !is_position_empty(targetPosition)){
    targetPiece = get_piece_at_position(targetPosition);
    if (sourcePiece->get_team() == targetPiece->get_team()){
      cout << sourcePiece->get_team_name() << "'s "<< sourcePiece->get_name() <<  " cannot capture own team!" << endl;
      return false;
    }
  }

  if(!castleMove && sourcePiece->is_move_valid(targetPosition) && sourcePiece->is_simulated_move_valid(targetPosition)){
    cout << sourcePiece->get_team_name() << "'s "<< sourcePiece->get_name() << " moves from "<< sourcePosition << " to " << targetPosition;
    sourcePiece->change_position(targetPosition);
    if (targetPiece)
      cout << " taking " << targetPiece->get_team_name() << "'s " << targetPiece->get_name();
    cout << endl;
  }
  else if (!castleMove){
    cout << sourcePiece->get_team_name() << "'s " << sourcePiece->get_name()<< " cannot move to " << targetPosition << "!" << endl;
    return false;
  }

  sourcePiece->first_move_completed();
  change_team();

  if (playerTurn == black){
    gameEnded = blackKing->is_checkmate();
    if (gameEnded)
      cout << "Black is in checkmate" << endl;
    else if (playerTurn == black && blackKing->is_check())
      cout << "Black is in check" << endl;
  }
  else{
    gameEnded = whiteKing->is_checkmate();
    if (gameEnded)
      cout << "White is in checkmate" << endl;
    else if (playerTurn == white && whiteKing->is_check())
      cout << "White is in check" << endl;

  }

  if (!gameEnded && is_stalemate()){
    gameEnded = true;
    cout << "Game ended in stalemate" << endl;
  }

  return true;
}

// void ChessBoard::print_board(){
//   // print_all_pieces();
//
//   string position = "A8";
//   Piece* piecePtr = NULL;
//   char letter = 'A';
//   cout << "    ";
//   for(int i=0; i<8; i++){
//     cout <<  letter << "    ";
//     letter = letter + 1;
//   }
//   cout << "\n  +----+----+----+----+----+----+----+----+" << endl;
//   string positionA8 = "A8";
//   for(int row=0; row<8; row++){
//     string position = positionA8;
//     position[1] = position[1] - row;
//     cout << 8 - row << " | ";
//     for(int col=0; col<8; col++){
//       string positioncol = position;
//       positioncol[0] = positioncol[0] + col;
//       // cout << endl << "Position: " << positioncol << endl;
//       // is_state_of_map_good();
//       if (!is_position_empty(positioncol)){
//         piecePtr = get_piece_at_position(positioncol);
//           cout << piecePtr->get_short_name();
//         if (piecePtr->get_team() == white)
//           cout << 'w';
//         else
//           cout << 'b';
//       }
//       else
//         cout << "..";
//       cout << " | ";
//     }
//
//     cout << endl << "  +----+----+----+----+----+----+----+----+" << endl;
//   }
// }
