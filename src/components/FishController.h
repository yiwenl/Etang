//
//  FishController.h
//  EEtang
//
//  Created by Yiwen on 03/06/2014.
//
//

#ifndef __EEtang__FishController__
#define __EEtang__FishController__

#include <iostream>
#include "Fish.h"

using namespace std;
using namespace ci;
using namespace ci::app;

class FishController {
public :
    FishController();
    void update();
    
    vector<Fish*>           getFishes();
    
private :
    void _init();
    vector<Fish*>           _fishes;
};

#endif /* defined(__EEtang__FishController__) */
