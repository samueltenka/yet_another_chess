/* Position.h: represents chess position traditionally,
 * and also as feature vector. Calculates all legal moves
 * from given position, all legal vectors from given vector,
 * and given a move in algebraic notation can update a position
 * or a vector. Can read and write in PGN notation.
 * (TODO: should we use smith reversible notation??)
 */

#ifndef POSITION_H
#define POSITION_H

#include <vector>

enum Color {
   black, white, empty
};
enum Species {
   pawn, knight, bishop, rook, queen, king
} const int num_species = 6; 
struct Piece {
   Color color; Species species;
};

class Move {
   short row_begin, col_begin;
   short row_end, col_end;
   bool is_capture;
   Piece taken; //for reversibility
   bool is_promotion,
   bool is_castle;
   bool is_pawn_jump;
};

class Position {
private:
   Piece board[8][8];
   bool castled[2];
   struct {
      bool enpassantable;
      short column;
   } enpassant;
   bool whites_turn;
public:
   void from_vector(const std::vector<short> &v);
   void to_vector(std::vector<short> &v) const;
   void update_by(Move m);
   void next_moves(std::vector<Moves> &mvs);
};

#endif//POSITION_H
