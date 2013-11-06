//
//  Cell.h
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#ifndef __Defragment__Cell__
#define __Defragment__Cell__

#include <iostream>
#include "cinder/Vector.h"

#include <boost/iterator.hpp>
#include <boost/iterator/filter_iterator.hpp>

class Cell {
public:
    typedef std::vector<Cell*> Cells;
    Cells mNeighbors;


    Cell(ci::Vec2i index);
    Cell(ci::Vec2i index, int size);
    
    bool isOccupied();
    bool setOccupied(bool occupied);
    
    ci::Vec2i getIndex();
    ci::Vec2f getPosition();
    int getSize();
    void calcPosition();

    void addNeighbor(Cell *neighbor);
    void addNeighbors(Cells *neighbors);
    void addNeighborIsEdge();

    struct Neighbors {
        friend Cell;
        typedef Cells::iterator iterator;
        
        iterator begin() {
            return mCell.mNeighbors.begin();
        }
        
        iterator end() {
            return mCell.mNeighbors.end();
        }
/*
        struct isOccupied {
            bool operator()(Cell& c) {
                return c.isOccupied();
            }
        };

        struct Occupied {
            friend Neighbors;
            friend Cell;
            typedef boost::filter_iterator<isOccupied, Cells::iterator> iterator;
            typedef boost::filter_iterator<isOccupied, Cells::const_iterator> const_iterator;
            
            iterator begin() {
                return boost::make_filter_iterator<isOccupied>(mCell.mNeighbors.begin(),mCell.mNeighbors.end());
            }

            iterator end() {
                return boost::make_filter_iterator<isOccupied>(mCell.mNeighbors.end(),mCell.mNeighbors.end());
            }
        private:
            Occupied(Cell& c) : mCell(c) {};
            Cell& mCell;
        } Occupied;
*/
    private:
        Neighbors(Cell& c) : mCell(c) {};
        Cell& mCell;
    } Neighbors;

    
    void draw();
    void drawBorder();
    

private:
    bool mIsOccupied = false;
    ci::Vec2i mIndex;
    ci::Vec2f mPosition;
    int mSize = 10;
};

#endif /* defined(__Defragment__Cell__) */
