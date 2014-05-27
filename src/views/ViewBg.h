//
//  ViewBg.h
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#ifndef __EEtang__ViewBg__
#define __EEtang__ViewBg__

#include <iostream>
#include "cinder/gl/Texture.h"
#include "View.h"

using namespace bongiovi;

class ViewBg : public View {
public:
    ViewBg();
    ViewBg(string vsPath, string fsPath);
    void                    render(gl::Texture);
    void                    render(gl::TextureRef);
    
private:
    void                    _init();
};

#endif /* defined(__EEtang__ViewBg__) */
