//
//  BoxController.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#include "BoxController.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include <boost/foreach.hpp>

using namespace ci;


BoxController::BoxController(Grid& grid)
{
    mGrid = grid;
    
    int nBoxes = Rand::randInt(10,20);
    for(int i=0; i<nBoxes; i++) {
        mBoxes.push_back( Box( grid.getNextOrderedCell() ) );
    }
};


BoxController::BoxController(Grid& grid, int nBoxes)
{
    mGrid = grid;
    
    for(int i=0; i<nBoxes; i++) {
        if (grid.isFullyOccupied() == false) {
            mBoxes.push_back( Box( grid.getNextOrderedCell() ) );
        }

    }
};

void addRandomBox();

void BoxController::setup()
{
    for(int i=0; i<mBoxes.size(); i++) {
        mBoxes[i].setup();
    }
};

void BoxController::update()
{
    for(int i=0; i<mBoxes.size(); i++) {
        mBoxes[i].update();
    }
};

void BoxController::draw()
{
    for(int i=0; i<mBoxes.size(); i++) {
        mBoxes[i].draw();
    }
};
