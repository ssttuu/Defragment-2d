//
//  BoxController.h
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#ifndef __Defragment__BoxController__
#define __Defragment__BoxController__

#include <iostream>
#include "Box.h"
#include "Grid.h"


class BoxController {
public:
    BoxController(Grid *grid);
    BoxController(Grid *grid, int nBoxes);

    void setup();
    void update();
    void draw();
    
    void addRandomBox();
    
private:
    int mWidth;
    int mHeight;
    
    Grid *mGrid;
    
    typedef std::vector<Box> Boxes;
    Boxes mBoxes;

};

#endif /* defined(__Defragment__BoxController__) */