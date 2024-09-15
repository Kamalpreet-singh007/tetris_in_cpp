#include"block.h"
#include"position.h"


class Lblock: public Block{
    public:
    Lblock(){
        id = 1;
        cells[0] = {position(0,2), position(1,0), position(1,1), position(1,2)};
        cells[1] = {position(0,1), position(1,1), position(2,1), position(2,2)};
        cells[2] = {position(1,0), position(1,1), position(1,2), position(2,0)};
        cells[3] = {position(0,0), position(0,1), position(1,1), position(2,1)};
        move(3,0);
                
    }
};

class Sblock: public Block{
    public:
    Sblock(){
        id = 2;
        cells[0] = {position(0,0), position(0,1), position(1,1), position(1,2)};
        cells[1] = {position(0,2), position(1,2), position(1,1), position(2,1)};
        cells[2] = {position(2,2), position(2,1), position(1,1), position(1,0)};
        cells[3] = {position(2,0), position(1,0), position(1,1), position(0,1)};
        move(3,0);

    }
};

class Zblock: public Block{
    public:
    Zblock(){
        id = 3;
        cells[0] = {position(0,0), position(1,0), position(1,1), position(2,1)};
        cells[1] = {position(0,2), position(0,1), position(1,1), position(1,0)};
        cells[2] = {position(2,2), position(1,2), position(1,1), position(0,1)};
        cells[3] = {position(2,0), position(2,1), position(1,1), position(1,2)};
        move(3,0);

    }
};

class Tblock: public Block{
    public:
    Tblock(){
        id = 4;
        cells[0] = {position(1,0), position(1,1), position(2,1), position(0,1)};
        cells[1] = {position(1,0), position(1,1), position(1,2), position(0,1)};
        cells[2] = {position(2,1), position(1,1), position(0,1), position(1,0)};
        cells[3] = {position(1,2), position(1,1), position(1,0), position(2,1)};
        move(3,0);

    }
};

class Oblock: public Block{
    public:
    Oblock(){
        id = 5;
        cells[0] = {position(0,0), position(0,1), position(1,0), position(1,1)};
        cells[1] ={position(0,0), position(0,1), position(1,0), position(1,1)};
        cells[2] = {position(0,0), position(0,1), position(1,0), position(1,1)};
        cells[3] = {position(0,0), position(0,1), position(1,0), position(1,1)};
        move(4,0);

    }
};
class Iblock: public Block{
    public:
    Iblock(){
        id = 6;
        cells[0] = {position(1,0), position(1,1), position(1,2), position(1,3)};
        cells[1] ={position(0,2), position(1,2), position(2,2), position(3,2)};
        cells[2] = {position(2,3), position(2,2), position(2,1), position(2,0)};
        cells[3] = {position(3,1), position(2,1), position(1,1), position(0,1)};
        move(3,0);

    }
};

class Jblock: public Block{
    public:
    Jblock(){
        id = 7;
        cells[0] = {position(0,0), position(1,0), position(1,1), position(1,2)};
        cells[1] ={position(0,2), position(0,1), position(1,1), position(2,1)};
        cells[2] = {position(2,2), position(1,2), position(1,1), position(1,0)};
        cells[3] = {position(2,0), position(2,1), position(1,1), position(0,1)};
        move(3,0);

    }
};
