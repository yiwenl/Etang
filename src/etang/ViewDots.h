//
//  ViewDots.h
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#ifndef __Etang__ViewDots__
#define __Etang__ViewDots__

#include <iostream>

#include "View.h"

using namespace bongiovi;

namespace etang {
    
    class ViewDots : public View {
    public:
        ViewDots();
        ViewDots(string vsPath, string fsPath);
        void                    render();
        
    private:
        void                    _init();
        void                    _updatePositions();
    };
    
}

#endif /* defined(__Etang__ViewDots__) */

