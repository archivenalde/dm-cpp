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

enum Moyen_e {TRAIN, AVION_ELECTRIQUE, AVION};

class Terminal
{
protected:
    static int NBTERMINAUX;

    std::string nom;
    const Coordonnees position;
    std::list<AbstractLigne*> liaisons;
    double tempsMoyen;
    std::map<const Coordonnees, int> flux;

    const int indice;

    Terminal();

public:
    Terminal(std::string, double, double, double);

    const std::string& getNom() const;
    const Coordonnees& getPosition() const;
    virtual const std::list<AbstractLigne*>& getLiaisons() const;
    double getTempsMoyen() const;
    const std::map<const Coordonnees, int>& getFlux() const;
    static int getNBTERMINAUX();
    int getIndice() const;
    void setFlux(Terminal**);

    virtual bool ajoutLiaisonPossible() const = 0;
    virtual void ajoutLiaison1sens(Terminal* _dest, Moyen_e _m);
    void ajoutLiaison2sens(Terminal* _dest, Moyen_e _m);
    void retirerLiaison(AbstractLigne*);

    bool estAccessible(Terminal*);

    double distance(const Coordonnees&) const;



    virtual ~Terminal();
};

#endif
