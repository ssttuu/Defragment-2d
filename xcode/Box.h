//
//  Box.h
//  Defragment
//
//  Created by Stu Schwartz on 11/4/13.
//
//

#ifndef __Defragment__Box__
#define __Defragment__Box__

#include <iostream>
#include "cinder/Rect.h"
#include <list>

#endif /* defined(__Defragment__Box__) */


class Box : public Rect::Rect {
private:
    ci::Vec2i mPosition;
    ci::Vec2i mSize;

    typedef std::list<Box> Boxes;
    Boxes mNeighbors;
    
public:
    Box();
    Box(ci::Vec2i pos);
    Box(ci::Vec2i pos, ci::Vec2i size);
    
    ci::Vec2i getPosition();
    ci::Vec2i getSize();
    
    void setPosition( ci::Vec2i newPosition );
    
    
    //void getNeighbors(OutputIterator result);

    struct Neighbors {
        friend Box;
        typedef Boxes::iterator iterator;
        
        iterator begin() {
            return mBox.mNeighbors.begin();
        }
        
        iterator end() {
            return mBox.mNeighbors.end();
        }
    private:
        Neighbors(Box& b) : mBox(b) {}
        Box& mBox;
    } Neighbors;
    
};