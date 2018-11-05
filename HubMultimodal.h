#ifndef HUB_MULTIMODAL_H
#define HUB_MULTIMODAL_H

#include "HubAeroport.h"
#include "Gare.h"

class HubMultimodal : public HubAeroport, public Gare
{
protected:
    HubMultimodal();
public:
    HubMultimodal(double, double);
    ~HubMultimodal();
};

#endif
