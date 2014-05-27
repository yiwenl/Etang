//
//  Scene.h
//  KuaFuCinder
//
//  Created by Yiwen on 08/01/2014.
//
//

#ifndef __KuaFuCinder__Scene__
#define __KuaFuCinder__Scene__

#include <iostream>
#include "cinder/Camera.h"
#include "SceneQuat.h"

using namespace ci;
using namespace std;

namespace bongiovi {
    class Scene {
        public :
        Scene();
        void render();
        void update();
        float				cameraDistance;
        SceneQuat*          sceneQuat;
        
        
        protected :
        CameraPersp*		_camera;
        CameraOrtho*        _cameraOrtho;
        Vec3f				_eye, _center, _up;
        
    };
}

#endif /* defined(__KuaFuCinder__Scene__) */
