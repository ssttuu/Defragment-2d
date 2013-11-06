//
//  Grid.h
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#ifndef __Defragment__Grid__
#define __Defragment__Grid__

#include <iostream>
#include "Cell.h"
#include "cinder/Vector.h"


class Grid {
public:
    Grid();
    Grid(int width, int height, int resolution);
    
    void setup();
    void update();
    void draw();
    
    int getWidth();
    int getHeight();
    int getResolution();
    ci::Vec2i getSize();
    int getRows();
    int getCols();
    ci::Vec2i getDimensions();
    
    bool isFullyOccupied();
    
    Cell *getNextRandomCell();
    Cell *getNextOrderedCell();


private:
    typedef std::vector<Cell> CellRow;
    typedef std::vector<CellRow> Grid2d;
    typedef std::vector<Grid2d> Grid3d;

    int mWidth = 100;
    int mHeight = 100;
    int mResolution = 0;
    int mNRows = 10;
    int mNCols = 10;
    
    int mNextIndex = 0;

    Grid2d mGrid;
    
};

#endif /* defined(__Defragment__Grid__) */
