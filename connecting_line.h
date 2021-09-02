#ifndef CONNECTING_LINE_H
#define CONNECTING_LINE_H

#include <QGraphicsLineItem>

class ConnectingLine : public QGraphicsLineItem {
public:
  ConnectingLine(QGraphicsItem*  firstItem, QGraphicsItem* secondItem);
  ~ConnectingLine();
  QGraphicsItem* getFirstItem();
  QGraphicsItem* getSecondItem();
  void setFirstItem(QGraphicsItem* firstItem);
  void setSecondItem(QGraphicsItem* secondItem);


private:
  QGraphicsItem*  firstItem_;
  QGraphicsItem* secondItem_;

};

#endif // CONNECTING_LINE_H
