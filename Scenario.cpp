#include <iostream>

#include "Scenario.h"
#include "Voyage.h"
#include "Gare.h"
#include "HubAeroport.h"
#include "HubMultimodal.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"

Scenario::Scenario(int _n)
{
    switch (_n) {
        case 1: scenario1(); break;
        case 2: scenario2(); break;
        case 3: scenario3(); break;
        case 4: scenario4(); break;
        case 5: scenario5(); break;
        case 6: scenario6(); break;
        default: std::cout << "Le scenario attendu est un nombre entre 1 et 6" << std::endl; break;
    }
}

void Scenario::scenario1()
{
    std::cout << std::endl << "-------------Scenario 1-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new AeroportRegional("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new HubAeroport("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new AeroportRegional("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new AeroportInternational("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    terminaux[BRUXELLES]->ajoutLiaison2sens(terminaux[PARIS], AVION);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[LYON], AVION);
    terminaux[NAPLES]->ajoutLiaison2sens(terminaux[ROME], AVION);
    terminaux[ROME]->ajoutLiaison2sens(terminaux[PARIS], AVION);

    calculsInformationsVoyages();

    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario2()
{
    std::cout << std::endl << "-------------Scenario 2-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new HubMultimodal("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new AeroportRegional("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new AeroportInternational("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    terminaux[BRUXELLES]->ajoutLiaison2sens(terminaux[PARIS], TRAIN);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[LYON], AVION);
    terminaux[LYON]->ajoutLiaison2sens(terminaux[NAPLES], AVION);
    terminaux[NAPLES]->ajoutLiaison2sens(terminaux[ROME], AVION);
    terminaux[ROME]->ajoutLiaison2sens(terminaux[PARIS], AVION);

    calculsInformationsVoyages();
    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario3()
{
    std::cout << std::endl << "-------------Scenario 3-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new HubMultimodal("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new Gare("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new HubMultimodal("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new Gare("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    terminaux[BRUXELLES]->ajoutLiaison2sens(terminaux[PARIS], TRAIN);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[LYON], TRAIN);
    terminaux[LYON]->ajoutLiaison2sens(terminaux[ROME], TRAIN);
    terminaux[ROME]->ajoutLiaison2sens(terminaux[NAPLES], TRAIN);

    calculsInformationsVoyages();
    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario4()
{
    std::cout << std::endl << "-------------Scenario 4-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new AeroportInternational("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new AeroportInternational("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new AeroportInternational("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new AeroportInternational("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new AeroportInternational("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    for(int i = 1; i < NB_VILLES; i++)
        for(int j = 0; j < i; j++)
            terminaux[i]->ajoutLiaison2sens(terminaux[j], AVION);

    calculsInformationsVoyages();
    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario5()
{
    std::cout << std::endl << "-------------Scenario 5-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new Gare("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new Gare("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new Gare("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new Gare("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new Gare("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    terminaux[BRUXELLES]->ajoutLiaison2sens(terminaux[PARIS], TRAIN);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[LYON], TRAIN);
    terminaux[LYON]->ajoutLiaison2sens(terminaux[ROME], TRAIN);
    terminaux[ROME]->ajoutLiaison2sens(terminaux[NAPLES], TRAIN);

    calculsInformationsVoyages();
    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}


void Scenario::scenario6()
{
    std::cout << std::endl << "-------------Scenario 6-------------" << std::endl << std::endl;

    terminaux[BRUXELLES] = new AeroportRegional("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON);
    terminaux[PARIS] = new HubAeroport("Paris", PARIS_LAT, PARIS_LON);
    terminaux[LYON] = new AeroportRegional("Lyon", LYON_LAT, LYON_LON);
    terminaux[ROME] = new AeroportRegional("Rome", ROME_LAT, ROME_LON);
    terminaux[NAPLES] = new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON);

    setFluxAll();

    terminaux[PARIS]->ajoutLiaison2sens(terminaux[BRUXELLES], AVION);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[LYON], AVION);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[NAPLES], AVION);
    terminaux[PARIS]->ajoutLiaison2sens(terminaux[ROME], AVION);

    calculsInformationsVoyages();
    afficherInformationsVoyages();

    for(int i=0; i<NB_VILLES; i++)
        delete terminaux[i];
}






const Terminal& Scenario::getTerminal(int _i)
{
    return *(terminaux[_i]);
}

void Scenario::setFluxAll()
{
    for (int i = 0; i < NB_VILLES; ++i)
        terminaux[i]->setFlux(terminaux);
}

void Scenario::calculsInformationsVoyages()
{
    for (int i = 0; i < NB_VILLES; i++)
    {
        for (int j = 0; j < NB_VILLES; j++)
        {
            if (i != j)
            {
                Voyage v(terminaux[i], terminaux[j], terminaux);
                std::map<const Coordonnees, int> m = terminaux[i]->getFlux();
                int f = m[terminaux[j]->getPosition()];
                tempsTrajet[i][j] = v.tempsTrajet();
                empreinte[i][j] = v.empreinteTotale(f);
            }
        }
    }
}

void Scenario::afficherInformationsVoyages()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (i != j)
            {
                std::cout << "Le voyage de " << terminaux[i]->getNom() << " a " << terminaux[j]->getNom() << " met " << tempsTrajet[i][j] << "heure(s)." << std::endl;
                std::cout << "Le voyage a une empreinte totale de " << empreinte[i][j] << " kg." << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

double Scenario::getTempsTrajet(Ville_e _v, Ville_e _u)
{
    return tempsTrajet[_v][_u];
}

double Scenario::getTempsTrajet(int _v, int _u)
{
    return tempsTrajet[_v][_u];
}

double Scenario::getEmpreinte(Ville_e _v, Ville_e _u)
{
    return empreinte[_v][_u];
}

double Scenario::getEmpreinte(int _v, int _u)
{
    return empreinte[_v][_u];
}
