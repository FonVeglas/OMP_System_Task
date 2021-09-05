#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include "action_type.h"
#include "figures.h"
#include "connecting_line.h"
#include <QGraphicsItem>
#include <QLineF>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

class WorkSpace : public QGraphicsScene {

  Q_OBJECT

public:
  explicit WorkSpace(QObject *parent = nullptr);
  ~WorkSpace();

  void connectFigures();
  void addConnectingLine(ConnectingLine *line);
  void clearConnectingLines();
  QList<ConnectingLine *> getConnectingLines() const;
  void setFigureType(const int &type);
  enum FigureTypes {
    TriangleType,
    RectangleType,
    EllipseType
  };

signals:
  void movedFigure();
  void deletedFigure(QGraphicsItem* item);

public slots:
  void redrawLines();
  void deleteLines(QGraphicsItem* item);

private:
  Figure *tempItem;
  int typeFigure;
  QGraphicsItem *pressedItem;
  QGraphicsItem *releasedItem;
  QList<ConnectingLine *> connectingLines;

  void createFigureStart(QGraphicsSceneMouseEvent *event);
  void createFigureEnd(QGraphicsSceneMouseEvent *event);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // WORK_SPACE_H
