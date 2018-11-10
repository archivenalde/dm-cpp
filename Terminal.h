#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <list>
#include <map>

#include "Coordonnees.h"
#include "Ligne.h"
#include "Moyen.h"

#define RT 6378

class Terminal
{
    const Coordonnees position;
    template <class T>


    //std::list<Ligne<>*> liaisons;
    std::map<std::pair<const Coordonnees, const Coordonnees>, int> tempsMoyen;
    std::map<const Coordonnees, int> flux;

protected:
    Terminal();

public:
    Terminal(double, double);


    class Liaison
    {
    private:
      Moyen m;
      std::list<Ligne<Moyen>*> liaisons;

    public:
      Liaison(T _m) : m(_m) {}

      const std::list<Ligne<Moyen>*>& getLiaisons() const
      {
        return liaisons;
      }

      void ajoutLiaison(Ligne<Moyen>* l)
      {
        if (l->getDestination() == this)
            liaisons.push_back(l);
      }
      //void retirerLiaison(Ligne<Moyen>*);
    }



    const Coordonnees& getPosition() const;
    const std::map<std::pair<const Coordonnees, const Coordonnees>, int>& getTempsMoyen() const;
    int getTempsMoyen(const Coordonnees&, const Coordonnees&) const;
    const std::map<const Coordonnees, int>& getFlux() const;


    double distance(const Coordonnees&) const;

    ~Terminal();
};

#endif
