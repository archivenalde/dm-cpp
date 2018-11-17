#ifndef HUB_MULTIMODAL_H
#define HUB_MULTIMODAL_H

#include <list>
#include "AbstractLigne.h"
#include "HubAeroport.h"
#include "Gare.h"

class HubMultimodal : public HubAeroport
{
private:
    Terminal* gare;

    std::list<AbstractLigne*> liaisonsGareAeroport;
public:
    HubMultimodal(std::string, double, double);
    ~HubMultimodal();

    void ajoutLiaison1sens(Terminal* _dest, Moyen_e _m);
    const std::list<AbstractLigne*>& getLiaisons() const;
    bool ajoutLiaisonPossible() const;
};

#endif
