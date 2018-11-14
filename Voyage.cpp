#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

#include "Voyage.h"
#include "Terminal.h"
#include "Ligne.h"


bool estPlusPetit(int a, int b)
{
    if (a < 0 && b >= 0)
        return false;
    else if (a >= 0 && b < 0)
        return true;
    else return a < b;

}

int trouve_min(int* _distances, const std::list<int>& _Q)
{
    int dmin = -1;
    int sommet = -2;

    for (auto s: _Q)
    {
        if (estPlusPetit(_distances[s], dmin))
        {
            dmin = _distances[s];
            sommet = s;
        }
    }

    return sommet;
}

void maj_distances(int* _pred, int* _dist, int sdeb, int sfin)
{
    if (estPlusPetit(_dist[sdeb] + 1, _dist[sfin])) // Peut_être remplacer + 1 par + distance de Terminal...
    {
        _dist[sfin] = _dist[sdeb] + 1;
        _pred[sfin] = sdeb;
    }
}


Voyage::Voyage(Terminal* _origine, Terminal* _destination)
: origine(_origine), destination(_destination)
{
    std::cout << "Voyage entre " << origine->getNom() << " et " << destination->getNom() << " programmé"<< std::endl;
}

Voyage::~Voyage()
{}

void Voyage::ajoutLigne(AbstractLigne* ligne)
{
    lignes.push_back(ligne);
}

void Voyage::determinerCorrespondances(Terminal** _noeuds)
{
    Terminal* deb = origine;
    Terminal* fin = destination;
    int nb = Terminal::getNBTERMINAUX();

    int d[5];
    int predecesseur[5];
    /*int *d = new int[nb];
    int *predecesseur = new int[nb];*/

    std::list<int> Q; //Ensemble des noeuds, i est leur indice

    //Initialisation
    for (int i = 0; i < nb; ++i)
    {
        d[i] = -1;
        predecesseur[i] = -1;
        Q.push_back(i);
    }
    d[deb->getIndice()] = 0;

    while(!Q.empty())
    {
        int smin = trouve_min(d, Q);
        Q.remove_if([smin](int n){ return n == smin; });

        for (int q: Q)
        {
            if (_noeuds[smin]->estAccessible(_noeuds[q]))
                maj_distances(predecesseur, d, smin, q);
        }
    }

    std::list<int> A;

    int s = fin->getIndice();
    while (s != deb->getIndice())
    {
        A.push_back(s);
        s = predecesseur[s];
    }
    A.reverse();

    int nor = deb->getIndice();
    while (! A.empty())
    {
        int next = _noeuds[nor]->getIndice();
        if (A.size() > 0)
        {
            for (auto l : _noeuds[next]->getLiaisons())
            {
                if (l->getDestination()->getIndice() == A.front())
                    lignes.push_back(l);
            }
        }
        nor = A.front();
        A.pop_front();
    }

    for (auto c : lignes)
    {
        std::cout << c->getOrigine()->getNom() << " -> " << c->getDestination()->getNom() << std::endl;
    }
}

double Voyage::tempsTrajet()
{
    /*double tempsTotal = 0;
    double distance = 0, vitesse = 0, tempsAttente = 0;
    int nbVoyages = 0;
    Terminal* origine,* suivant,* destination;
    std::list<AbstractLigne*>::iterator next;

    for (std::list<AbstractLigne*>::iterator it = lignes.begin(); it != lignes.end(); it++)
	{
        origine = (*it)->getOrigine();
        suivant = (*it)->getDestination();
        nbVoyages = std::ceil((double)flux/((*it)->getMoyen().getCapacite()));
        distance = origine->distance(suivant->getPosition());
        vitesse = (*it)->getMoyen().getVitesse();

        tempsTotal += nbVoyages * (distance/vitesse);

        next = std::next(it);
        if(next != lignes.end() && suivant == (*next)->getOrigine())
        {
            destination = (*next)->getDestination();

            tempsAttente = suivant->getTempsMoyen(origine->getPosition(), destination->getPosition());
            tempsTotal += nbVoyages * tempsAttente;
        }
    }
    */

    double tempsTotal = 0, tempsAttente = 0;
    double distance = 0, vitesse = 0;
    Terminal* origine, *suivant;
    std::list<AbstractLigne*>::iterator next;


    for (std::list<AbstractLigne*>::iterator it = lignes.begin(); it != lignes.end(); it++)
    {
        origine = (*it)->getOrigine();
        suivant = (*it)->getDestination();
        distance = origine->distance(suivant->getPosition());
        vitesse = (*it)->getMoyen().getVitesse();

        tempsTotal += (distance/vitesse);

        next = std::next(it);
        if(next != lignes.end() && suivant == (*next)->getOrigine())
        {
            destination = (*next)->getDestination();

            tempsAttente = suivant->getTempsMoyen();
            tempsTotal += tempsAttente;
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

    for (std::list<AbstractLigne*>::iterator it = lignes.begin(); it != lignes.end(); it++)
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

Terminal* Voyage::getOrigine() const
{
    return origine;
}


Terminal* Voyage::getDestination() const
{
    return destination;
}
