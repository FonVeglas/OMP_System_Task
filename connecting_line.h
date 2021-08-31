#ifndef CONNECTING_LINE_H
#define CONNECTING_LINE_H

#include <QGraphicsLineItem>

class ConnectingLine : public QGraphicsLineItem {
public:
  ConnectingLine(QGraphicsItem*  firstItem, QGraphicsItem* secondItem);
  ~ConnectingLine();
  QGraphicsItem* getFirstItem();
  QGraphicsItem* getSecondItem();


private:
  QGraphicsItem*  firstItem_;
  QGraphicsItem* secondItem_;

};

#endif // CONNECTING_LINE_H
