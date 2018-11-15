#include <iostream>

#include "Scenario.h"
#include "Flux.h"
#include "Terminal.h"
#include "Voyage.h"
#include "Gare.h"
#include "HubAeroport.h"
#include "HubMultimodal.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"

void Scenario::scenario1()
{
    std::cout << "Scenario 1" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new HubAeroport("Paris", PARIS_LAT, PARIS_LON),
                                      new AeroportRegional("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new AeroportRegional("Lyon", LYON_LAT, LYON_LON),
                                      new AeroportInternational("Rome", ROME_LAT, ROME_LON),
                                      new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    terminaux[BRUXELLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(BRUXELLES, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[BRUXELLES], f->getFlux(PARIS, BRUXELLES), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(PARIS, LYON), AVION);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(LYON, PARIS), AVION);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(LYON, NAPLES), AVION);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(NAPLES, LYON), AVION);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(NAPLES, ROME), AVION);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(ROME, NAPLES), AVION);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(ROME, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(PARIS, ROME), AVION);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario2()
{
    std::cout << "Scenario 2" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new HubMultimodal("Paris", PARIS_LAT, PARIS_LON),
                                      new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new AeroportRegional("Lyon", LYON_LAT, LYON_LON),
                                      new AeroportInternational("Rome", ROME_LAT, ROME_LON),
                                      new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    terminaux[BRUXELLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(BRUXELLES, PARIS), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[BRUXELLES], f->getFlux(PARIS, BRUXELLES), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(PARIS, LYON), AVION);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(LYON, PARIS), AVION);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(LYON, NAPLES), AVION);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(NAPLES, LYON), AVION);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(NAPLES, ROME), AVION);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(ROME, NAPLES), AVION);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(ROME, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(PARIS, ROME), AVION);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario3()
{
    std::cout << "Scenario 3" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new HubMultimodal("Paris", PARIS_LAT, PARIS_LON),
                                      new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new Gare("Lyon", LYON_LAT, LYON_LON),
                                      new HubMultimodal("Rome", ROME_LAT, ROME_LON),
                                      new Gare("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    terminaux[BRUXELLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(BRUXELLES, PARIS), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[BRUXELLES], f->getFlux(PARIS, BRUXELLES), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(PARIS, LYON), TRAIN);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(LYON, PARIS), TRAIN);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(LYON, ROME), TRAIN);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(ROME, LYON), TRAIN);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(ROME, NAPLES), TRAIN);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(NAPLES, ROME), TRAIN);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario4()
{
    std::cout << "Scenario 4" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new AeroportInternational("Paris", PARIS_LAT, PARIS_LON),
                                      new AeroportInternational("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new AeroportInternational("Lyon", LYON_LAT, LYON_LON),
                                      new AeroportInternational("Rome", ROME_LAT, ROME_LON),
                                      new AeroportInternational("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    for(int i = 1; i<NB_VILLES; i++)
        for(int j = 0; j<i; j++)
        {
            terminaux[i]->ajoutLiaison1sens(terminaux[j], f->getFlux((Ville_e) i, (Ville_e) j), AVION);
            terminaux[j]->ajoutLiaison1sens(terminaux[i], f->getFlux((Ville_e) j, (Ville_e) i), AVION);
        }

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario5()
{
    std::cout << "Scenario 5" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new Gare("Paris", PARIS_LAT, PARIS_LON),
                                      new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new Gare("Lyon", LYON_LAT, LYON_LON),
                                      new Gare("Rome", ROME_LAT, ROME_LON),
                                      new Gare("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    terminaux[BRUXELLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(BRUXELLES, PARIS), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[BRUXELLES], f->getFlux(PARIS, BRUXELLES), TRAIN);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(PARIS, LYON), TRAIN);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(LYON, PARIS), TRAIN);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(LYON, ROME), TRAIN);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(ROME, LYON), TRAIN);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(ROME, NAPLES), TRAIN);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(NAPLES, ROME), TRAIN);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario6()
{
    std::cout << "Scenario 6" << std::endl;

    Terminal* terminaux[NB_VILLES] = {new HubAeroport("Paris", PARIS_LAT, PARIS_LON),
                                      new AeroportRegional("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                                      new AeroportRegional("Lyon", LYON_LAT, LYON_LON),
                                      new AeroportRegional("Rome", ROME_LAT, ROME_LON),
                                      new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON)
                                     };

    Flux* f = Flux::getInstance();

    terminaux[PARIS]->ajoutLiaison1sens(terminaux[BRUXELLES], f->getFlux(PARIS, BRUXELLES), AVION);
    terminaux[BRUXELLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(BRUXELLES, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[LYON], f->getFlux(PARIS, LYON), AVION);
    terminaux[LYON]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(LYON, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[NAPLES], f->getFlux(PARIS, NAPLES), AVION);
    terminaux[NAPLES]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(NAPLES, PARIS), AVION);
    terminaux[PARIS]->ajoutLiaison1sens(terminaux[ROME], f->getFlux(PARIS, ROME), AVION);
    terminaux[ROME]->ajoutLiaison1sens(terminaux[PARIS], f->getFlux(ROME, PARIS), AVION);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    std::cout << f->getFlux(voyage) << std::endl;

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl << std::endl;

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}
