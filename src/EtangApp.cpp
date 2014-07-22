#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneEtang.h"
#include "Model.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace etang;

class EtangApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void keyDown( KeyEvent event );
    
    private :
    SceneEtang*                 _scene;
    params::InterfaceGlRef      _params;
    
};

void EtangApp::setup()
{
    setWindowSize(1280, 720);
    setFrameRate(30);
    setWindowPos(0, 0);
    srand(time(NULL));
    
    gl::enable( GL_TEXTURE_2D );
    gl::enable( GL_TEXTURE_RECTANGLE_ARB );
    
    gl::enable( GL_VERTEX_PROGRAM_POINT_SIZE );
    gl::enable( GL_DEPTH_TEST );
    gl::enable( GL_CULL_FACE );
    gl::enable( GL_POINT_SMOOTH );
    gl::enableAlphaBlending();

    
    _scene          = new SceneEtang(getWindow());
    _params         = params::InterfaceGl::create( "Etang", Vec2i( 300, getWindowHeight()-30 ) );
    Model::getInstance();
}

void EtangApp::update()
{
//    _scene->update();
    Model::getInstance().controller->update();
}

void EtangApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
    _params->draw();
}

void EtangApp::keyDown( KeyEvent event) {
    switch(event.getChar()) {
        case 'f' :
            setFullScreen(!isFullScreen());
            break;
    }
}


CINDER_APP_NATIVE( EtangApp, RendererGl )
