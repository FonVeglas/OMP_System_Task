#ifndef FIGURES_H
#define FIGURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "action_type.h"

//Родительынй класс всех фигур
class Figure : public QObject, public QGraphicsItem {

  Q_OBJECT
  Q_INTERFACES(QGraphicsItem)

public:
  explicit Figure(const QPointF &point, QObject *parent = nullptr);
  virtual ~Figure();
  virtual QPointF getStartPoint() const;
  virtual QPointF getEndPoint() const;
  void setStartPoint(const QPointF &point);
  void setEndPoint(const QPointF &point);
  unsigned int getId() const;
  void setId(const unsigned int &id);

  static unsigned int idCounter;

signals:
  void pointChanged();

private:
  unsigned int id_;
  QPointF startPoint_;
  QPointF endPoint_;
  QPointF m_shiftMouseCoords;

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
  explicit Triangle(const QPointF &point, QObject *parent = nullptr);
  ~Triangle();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

//Rectangle------------------------------------------------------------------------------
class Rectangle : public Figure
{
  Q_OBJECT

public:
  explicit Rectangle(const QPointF &point, QObject *parent = 0);
  ~Rectangle();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

//Ellipse------------------------------------------------------------------------------
class Ellipse : public Figure
{
  Q_OBJECT

public:
  explicit Ellipse(const QPointF &point, QObject *parent = 0);
  ~Ellipse();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FIGURES_H
