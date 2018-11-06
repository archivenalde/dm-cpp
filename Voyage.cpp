#include <cmath>
#include "Voyage.h"
#include "Terminal.h"
#include "Ligne.h"

Voyage::Voyage(Terminal* _origine, Terminal* _destination)
: origine(_origine), destination(_destination)
{}

Voyage::~Voyage()
{}

void Voyage::ajoutLigne(Ligne<Moyen>* ligne)
{
    lignes.push_back(ligne);
}

double Voyage::tempsTrajetTotal(int flux)
{

}

double Voyage::empreinteTotale(int flux)
{
    double empreinteTotale = 0;
    double distance = 0, empreinte = 0;
    int nbVoyages = 0;

    for (std::list<Ligne<Moyen>*>::iterator it = lignes.begin(); it != lignes.end(); it++)
	{
        nbVoyages = std::ceil((double)flux/(*it)->getMoyen().getCapacite());
        distance = (*it)->getOrigine().distance((*it)->getDestination().getPosition());
        empreinte = (*it)->getMoyen().getEmpreinte();

        empreinteTotale += nbVoyages * distance * empreinte;
    }

    return empreinteTotale;
}
