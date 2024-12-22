//
// Created by giacomo on 21/12/24.
//

#include <parser/schema/NestingState.h>

NestingState::NestingState(const Entity* e) : entity_stack{e} {}