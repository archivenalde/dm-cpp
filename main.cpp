#include <iostream>

#include "Terminal.h"
#include "HubAeroport.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"
#include "Avion.h"
#include "Train.h"
#include "Voyage.h"

/*
            Latitude       Longitude
Paris       48.867         2.333
Bruxelles   50.850         4.351
Lyon        45.764         4.835
Rome        41.902         12.496
Naples      40.851         14.268
*/

#define PARIS_LAT 48.867
#define PARIS_LON 2.333
#define BRUXELLES_LAT 50.850
#define BRUXELLES_LON 4.351
#define LYON_LAT 45.764
#define LYON_LON 4.835
#define ROME_LAT 41.902
#define ROME_LON 12.496
#define NAPLES_LAT 40.851
#define NAPLES_LON 14.268

#define BRUXELLES 0
#define PARIS 1
#define LYON 2
#define ROME 3
#define NAPLES 4


int main(int argc, char const *argv[]) {

    Terminal* terminaux[5] = {new AeroportRegional("Bruxelles", BRUXELLES_LAT, BRUXELLES_LON),
                             new HubAeroport("Paris", PARIS_LAT, PARIS_LON),
                             new AeroportRegional("Lyon", LYON_LAT, LYON_LON),
                             new AeroportInternational("Rome", ROME_LAT, ROME_LON),
                             new AeroportRegional("Naples", NAPLES_LAT, NAPLES_LON)};


    int flux[5][5] = {{-1, 13000, 5500, 4500, 2000},
                      {12500, -1, 18000, 10000, 4000},
                      {6000, 19000, -1, 6500, 2500},
                      {5000, 9000, 6000, -1, 11000},
                      {2500, 5000, 3000, 10000, -1}};

    terminaux[PARIS]->ajoutLiaison2sens(terminaux[ROME], 2, AVION);
    terminaux[LYON]->ajoutLiaison2sens(terminaux[PARIS], 2, AVION);
    terminaux[BRUXELLES]->ajoutLiaison2sens(terminaux[PARIS], 2, AVION);
    terminaux[NAPLES]->ajoutLiaison2sens(terminaux[ROME], 2, AVION);
    terminaux[LYON]->ajoutLiaison2sens(terminaux[NAPLES], 2, AVION);

    Voyage voyage(terminaux[LYON], terminaux[NAPLES]);

    voyage.determinerCorrespondances(terminaux);
    std::cout << voyage.tempsTrajet() << std::endl;

    return 0;
}
