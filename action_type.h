#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H
//Класс, который определяет тип выполняемого действия в зависимости от нажатой кнопки
class ActionType{
private:
  ActionType(){}
  static int typeAction;
public:
  static void setActionType(const int &type);
  static int getActionType();
  enum ActionTypes {
    AddFigure,
    ConnectFigures,
    MoveFigure,
    DeleteFigure,
  };
};


#endif // ACTION_TYPE_H
