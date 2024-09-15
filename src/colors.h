#if !defined(COLORS_H)
#define COLORS_H
#include<vector>
#include<raylib.h>

extern const Color darkgrey ;
extern const Color geeen;
extern const Color red ;
extern const Color orange ;
extern const Color yellow ;
extern const Color purple;
extern const Color cyan ;
extern const Color blue ;

    std::vector<Color> get_cell_colors();
#endif // COLORS_H

