#include "action_type.h"


int ActionType::typeAction = -1;
void ActionType::setActionType(const int &type) { typeAction = type; }
const int ActionType::getActionType(){return typeAction;}

