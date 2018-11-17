#include <iostream>
#include <list>
#include "HubMultimodal.h"
#include "Ligne.h"
#include "Train.h"
#include "Avion.h"
#include "AvionElectrique.h"

HubMultimodal::HubMultimodal(std::string _nom, double _latitude, double _longitude)
: HubAeroport(_nom, _latitude, _longitude), gare(_nom, _latitude, _longitude)
{
    NBTERMINAUX--; // Pour eviter que la gare et le HubAeroport ne soit compter deux fois.
    std::cout << "Construction du hub multimodal de " << _nom << " terminée" << std::endl;
}

HubMultimodal::~HubMultimodal()
{
    NBTERMINAUX++; //Symetrique au constructeur, pour ne retirer que le HubMultimodal, et non la gare en plus.
}

void HubMultimodal::ajoutLiaison1sens(Terminal* _dest, Moyen_e _m)
{
    if (_m == TRAIN)
        gare.ajoutLiaison1sens(_dest, TRAIN);
    else
        HubAeroport::ajoutLiaison1sens(_dest, _m);

    AbstractLigne* l;
    switch(_m) {
        case TRAIN:
            l = new Ligne<Train>(this, _dest);
            liaisonsGareAeroport.push_back(l);
            break;
        case AVION_ELECTRIQUE:
            l = new Ligne<AvionElectrique>(this, _dest);
            liaisonsGareAeroport.push_back(l);
            break;
        case AVION:
            l = new Ligne<Avion>(this, _dest);
            liaisonsGareAeroport.push_back(l);
            break;
    };

}

const std::list<AbstractLigne*>& HubMultimodal::getLiaisons() const
{
    return liaisonsGareAeroport;
}

bool HubMultimodal::ajoutLiaisonPossible() const
{
    return HubAeroport::ajoutLiaisonPossible() && gare.ajoutLiaisonPossible();
}
