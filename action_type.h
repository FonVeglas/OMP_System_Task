#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H
class ActionType{
private:
  ActionType(){}
  static int typeAction;
public:
  static void setActionType(const int &type);
  static const int getActionType();
  enum ActionTypes {
    AddFigure,
    ConnectFigures,
    MoveFigure,
    DeleteFigure,
  };
};


#endif // ACTION_TYPE_H
