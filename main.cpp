#include <iostream>

#include "HubAeroport.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"
#include "Avion.h"

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


int main(int argc, char const *argv[]) {

    HubAeroport paris(PARIS_LAT, PARIS_LON);
    AeroportInternational rome(ROME_LAT, ROME_LON);
    AeroportRegional lyon(LYON_LAT, LYON_LON);
    AeroportRegional bruxelles(BRUXELLES_LAT, BRUXELLES_LON);
    AeroportRegional naples(NAPLES_LAT, NAPLES_LON);

    Moyen a = Avion();
    paris.ajoutLiaison(new Ligne<Avion>(&paris, &rome, 2) );
    std::cout << paris.getLiaisons().front()->getMoyen().getCapacite() << std::endl;

    return 0;
}
