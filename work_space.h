#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include "action_type.h"
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
  const int getFigureType();
  void setFigureType(const int type);
  enum FigureTypes {
    TriangleType,
    RectangleType,
    EllipseType
  };

signals:
  void typeFigureChanged();

private:
  Figure *tempItem;
  int typeFigure;

  void createFigureStart(QGraphicsSceneMouseEvent *event);
  void createFigureEnd(QGraphicsSceneMouseEvent *event);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // WORK_SPACE_H
