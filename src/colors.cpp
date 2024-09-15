#include"colors.h"


const Color darkgrey {26, 31, 40, 255};
const Color geeen {47, 230, 23, 255};
const Color red {232, 18, 18, 255};
const Color orange {226, 116, 17, 255};
const Color yellow {237, 234, 4, 255};
const Color purple {116, 0, 247, 255};
const Color cyan {21, 204, 209, 255};
const Color blue {13, 64, 216, 255};

std::vector<Color> get_cell_colors(){

    return {darkgrey, geeen,red, orange, yellow, purple, cyan, blue}; 
}