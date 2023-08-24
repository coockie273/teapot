#ifndef QW_H
#define QW_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class QW : public QWidget
{
    Q_OBJECT
public:
    QW();

    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);

         painter.drawPixmap(rect(), QPixmap(":/img/chainik.jpg")); // Загрузите вашу картинку и укажите путь
    }
};

#endif // QW_H
