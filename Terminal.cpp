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
{}

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

void Terminal::ajoutLiaison1sens(Terminal* _dest, int _frequence, Moyen_e _m)
{
    if (ajoutLiaisonPossible())
    {
        AbstractLigne* l;
        switch(_m) {
            case TRAIN:
                l = new Ligne<Train>(this, _dest, _frequence);
                liaisons.push_back(l);
                break;
            case AVION_ELECTRIQUE:
                l = new Ligne<AvionElectrique>(this, _dest, _frequence);
                liaisons.push_back(l);
                break;
            case AVION:
                l = new Ligne<Avion>(this, _dest, _frequence);
                liaisons.push_back(l);
                break;
        };
    }
    else
    {
        std::cout << "Il y a trop de liaisons dans le Terminal " << nom << ". L'ajout de la liaison ne peut se faire." << std::endl;
    }
    /*if (l->getOrigine() == this)
    {
        liaisons.push_back(l);
        l->getDestination()->liaisons.push_back(l);
    }*/
}

void Terminal::ajoutLiaison2sens(Terminal* _dest, int _frequence, Moyen_e _m)
{
    ajoutLiaison1sens(_dest, _frequence, _m);
    _dest->ajoutLiaison1sens(this, _frequence, _m);
}

bool Terminal::estAccessible(Terminal* _t)
{
    std::list<AbstractLigne*>::iterator it;

    for (it = liaisons.begin(); it != liaisons.end(); ++it)
    {
        if ((*it)->getDestination()->position == _t->position)
            return true;
    }

    return false;
}


double Terminal::distance(const Coordonnees& _pos) const
{
    double horizontale, verticale, d = 2 * M_PI * RT/360.0;

    Coordonnees posOrigineRad(position.getLatitude() * M_PI/180, position.getLongitude() * M_PI/180);
    Coordonnees posArriveRad(_pos.getLatitude() * M_PI/180, _pos.getLongitude() * M_PI/180);

    verticale = sin((posArriveRad.getLatitude() - posOrigineRad.getLatitude())/2);
    horizontale = sin((posArriveRad.getLongitude() - posOrigineRad.getLongitude())/2);

    return 2.0 * RT * asin(sqrt(verticale * verticale + cos(posOrigineRad.getLatitude()) * cos(posArriveRad.getLatitude()) * horizontale * horizontale));
}

int Terminal::getNBTERMINAUX()
{
    return NBTERMINAUX;
}

int Terminal::getIndice() const
{
    return indice;
}
