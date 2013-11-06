//
//  Grid.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#include "Grid.h"
#include "Cell.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include <boost/foreach.hpp>

using namespace ci;

Grid::Grid() {
    
};


Grid::Grid(int width, int height, int resolution) {
    mWidth = width;
    mHeight = height;
    mResolution = resolution;
    mNRows = height/resolution;
    mNCols = width/resolution;
    
    //Grid2d mGrid(mNRows, CellRow(mNCols));
    
    for(int i=0; i<mNRows; i++) {
        CellRow tmpRow;
        for(int j=0; j<mNCols; j++) {
            Cell tmpCell = Cell(Vec2i(j,i), resolution );
            tmpRow.push_back( tmpCell );
        }
        mGrid.push_back(tmpRow);
    }
    
};

void Grid::setup() {
    // add neighbors
    for(int y=0; y<mNRows; y++) {
        for(int x=0; x<mNCols; x++) {
            for(int i=-1; i<2; i++) {
                for(int j=-1; j<2; j++) {
                    
                    // check to be sure it's within the bounds
                    if((y+i >= 0 && y+i < mNRows) && (x+j >= 0 && x+j < mNCols)) {
                        
                        // don't add self to neighbors
                        if(i==0 && j==0) {
                            continue;
                        }

                        //Cell tmpCell mGrid[y+i][x+j];
                        //std::cout << mGrid[y+i][x+j].getIndex() << std::endl;
                        mGrid[y][x].addNeighbor( &(mGrid[y+i][x+j]) );

                    } else {
                        mGrid[y][x].addNeighborIsEdge();
                    }
                }
            }
        }
    }
};

void Grid::draw() {
    for(int i=0; i<mGrid.size(); i++) {
        for(int j=0; j<mGrid[i].size(); j++) {
            mGrid[i][j].draw();
        }
    }
}

int Grid::getWidth() {
    return mWidth;
};
int Grid::getHeight() {
    return mHeight;
};
int Grid::getResolution() {
    return mResolution;
};
ci::Vec2i Grid::getSize() {
    return Vec2i(getWidth(), getHeight());
};
int Grid::getRows() {
    return mNRows;
};
int Grid::getCols() {
    return mNCols;
};
ci::Vec2i Grid::getDimensions() {
    return Vec2i(getRows(), getCols());
};

bool Grid::isFullyOccupied() {
    for(int i=0; i<mGrid.size(); i++) {
        for(int j=0; j<mGrid[i].size(); j++) {
            if(mGrid[i][j].isOccupied()) {
                continue;
            }
            return false;
        }
    }
    return true;
}

Cell *Grid::getNextRandomCell() {
    int randRow;
    int randCol;
    do {
        randRow = Rand::randInt(0, getRows());
        randCol = Rand::randInt(0, getCols());
    } while ( (mGrid[randRow][randCol]).isOccupied() );
    
    return &(mGrid[randRow][randCol]);
}

Cell *Grid::getNextOrderedCell() {
    int nextRow;
    int nextCol;
    do {
        nextCol = mNextIndex % mNCols;
        nextRow = mNextIndex / mNCols;
        mNextIndex++;
    } while ( (mGrid[nextRow][nextCol]).isOccupied() );
    
    
    return &(mGrid[nextRow][nextCol]);
}







