#include "workspace.h"
#include <iostream>

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) {}

WorkSpace::~WorkSpace() {}

void WorkSpace::setTypeFigure(const int type) { typeFigure_ = type; }

//int WorkSpace::typeFigure() const { return typeFigure_; }

void WorkSpace::printFigure(QGraphicsSceneMouseEvent *event){
  switch (typeFigure_) {
  case TriangleType: {
    Figure *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case RectangleType: {
    Figure *item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case EllipseType: {
    Figure *item = new Ellipse(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  default: {
    Figure *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  }
  this->addItem(tempItem);
}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

  tempItem->setEndPoint(event->scenePos());
  std::cout << "Start point x: " << tempItem->startPoint().x() << ' '
            << "start point y: " << tempItem->startPoint().y() << std::endl;

  std::cout << "End point x: " << tempItem->endPoint().x() << ' '
            << "end point y: " << tempItem->endPoint().y() << std::endl;

  this->update(QRectF(0, 0, this->width(), this->height()));
}

void WorkSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  printFigure(event);
}
