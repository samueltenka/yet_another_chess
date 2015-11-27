#include "Position.h"

static const int header_size = 12;
static const int square_size = 2*num_species;
static const int body_size = 64*square_size;
static const int total_size = header_size+body_size;

static int inline to_int(Piece &P) {
   return Piece.color*num_species + Piece.species;
}

void Position::to_vector(std::vector<bool> &v) const {
   v.resize(total_size, false);
   //0. Header: turn info and castling, enpassant stats 
   v[0] = whites_turn;
   v[1] = castled[0];
   v[2] = castled[1];
   v[3] = enpassant.enpassantable;
   v[4+enpassant.column] = true; // indices 4...11

   //1. Body: piece positions
   int i=header_size;
   for(int r=0; r<8; ++r) {
      for(int c=0; c<8; ++c) {
         v[i+to_int(board[r][c])] = true;
         i+=square_size;
      }
   }
}
