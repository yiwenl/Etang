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

using namespace bongiovi;

class SceneEtang : public Scene {
public:
    SceneEtang();
    void                    render();
    
    
private:
    void                    _initTextures();
    void                    _initViews();
};

#endif /* defined(__EEtang__SceneEtang__) */