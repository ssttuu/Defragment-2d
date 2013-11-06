//
//  DefragmentApp.cpp
//  Defragment
//
//  Created by Stu Schwartz on 11/5/13.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "BoxController.h"
#include "Box.h"

#include "Grid.h"

using namespace ci;
using namespace ci::app;

class DefragmentApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
private:
    int mWidth = 1200;
    int mHeight = 800;
    
    Grid mGrid = Grid( mWidth, mHeight, 10);
    BoxController mBoxController = BoxController( &mGrid, 5000);
    
};

void DefragmentApp::prepareSettings( Settings *settings) {
    settings->setWindowSize( mWidth, mHeight);
    settings->setFrameRate( 60.0f);
};

void DefragmentApp::setup() {
    mGrid.setup();
    mBoxController.setup();
};

void DefragmentApp::mouseDown( MouseEvent event ) {
    
};

void DefragmentApp::update() {
    //mGrid.update();
    mBoxController.update();
};

void DefragmentApp::draw() {
    // clear out the window with black
    gl::clear( Color(0,0,0) );
    
    mBoxController.draw();
    mGrid.draw();
};

CINDER_APP_NATIVE( DefragmentApp, RendererGl );
