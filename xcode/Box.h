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
#include "cinder/Path2d.h"

#include "Cell.h"

const int DIR_ARRAY[] = {1,3,4,6};
const std::vector<int> NESW (DIR_ARRAY, DIR_ARRAY + sizeof(DIR_ARRAY) / sizeof(int));

class Box {
private:
    ci::Anim<ci::Vec2f> mPosition;
    int mRadius;
    float mSpeed;
    ci::Vec3f mColor;

    bool mIsMoving = false;

    Cell *mCellPtr = nullptr;
    Cell *mCellMovingToPtr = nullptr;
    
    std::vector<Cell*> mCellHistory;
    int mTrailLength = 20;
    
    ci::Path2d mPath;

public:
    Box();
    Box(Cell *cellPtr);
    
    void setup();
    void update();
    
    void draw();
    void drawBox();
    void drawTrail();
    
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
 

    void appendCurrentCell();
    bool justVisited(Cell *cellPtr);
};

#endif /* defined(__Defragment__Box__) */