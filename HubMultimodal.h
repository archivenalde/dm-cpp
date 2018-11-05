#ifndef HUB_MULTIMODAL_H
#define HUB_MULTIMODAL_H

#include "HubAeroport.h"
#include "Gare.h"

class HubMultimodal : public HubAeroport, public Gare
{
public:
    HubMultimodal(double _latitude, double _longitude);
};

#endif
