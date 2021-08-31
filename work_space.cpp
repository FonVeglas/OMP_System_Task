#include "work_space.h"
#include <iostream>

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) {}

WorkSpace::~WorkSpace() {
}

void WorkSpace::setFigureType(const int type) { typeFigure = type; }
const int WorkSpace::getFigureType(){return typeFigure;}

//int WorkSpace::typeFigure() const { return typeFigure; }
void WorkSpace::createFigureStart(QGraphicsSceneMouseEvent *event){
  switch (WorkSpace::typeFigure) {
  case WorkSpace::FigureTypes::TriangleType: {
    Figure *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case WorkSpace::FigureTypes::RectangleType: {
    Figure *item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case WorkSpace::FigureTypes::EllipseType: {
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
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    std::cout << "Graphics scene press" << std::endl;
    createFigureStart(event);
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mousePressEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {
    lineBetween = new QGraphicsLineItem;
    pressedItem = itemAt(event->scenePos(), QTransform());
    break;
  }
  case ActionType::DeleteFigure: {
    std::cout << "Graphics scene press" << std::endl;
    auto itemsToRemove = items(event->scenePos());
    if (!itemsToRemove.empty()) {
      QGraphicsItem * itemToRemove = itemsToRemove.at(0);
      removeItem(itemToRemove);
      break;
    }
  }
  }
}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    std::cout << "Graphics scene move" << std::endl;
    createFigureEnd(event);
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mouseMoveEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {

    break;
  }
  case ActionType::DeleteFigure: {

    break;
  }
  }
}

void WorkSpace::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    std::cout << "Graphics scene release" << std::endl;
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mouseReleaseEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {
    releasedItem = itemAt(event->scenePos(), QTransform());
    QPointF p1 = pressedItem->sceneBoundingRect().center();
    QPointF p2 = releasedItem->sceneBoundingRect().center();
    QLineF line(p1, p2);
    lineBetween->setLine(line);
    this->addItem(lineBetween);
    break;
  }
  case ActionType::DeleteFigure: {

    break;
  }
  }
}
