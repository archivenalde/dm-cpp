#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

#include "Voyage.h"
#include "Terminal.h"
#include "Ligne.h"

Voyage::Voyage(Terminal* _origine, Terminal* _destination)
: origine(_origine), destination(_destination)
{
    std::cout << "Voyage entre " << origine->getNom() << " et " << destination->getNom() << " programmé"<< std::endl;
}

Voyage::~Voyage()
{}

void Voyage::ajoutLigne(Ligne<Moyen>* ligne)
{
    lignes.push_back(ligne);
}

double Voyage::tempsTrajetTotal(int flux)
{
    double tempsTotal = 0;
    double distance = 0, vitesse = 0, tempsAttente = 0;
    int nbVoyages = 0;
    Terminal* origine,* suivant,* destination;
    std::list<Ligne<Moyen>*>::iterator next;

    for (std::list<Ligne<Moyen>*>::iterator it = lignes.begin(); it != lignes.end(); it++)
	{
        origine = (*it)->getOrigine();
        suivant = (*it)->getDestination();
        nbVoyages = std::ceil((double)flux/((*it)->getMoyen().getCapacite()));
        distance = origine->distance(destination->getPosition());
        vitesse = (*it)->getMoyen().getVitesse();

        tempsTotal += nbVoyages * (distance/vitesse);

        next = std::next(it);
        if(next != lignes.end() && suivant == (*next)->getOrigine())
        {
            destination = (*next)->getDestination();

            /* TODO: recuperation du temps d'attente */
            tempsAttente = suivant->getTempsMoyen(origine->getPosition(), destination->getPosition());
            tempsTotal += nbVoyages * tempsAttente;
        }
    }

    return tempsTotal;
}

double Voyage::empreinteTotale(int flux)
{
    double empreinteTotale = 0;
    double distance = 0, empreinte = 0;
    int nbVoyages = 0;
    Terminal* origine,* destination;

    for (std::list<Ligne<Moyen>*>::iterator it = lignes.begin(); it != lignes.end(); it++)
	{
        origine = (*it)->getOrigine();
        destination = (*it)->getDestination();
        // ceil : entier superieur. Recupere le nombre de moyens differents pour transporter tous les passagers
        nbVoyages = std::ceil((double)flux/(*it)->getMoyen().getCapacite());
        distance = origine->distance(destination->getPosition());
        empreinte = (*it)->getMoyen().getEmpreinte();

        empreinteTotale += nbVoyages * distance * empreinte;
    }

    return empreinteTotale;
}
