PROG = chess
CC = g++
CPPFLAGS = -Wall -std=c++11 -g -c
OBJS = ChessMain.o ChessBoard.o King.o Piece.o Rook.o Bishop.o Knight.o Queen.o Pawn.o

$(PROG) : $(OBJS)
	$(CC) -g $(OBJS) -o $(PROG)
ChessMain.o: ChessMain.cpp ChessBoard.h
ChessBoard.o: ChessBoard.cpp ChessBoard.h Piece.h King.h Rook.h Bishop.h Knight.h Queen.h Pawn.h
Piece.o: Piece.cpp Piece.h ChessBoard.h
Rook.o: Rook.cpp Rook.h Piece.h ChessBoard.h
Bishop.o: Bishop.cpp Bishop.h Piece.h ChessBoard.h
Knight.o: Knight.cpp Knight.h Piece.h ChessBoard.h
Queen.o: Queen.cpp Queen.h Piece.h ChessBoard.h
King.o: King.cpp King.h Piece.h ChessBoard.h
Pawn.o: Pawn.cpp Pawn.h Piece.h ChessBoard.h

%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) $<

clean:
	rm -f *.o *.gch $(PROG)
