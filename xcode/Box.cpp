//
//  Box.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/4/13.
//
//

#include "Box.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "cinder/Rect.h"
#include "cinder/gl/gl.h"
#include "cinder/Timeline.h"

#include "Cell.h"

using namespace ci;

//Box::Box() : mRadius(10), mIsMoving(false) {}

Box::Box(Cell *cellPtr) {

    mCellPtr = cellPtr;
    mCellPtr->setOccupied(true);
    setPosition(mCellPtr->getPosition());
    setSize(mCellPtr->getSize());
    mColor = Rand::randVec3f()/2;
    mSpeed = Rand::randFloat(0.1f, 1.0f);
    //std::cout << "new box at" << mCellPtr->getPosition() << "," << getPosition() << std::endl;
}


void Box::setup() {

}

void Box::update() {
    // 1 is up
    // 3 is left
    // 4 is right
    // 6 is down
    //vector<int> NEWS({1,3,4,6});
    std::vector<int> moveOptions;
    
    
    if(isMoving() == false) {
        for(int i=0; i<NESW.size(); i++) {
            int dir = NESW.at(i);
            if ((mCellPtr->mNeighbors).at( dir ) != nullptr) {
                if ( mCellPtr->mNeighbors.at( dir )->isOccupied() == false) {
                    moveOptions.push_back(dir);
                }
            }
        }
        
        
        if(moveOptions.size() > 0) {
            int directionChoice = Rand::randInt(0, moveOptions.size());
            
            beginMoveTo(mCellPtr->mNeighbors.at( moveOptions.at(directionChoice) ) );
        }
    }
}

void Box::draw() {
    glColor3f(1.0, 1.0, 1.0);
    Vec2f rad = Vec2f(mRadius,mRadius);
    gl::drawSolidRect( ci::Rectf(mPosition.value()-rad, mPosition.value()+rad) );

    rad = Vec2f(mRadius-1,mRadius-1);
    glColor3f(mColor.x, mColor.y, mColor.z);
    gl::drawSolidRect( ci::Rectf(mPosition.value()-rad, mPosition.value()+rad) );
}

void Box::beginMoveTo(Cell *cellPtr) {
    mCellMovingToPtr = cellPtr;
    mCellMovingToPtr->setOccupied(true);
    mIsMoving = true;

	app::timeline().appendTo( &mPosition, mCellMovingToPtr->getPosition(), mSpeed, EaseOutCubic() ).finishFn( std::bind( &Box::endMove, this ) );
}

void Box::move() {
    std::cout << "moving" << std::endl;
}

void Box::endMove() {
    //std::cout << "move Ended" << std::endl;
    mCellPtr->setOccupied(false);
    mCellPtr = mCellMovingToPtr;
    mIsMoving = false;
}
                      
bool Box::isMoving() {
    return mIsMoving;
}

Vec2f Box::getPosition() {
    return mPosition;
}

int Box::getSize() {
    return mRadius*2;
}

int Box::getRadius() {
    return mRadius;
}


void Box::setPosition( Vec2f newPosition ) {
    mPosition() = newPosition;
}

void Box::setSize( int newSize ) {    
    mRadius = newSize/2;
}

void Box::setRadius( int newRadius ) {
    mRadius = newRadius;
}
