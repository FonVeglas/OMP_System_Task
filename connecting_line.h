#ifndef CONNECTING_LINE_H
#define CONNECTING_LINE_H

#include <QGraphicsLineItem>
//Класс соединительной линии
class ConnectingLine : public QGraphicsLineItem {
public:
  ConnectingLine(QGraphicsItem*  firstItem, QGraphicsItem* secondItem);
  ~ConnectingLine();
  QGraphicsItem* getFirstItem() const;
  QGraphicsItem* getSecondItem() const;
  void setFirstItem(QGraphicsItem* firstItem);
  void setSecondItem(QGraphicsItem* secondItem);
  unsigned int getFirstItemId() const;
  unsigned int getSecondItemId() const;
  void setFirstItemId(const unsigned int &id);
  void setSecondItemId(const unsigned int &id);


private:
  //id фигур которые связывает эта линия
  unsigned int firstItemId;
  unsigned int secondItemId;
  QGraphicsItem*  firstItem_;
  QGraphicsItem* secondItem_;

};

#endif // CONNECTING_LINE_H
