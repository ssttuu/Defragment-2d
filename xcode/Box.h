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
#include <list>

#include "cinder/Vector.h"
#include "cinder/Rect.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"
#include "cinder/Timeline.h"

#include "Cell.h"

const int DIR_ARRAY[] = {1,3,4,6};
const std::vector<int> NESW (DIR_ARRAY, DIR_ARRAY + sizeof(DIR_ARRAY) / sizeof(int));

class Box {
private:
    //ci::Vec2i mPosition;
    int mRadius;
    ci::Vec3f mColor;

    Cell *mCellPtr = nullptr;
    Cell *mCellMovingToPtr = nullptr;

    ci::Anim<ci::Vec2f> mPosition;
    bool mIsMoving = false;
    
    float mSpeed;

public:
    Box();
    Box(Cell *cellPtr);
    
    void setup();
    void update();
    void draw();
    
    void beginMoveTo(Cell *cellPtr);
    void move();
    void endMove();
    
    bool isMoving();
    
    ci::Vec2f getPosition();
    int getSize();
    int getRadius();
    
    void setPosition( ci::Vec2f newPosition );
    void setSize( int newSize );
    void setRadius( int newRadius );
 

};

#endif /* defined(__Defragment__Box__) */