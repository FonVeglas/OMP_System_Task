#ifndef FIGURES_H
#define FIGURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "action_type.h"

class Figure : public QObject, public QGraphicsItem {

  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)

public:
  explicit Figure(QPointF point, QObject *parent = nullptr);
  ~Figure();
  QPointF startPoint() const;
  QPointF endPoint() const;
  void setStartPoint(const QPointF &point);
  void setEndPoint(const QPointF &point);

signals:
  void pointChanged();

private:
  QPointF startPoint_;
  QPointF endPoint_;
  QPointF shiftMouseCoords;

  QRectF boundingRect() const;

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
  void updateFigure();
};

//Triangle------------------------------------------------------------------------------
class Triangle : public Figure
{
  Q_OBJECT

public:
  explicit Triangle(QPointF point, QObject *parent = nullptr);
  ~Triangle();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

//Rectangle------------------------------------------------------------------------------
class Rectangle : public Figure
{
  Q_OBJECT

public:
  explicit Rectangle(QPointF point, QObject *parent = 0);
  ~Rectangle();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

//Ellipse------------------------------------------------------------------------------
class Ellipse : public Figure
{
  Q_OBJECT

public:
  explicit Ellipse(QPointF point, QObject *parent = 0);
  ~Ellipse();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FIGURES_H
