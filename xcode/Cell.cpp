//
//  Cell.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#include "Cell.h"
#include "cinder/Vector.h"

using namespace ci;

Cell::Cell(Vec2i index)
{
    mIndex = index;
    calcPosition();
    mIsOccupied = false;
};

Cell::Cell(Vec2i index, int size)
{
    mIndex = index;
    mSize = size;
    calcPosition();
}

bool Cell::isOccupied() const
{
    return mIsOccupied;
};

bool Cell::setOccupied(bool occupied)
{
    mIsOccupied = occupied;
    return mIsOccupied;
}

const Vec2i Cell::getIndex() const
{
    return mIndex;
}

const Vec2f Cell::getPosition() const
{
    return mPosition;
}

int Cell::getSize() const
{
    return mSize;
}

void Cell::calcPosition()
{
    mPosition = (mIndex * mSize) + Vec2i(mSize/2,mSize/2);
}

void Cell::addNeighbor(Cell& neighbor)
{
    mNeighbors.push_back( &neighbor );
};

void Cell::addNeighbors(Cells& neighbors)
{
    for(auto c : neighbors) {
        mNeighbors.push_back( c);
    }
};

void Cell::addNeighborIsEdge()
{
    mNeighbors.push_back(nullptr);
}

void Cell::draw()
{
    if (isOccupied()) {
        glColor3f(0.5, 0, 0);
        gl::drawSolidCircle(mPosition, 2);
    } else {
        glColor3f(0.5, 0.5, 0.5);
        gl::drawSolidCircle(mPosition, 1);
    }

    drawBorder();
}

void Cell::drawBorder()
{
    glColor3f(0.3, 0.3, 0.3);
    int radius = mSize/2;
    gl::drawLine(mPosition + Vec2i(radius, -radius), mPosition + Vec2i(radius, radius));
    gl::drawLine(mPosition + Vec2i(-radius, radius), mPosition + Vec2i(radius, radius));
}
