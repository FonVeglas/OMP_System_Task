#include "workspace.h"
#include <iostream>

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) {}

WorkSpace::~WorkSpace() {}

void WorkSpace::setFigureType(const int type) { typeFigure = type; }
void WorkSpace::setActionType(const int type) { typeAction = type; }

//int WorkSpace::typeFigure() const { return typeFigure; }

void WorkSpace::createFigureStart(QGraphicsSceneMouseEvent *event){
  switch (typeFigure) {
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

void WorkSpace::createFigureEnd(QGraphicsSceneMouseEvent *event){
  tempItem->setEndPoint(event->scenePos());
  std::cout << "Start point x: " << tempItem->startPoint().x() << ' '
            << "start point y: " << tempItem->startPoint().y() << std::endl;

  std::cout << "End point x: " << tempItem->endPoint().x() << ' '
            << "end point y: " << tempItem->endPoint().y() << std::endl;

  this->update(QRectF(0, 0, this->width(), this->height()));
}

void WorkSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {

//  if(typeAction == ActionTypes::AddFigure)
//    event->accept();
  if(typeAction == ActionTypes::AddFigure){
    std::cout << "accepted press" << std::endl;
    createFigureStart(event);
  }
  if(typeAction == ActionTypes::MoveFigure)
    QGraphicsScene::mousePressEvent(event);

}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

//  if(typeAction == ActionTypes::AddFigure)
//    event->accept();
  if(typeAction == ActionTypes::AddFigure){
    std::cout << "accepted move" << std::endl;
    createFigureEnd(event);
  }
  if(typeAction == ActionTypes::MoveFigure)
    QGraphicsScene::mouseMoveEvent(event);


}


