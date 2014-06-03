//
//  ViewFish.h
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#ifndef __EEtang__ViewFish__
#define __EEtang__ViewFish__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "View.h"

using namespace bongiovi;
using namespace ci::app;

class ViewFish : public View {
public:
    ViewFish();
    ViewFish(string vsPath, string fsPath);
    void                    render(gl::TextureRef, Vec3f pos);
    
private:
    void                    _init();
};

#endif /* defined(__EEtang__ViewFish__) */
