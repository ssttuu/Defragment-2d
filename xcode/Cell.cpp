//
//  Cell.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#include "Cell.h"
#include "cinder/Vector.h"

#include <boost/foreach.hpp>

using namespace ci;

Cell::Cell(Vec2i index) : Neighbors(*this) {
    mIndex = index;
    calcPosition();
    mIsOccupied = false;
};

Cell::Cell(Vec2i index, int size) : Neighbors(*this) {
    mIndex = index;
    mSize = size;
    calcPosition();
}

bool Cell::isOccupied() {
    return mIsOccupied;
};

bool Cell::setOccupied(bool occupied) {
    mIsOccupied = occupied;
    return mIsOccupied;
}

Vec2i Cell::getIndex() {
    return mIndex;
}

Vec2f Cell::getPosition() {
    return mPosition;
}

int Cell::getSize() {
    return mSize;
}

void Cell::calcPosition() {
    mPosition = (mIndex * mSize) + Vec2i(mSize/2,mSize/2);
}

void Cell::addNeighbor(Cell *neighbor) {
    mNeighbors.push_back( neighbor );
};

void Cell::addNeighbors(Cells *neighbors) {
    BOOST_FOREACH(Cell * c, (*neighbors) ) {
        mNeighbors.push_back( c);
    }
};

void Cell::addNeighborIsEdge() {
    mNeighbors.push_back(nullptr);
}

void Cell::draw() {
    
    
    if (isOccupied()) {
        glColor3f(0.5, 0, 0);
        gl::drawSolidCircle(mPosition, 2);
    } else {
        glColor3f(0.5, 0.5, 0.5);
        gl::drawSolidCircle(mPosition, 1);
    }
    
    
    drawBorder();
    
}

void Cell::drawBorder() {
    glColor3f(0.3, 0.3, 0.3);
    int radius = mSize/2;
    gl::drawLine(mPosition + Vec2i(radius, -radius), mPosition + Vec2i(radius, radius));
    gl::drawLine(mPosition + Vec2i(-radius, radius), mPosition + Vec2i(radius, radius));
}
