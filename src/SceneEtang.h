//
//  SceneEtang.h
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#ifndef __EEtang__SceneEtang__
#define __EEtang__SceneEtang__

#include <iostream>

#include "cinder/gl/Texture.h"
#include "cinder/gl/Fbo.h"
#include "Scene.h"
#include "Fish.h"
#include "FishController.h"
#include "ViewBg.h"
#include "ViewFish.h"

using namespace bongiovi;

class SceneEtang : public Scene {
public:
    SceneEtang();
    void                    render();
//    void                    update();
    
    
private:
    void                    _initTextures();
    void                    _initViews();
    FishController*         _fishes;
    
    ViewBg*                 _vBg;
    ViewFish*               _vFish;
    gl::TextureRef          _texBg;
    gl::TextureRef          _texDot;
    gl::TextureRef          _texFish;
};

#endif /* defined(__EEtang__SceneEtang__) */
