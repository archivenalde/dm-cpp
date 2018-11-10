#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <list>
#include <map>

#include "Coordonnees.h"
#include "Ligne.h"
#include "Moyen.h"
#include "AbstractLigne.h"

#define RT 6378

class Terminal
{
    const Coordonnees position;
    std::list<AbstractLigne*> liaisons;
    std::map<std::pair<const Coordonnees, const Coordonnees>, int> tempsMoyen;
    std::map<const Coordonnees, int> flux;

protected:
    Terminal();

public:
    Terminal(double, double);

    const Coordonnees& getPosition() const;
    const std::list<AbstractLigne*>& getLiaisons() const;
    const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& getTempsMoyen() const;
    int getTempsMoyen(const Coordonnees&, const Coordonnees&) const;
    const std::map<const Coordonnees, int>& getFlux() const;
    void ajoutLiaison(AbstractLigne*);
    void retirerLiaison(AbstractLigne*);

    double distance(const Coordonnees&) const;

    ~Terminal();
};

#endif
