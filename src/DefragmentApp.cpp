#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DefragmentApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void DefragmentApp::setup()
{
}

void DefragmentApp::mouseDown( MouseEvent event )
{
}

void DefragmentApp::update()
{
}

void DefragmentApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( DefragmentApp, RendererGl )
