#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EtangApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void EtangApp::setup()
{
}

void EtangApp::mouseDown( MouseEvent event )
{
}

void EtangApp::update()
{
}

void EtangApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( EtangApp, RendererGl )
