//
// Created by giacomo on 28/12/23.
//

#ifndef GSM2_SERIALISATION_H
#define GSM2_SERIALISATION_H

#include "base.h"

struct Serialisation {
    SerialisationType        type;
    SerialisationStyle       style;

    Serialisation(SerialisationType type = NONE_ST, SerialisationStyle style = NONE_SS);
    Serialisation() = default;
    Serialisation(const Serialisation&) = default;
    Serialisation(Serialisation&&) = default;
    Serialisation& operator=(const Serialisation&) = default;
    Serialisation& operator=(Serialisation&&) = default;
};

#endif //GSM2_SERIALISATION_H
