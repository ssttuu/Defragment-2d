//
//  Cell.h
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#pragma once

#include <iostream>
#include "cinder/Vector.h"


class Cell {
public:
    typedef std::vector<Cell*> Cells;
    Cells mNeighbors;


    Cell(ci::Vec2i index);
    Cell(ci::Vec2i index, int size);
    
    bool isOccupied() const;
    bool setOccupied(bool occupied);
    
    const ci::Vec2i getIndex() const;
    const ci::Vec2f getPosition()const;
    const int getSize() const;
    void calcPosition();

    void addNeighbor(Cell *neighbor);
    void addNeighbors(Cells *neighbors);
    void addNeighborIsEdge();

    const Cells& getNeighbors() const;

    
    void draw();
    void drawBorder();
    

private:
    bool mIsOccupied = false;
    ci::Vec2i mIndex;
    ci::Vec2f mPosition;
    int mSize = 10;
};
