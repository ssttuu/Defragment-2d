//
//  Grid.h
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#pragma once

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
    
    const int getWidth() const;
    const int getHeight() const;
    const int getResolution() const;
    const ci::Vec2i getSize() const;
    const int getRows() const;
    const int getCols() const;
    const ci::Vec2i getDimensions() const;
    
    bool isFullyOccupied() const;
    
    Cell& getNextRandomCell();
    Cell& getNextOrderedCell();


public:
    typedef std::vector<Cell> CellRow;
    typedef std::vector<CellRow> Grid2d;
    typedef std::vector<Grid2d> Grid3d;

private:
    int mWidth = 100;
    int mHeight = 100;
    int mResolution = 0;
    int mNRows = 10;
    int mNCols = 10;
    
    int mNextIndex = 0;

    Grid2d mGrid;
    
};