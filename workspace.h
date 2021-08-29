#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "figures.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class WorkSpace : public QGraphicsScene {

  Q_OBJECT

public:
  explicit WorkSpace(QObject *parent = nullptr);
  ~WorkSpace();

  //int typeFigure() const;
  void setTypeFigure(const int type);

  enum FigureTypes {
    TriangleType,
    RectangleType,
    EllipseType
  };

signals:
  void typeFigureChanged();

private:
  Figure *tempItem;
  int typeFigure_;

  void printFigure(QGraphicsSceneMouseEvent *event);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // WORKSPACE_H
