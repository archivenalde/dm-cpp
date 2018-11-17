#include <list>
#include <map>
#include <cmath>
#include <iostream>

#include "Terminal.h"
#include "AbstractLigne.h"
#include "Ligne.h"
#include "Train.h"
#include "Avion.h"
#include "AvionElectrique.h"
#include "Flux.h"

int Terminal::NBTERMINAUX = 0;


Terminal::Terminal()
: position(0.0, 0.0), indice(NBTERMINAUX)
{
    NBTERMINAUX++;
}

Terminal::Terminal(std::string _nom, double _lat, double _lon, double _tpsMoyen)
: nom(_nom), position(_lat, _lon), tempsMoyen(_tpsMoyen), indice(NBTERMINAUX)
{
    NBTERMINAUX++;
}

Terminal::~Terminal()
{
    NBTERMINAUX--;
}

const std::string& Terminal::getNom() const
{
    return nom;
}

const Coordonnees& Terminal::getPosition() const
{
    return position;
}

const std::list<AbstractLigne*>& Terminal::getLiaisons() const
{
    return liaisons;
}

double Terminal::getTempsMoyen() const
{
    return tempsMoyen;
}

const std::map<const Coordonnees, int>& Terminal::getFlux() const
{
    return flux;
}

void Terminal::ajoutLiaison1sens(Terminal* _dest, Moyen_e _m)
{
    if (ajoutLiaisonPossible())
    {
        AbstractLigne* l;
        switch(_m) {
            case TRAIN:
                l = new Ligne<Train>(this, _dest);
                liaisons.push_back(l);
                break;
            case AVION_ELECTRIQUE:
                l = new Ligne<AvionElectrique>(this, _dest);
                liaisons.push_back(l);
                break;
            case AVION:
                l = new Ligne<Avion>(this, _dest);
                liaisons.push_back(l);
                break;
        };
    }
    else
    {
        std::cout << "Il y a trop de liaisons dans le Terminal " << nom << ". L'ajout de la liaison ne peut se faire." << std::endl;
    }

}

void Terminal::ajoutLiaison2sens(Terminal* _dest, Moyen_e _m)
{
    ajoutLiaison1sens(_dest, _m);
    _dest->ajoutLiaison1sens(this, _m);
}

bool Terminal::estAccessible(Terminal* _t)
{
    std::list<AbstractLigne*>::iterator it;
    std::list<AbstractLigne*> tmpl = getLiaisons();

    for (it = tmpl.begin(); it != tmpl.end(); ++it)
    {
        if ((*it)->getDestination()->position == _t->position)
            return true;
    }

    return false;
}


double Terminal::distance(const Coordonnees& _pos) const
{
    double longitude, coeff = M_PI/180;

    Coordonnees posOrigineRad(position.getLatitude() * coeff, position.getLongitude() * coeff);
    Coordonnees posArriveRad(_pos.getLatitude() * coeff, _pos.getLongitude() * coeff);

    longitude = cos((posArriveRad.getLongitude() - posOrigineRad.getLongitude()));

    return RT * acos(cos(posOrigineRad.getLatitude())*cos(posArriveRad.getLatitude())*longitude + sin(posOrigineRad.getLatitude())*sin(posArriveRad.getLatitude()));
}

int Terminal::getNBTERMINAUX()
{
    return NBTERMINAUX;
}

int Terminal::getIndice() const
{
    return indice;
}

void Terminal::setFlux(Terminal** _t)
{
    Flux* f = Flux::getInstance();

    for (int i = 0; i < NB_VILLES; ++i)
    {
        flux.insert(std::pair<const Coordonnees, int>(_t[i]->getPosition(), f->getFlux(this->indice, i)));
    }
}
