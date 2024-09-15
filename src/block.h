#if !defined(BLOCK_H)
#define BLOCK_H
#include<vector>
#include<map>
#include"position.h"
#include"colors.h"

class Block{
    public:
    Block();
    int id;
    std::map<int, std::vector<position>>cells;


    void Draw();
    void move(int row, int  col);
    void rotate();
    void undo_rotation();

    std::vector<position> get_cell_Position();

    private:
    int cell_size;
    int rotation_state;
    std::vector<Color> colors;
    int row_offset;
    int col_offset;
};




#endif // BLOCK_H
