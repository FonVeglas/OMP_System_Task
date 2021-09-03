#include "figures.h"
#include <iostream>

Figure::Figure(const QPointF &point, QObject *parent)
    : QObject(parent), QGraphicsItem() {

  this->setStartPoint(mapFromScene(point));
  this->setEndPoint(mapFromScene(point));

  connect(this, &Figure::pointChanged, this, &Figure::updateFigure);
}

Figure::~Figure() {}

QRectF Figure::boundingRect() const {

  return QRectF((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
                (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
                qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
                qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}

void Figure::updateFigure() {
  this->update((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
               (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
               qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
               qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}


void Figure::setStartPoint(const QPointF &point) {
  startPoint_ = mapFromScene(point);
  emit pointChanged();
}

void Figure::setEndPoint(const QPointF &point) {
  endPoint_ = mapFromScene(point);
  emit pointChanged();
}

QPointF Figure::getStartPoint() const { return startPoint_; }

QPointF Figure::getEndPoint() const { return endPoint_; }

//Mouse events------------------------------------------------------------------------------
void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event){
  switch (ActionType::getActionType()) {
  case ActionType::MoveFigure: {
    m_shiftMouseCoords = this->pos() - mapToScene(event->pos());
    std::cout << "Figure press" << std::endl;
    break;
  }
  }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
  switch (ActionType::getActionType()) {
  case ActionType::MoveFigure: {
    this->setPos(event->scenePos() + m_shiftMouseCoords);
    std::cout << "Figure move" << std::endl;
    break;
  }
  }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::MoveFigure: {
    Q_UNUSED(event);
    std::cout << "Figure release" << std::endl;
    break;
  }
  }
}

//Triangle------------------------------------------------------------------------------
Triangle::Triangle(const QPointF &point, QObject *parent)
   : Figure(point,parent)
{
  Q_UNUSED(point)
}

Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::black, 2));

  QPolygonF polygon;

  polygon << QPointF(getStartPoint().x() + (getEndPoint().x() > getStartPoint().x() ? + 1 : - 1)*
                                abs((getEndPoint().x() - getStartPoint().x())/2), getStartPoint().y())
          << QPointF((getEndPoint().x() > getStartPoint().x()) ? getEndPoint().x() : getStartPoint().x(),
                     getEndPoint().y())
          << QPointF((getEndPoint().x() > getStartPoint().x()) ? getStartPoint().x() : getEndPoint().x(),
                     getEndPoint().y());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

//Rectangle------------------------------------------------------------------------------
Rectangle::Rectangle(const QPointF &point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Rectangle::~Rectangle()
{

}


void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
              getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
              qAbs(getEndPoint().x() - getStartPoint().x()),
              qAbs(getEndPoint().y() - getStartPoint().y()));

  painter->drawRect(rect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

//Ellipse------------------------------------------------------------------------------
Ellipse::Ellipse(const QPointF &point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Ellipse::~Ellipse()
{

}


void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::black, 2));


  QRectF rect(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
              getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
              qAbs(getEndPoint().x() - getStartPoint().x()),
              qAbs(getEndPoint().y() - getStartPoint().y()));

  painter->drawEllipse(rect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
