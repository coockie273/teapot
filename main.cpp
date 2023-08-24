#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QRandomGenerator>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QPainter>
#include <qw.h>
#include <QMainWindow>



class Bubble : public QLabel
{
public:
    Bubble(QWidget *parent) : QLabel(parent)
    {
        setFixedSize(10, 10);
        setStyleSheet("background-color: rgb(70,40,52); border-color : white; border-radius: 5px;");
        setGraphicsEffect(new QGraphicsOpacityEffect(this));  // Добавляем эффект прозрачности
    }

    void riseAndFade()
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(1000);
        animation->setStartValue(geometry());
        animation->setEndValue(geometry().translated(0, -550));  // Поднятие выше
        animation->setEasingCurve(QEasingCurve::OutQuad);

        QPropertyAnimation *fadeAnimation = new QPropertyAnimation(graphicsEffect(), "opacity");
        fadeAnimation->setDuration(700);  // Исчезновение за 2 секунды
        fadeAnimation->setStartValue(1.0);
        fadeAnimation->setEndValue(0.0);

        QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
        group->addAnimation(animation);
        group->addAnimation(fadeAnimation);
        group->start(QAbstractAnimation::DeleteWhenStopped);

        QObject::connect(group, &QParallelAnimationGroup::finished, [=]() {
            delete this;  // Удалить пузырёк после окончания анимации
        });
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QW widget;
    //main.setStyleSheet("background-image: url(:/img/chainik.jpg);"); // Подставьте правильный путь к вашей картинке
    QTimer timer;
    timer.start(300); // Интервал в миллисекундах
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        Bubble *bubble = new Bubble(&widget);
        bubble->move(QRandomGenerator::global()->bounded(450, 950), 600);
        bubble->show();
        bubble->riseAndFade();
    });

    widget.showMaximized();

    return app.exec();
}
