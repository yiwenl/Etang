#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EEtangApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void EEtangApp::setup()
{
}

void EEtangApp::mouseDown( MouseEvent event )
{
}

void EEtangApp::update()
{
}

void EEtangApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( EEtangApp, RendererGl )
