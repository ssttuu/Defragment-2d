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

Box::Box(Cell& cell)
{
    mCellPtr = &cell;

    mCellPtr->setOccupied(true);
    setPosition(mCellPtr->getPosition());
    setSize(mCellPtr->getSize());
    mColor = Rand::randVec3f();
    mSpeed = Rand::randFloat(0.1f, 1.0f);
}


void Box::setup()
{

}

void Box::update()
{
    // 1 is up
    // 3 is left
    // 4 is right
    // 6 is down

    std::vector<int> moveOptions;

    if( !isMoving()) {
        for(int i=0; i<NESW.size(); i++) {
            int dir = NESW.at(i);
            Cell* tmpCellPtr = mCellPtr->mNeighbors.at(dir);
            if ( tmpCellPtr != nullptr) {
                if ( !tmpCellPtr->isOccupied() && !justVisited(*tmpCellPtr)) {
                    moveOptions.push_back(dir);
                }
            }
        }

        if(moveOptions.size() > 0) {
            int directionChoice = Rand::randInt(0, moveOptions.size());
            beginMoveTo( *mCellPtr->mNeighbors.at( moveOptions.at(directionChoice) ) );
        }
    }
}

void Box::draw()
{
    drawTrail();
    drawBox();

}

void Box::drawBox()
{
    glColor3f(1.0, 1.0, 1.0);
    Vec2f rad = Vec2f(mRadius,mRadius);
    gl::drawSolidRect( ci::Rectf(mPosition.value()-rad, mPosition.value()+rad) );
    
    rad = Vec2f(mRadius-1,mRadius-1);
    glColor3f(mColor.x, mColor.y, mColor.z);
    gl::drawSolidRect( ci::Rectf(mPosition.value()-rad, mPosition.value()+rad) );
}

void Box::drawTrail()
{
    int start = 0;
    /*
    if (mCellHistory.size() > mTrailLength) {
        start = mCellHistory.size() - mTrailLength;
    }
    */
    glColor3f(mColor.x, mColor.y, mColor.z);
    mPath.clear();
    int j=0;
    for(int i=start; i<mCellHistory.size(); i++) {
        if(j==0) mPath.moveTo(mCellHistory.at(i)->getPosition());
        mPath.lineTo(mCellHistory.at(i)->getPosition());
        j++;
    }
    gl::draw(mPath);
}

void Box::beginMoveTo(Cell& cellPtr)
{
    mCellMovingToPtr = &cellPtr;
    mCellMovingToPtr->setOccupied(true);
    mIsMoving = true;

	app::timeline().appendTo( &mPosition, mCellMovingToPtr->getPosition(), mSpeed, EaseOutCubic() ).finishFn( std::bind( &Box::endMove, this ) );
}

void Box::move()
{
    std::cout << "moving" << std::endl;
}

void Box::endMove()
{
    //std::cout << "move Ended" << std::endl;
    mCellPtr->setOccupied(false);
    mCellPtr = mCellMovingToPtr;
    mIsMoving = false;
    appendCurrentCell();
}
                      
bool Box::isMoving() const
{
    return mIsMoving;
}

const Vec2f& Box::getPosition() const
{
    return mPosition;
}

int Box::getSize() const
{
    return mRadius*2;
}

int Box::getRadius() const
{
    return mRadius;
}


void Box::setPosition( Vec2f newPosition )
{
    mPosition() = newPosition;
}

void Box::setSize( int newSize )
{
    mRadius = newSize/2;
}

void Box::setRadius( int newRadius )
{
    mRadius = newRadius;
}

void Box::appendCurrentCell()
{
    mCellHistory.push_back( mCellPtr );
}

bool Box::justVisited(Cell& cell) const
{
    if (mCellHistory.size() <= 1) {
        return false;
    }
    // the last item in mCellHistory is the current cell we're in
    // the one before that is the one we just came from, hence -2
    return &cell == mCellHistory.at(mCellHistory.size()-2);
}
