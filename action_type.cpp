#include "action_type.h"


int ActionType::typeAction = -1;
void ActionType::setActionType(const int &type) { typeAction = type; }
int ActionType::getActionType(){return typeAction;}

