#include "AbstractLigne.h"


const Moyen& AbstractLigne::getMoyen() const
{
  return do_getMoyen();
}

Terminal* AbstractLigne::getOrigine() const
{
  return do_getOrigine();
}


Terminal* AbstractLigne::getDestination() const
{
  return do_getDestination();
}


int AbstractLigne::getFrequence() const
{
  return do_getFrequence();
}

void AbstractLigne::setFrequence(int _f)
{
  do_setFrequence(_f);
}
