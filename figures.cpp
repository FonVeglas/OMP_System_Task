#include "figures.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent)
    : QObject(parent), QGraphicsItem() {

  this->setStartPoint(mapFromScene(point));
  this->setEndPoint(mapFromScene(point));

  connect(this, &Figure::pointChanged, this, &Figure::updateFigure);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{

  return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                qAbs(endPoint().x() - startPoint().x()) + 10,
                qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateFigure()
{
  this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
               (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
               qAbs(endPoint().x() - startPoint().x()) + 10,
               qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF &point) {
  startPoint_ = mapFromScene(point);
  emit pointChanged();
}

void Figure::setEndPoint(const QPointF &point) {
  endPoint_ = mapFromScene(point);
  emit pointChanged();
}

QPointF Figure::startPoint() const {
  return startPoint_;
}

QPointF Figure::endPoint() const {
  return endPoint_;
}

//Triangle------------------------------------------------------------------------------
Triangle::Triangle(QPointF point, QObject *parent)
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

  polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                                abs((endPoint().x() - startPoint().x())/2), startPoint().y())
          << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                     endPoint().y())
          << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                     endPoint().y());

  painter->drawPolygon(polygon);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

//Rectangle------------------------------------------------------------------------------
Rectangle::Rectangle(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Rectangle::~Rectangle()
{

}


void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::black, 2));

  QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
              endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
              qAbs(endPoint().x() - startPoint().x()),
              qAbs(endPoint().y() - startPoint().y()));

  painter->drawRect(rect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

//Ellipse------------------------------------------------------------------------------
Ellipse::Ellipse(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Ellipse::~Ellipse()
{

}


void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::black, 2));


  QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
              endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
              qAbs(endPoint().x() - startPoint().x()),
              qAbs(endPoint().y() - startPoint().y()));

  painter->drawEllipse(rect);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
