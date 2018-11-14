#ifndef FLUX_H
#define FLUX_H

enum Ville_e { BRUXELLES, PARIS, LYON, ROME, NAPLES};
#define NB_VILLES NAPLES + 1

#include "Voyage.h"
#include "Terminal.h"

class Flux {

    static Flux* instance;
    static int flux[NB_VILLES][NB_VILLES];

    Flux();
    Flux(const Flux& t);
    Flux& operator=(Flux&);

public:
    // Methode a appeler soit pour initialiser l'instance de Flux, soit pour recuperer cette instance.
    static Flux* getInstance() {
        if (instance == 0)
            instance = new Flux();
        return instance;
    }

    // Methode lorsqu'on a plus besoin de l'instance de Flux dans la suite du programme. Il sera necessaire de reinitialiser la Flux avec (void)Flux::getInstance().
    static void destroyInstance() {
        if (instance != 0)
        {
            delete instance;
            instance = 0;
        }
    }

    const int getFlux(const Voyage&) const; //Recupere le flux d'un voyage
    const int getFlux(Ville_e v, Ville_e u) const; //Recupere le flux du voyage de v a u
};

#endif
