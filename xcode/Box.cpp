//
//  Box.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/4/13.
//
//

#include "Box.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include <boost/foreach.hpp>

using namespace ci;

Box::Box() : Neighbors(*this) {
    mPosition = Vec2i(0,0);
    mSize = Vec2i(1,1);
};

Box::Box(ci::Vec2i pos) : Neighbors(*this) {
    mPosition = pos;
    mSize = Vec2i(1,1);
};

Box::Box(ci::Vec2i pos, ci::Vec2i size) : Neighbors(*this) {
    mPosition = pos;
    mSize = size;
};

// GETTERS

ci::Vec2i Box::getPosition() {
    return mPosition;
};

ci::Vec2i Box::getSize() {
    return mSize;
};

// SETTERS
void Box::setPosition( Vec2i newPosition ) {
    mPosition = newPosition;
}