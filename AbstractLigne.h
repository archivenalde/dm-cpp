#ifndef ABSTRACTLIGNE_H
#define ABSTRACTLIGNE_H

#include "Moyen.h"

class Terminal;

class AbstractLigne {

  virtual const Moyen& do_getMoyen() const = 0;
  virtual Terminal* do_getOrigine() const = 0;
  virtual Terminal* do_getDestination() const = 0;
  virtual int do_getFrequence() const = 0;

public:
  const Moyen& getMoyen() const;
  Terminal* getOrigine() const;
  Terminal* getDestination() const;
  int getFrequence() const;

  friend bool operator==(const AbstractLigne& l1, const AbstractLigne& l2)
  {
      return l1.getMoyen() == l2.getMoyen() && l1.getOrigine() == l2.getOrigine() && l1.getDestination() == l2.getDestination() && l1.getFrequence() == l2.getFrequence();
  }
};

#endif
