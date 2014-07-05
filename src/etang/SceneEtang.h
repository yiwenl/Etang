//
//  SceneEtang.h
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#ifndef __Etang__SceneEtang__
#define __Etang__SceneEtang__

#include <iostream>

#include "cinder/gl/Texture.h"
#include "cinder/gl/Fbo.h"
#include "Scene.h"
#include "ViewDots.h"

using namespace bongiovi;

namespace etang {
    class SceneEtang : public Scene {
    public:
        SceneEtang();
        void                    render();
        
        
        gl::TextureRef          _texDot;
        
        ViewDots*               _viewDot;
        
    private:
        void                    _initTextures();
        void                    _initViews();
    };
}


#endif /* defined(__Etang__SceneEtang__) */
