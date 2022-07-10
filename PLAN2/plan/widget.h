#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "map.h"
#include "heroplan.h"
#include "diji.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void timeout();


//声明类名
    MAP  m_map;
    heroplan m_hero;

    diji m_diji[diji_suliang];



 //敌机计算时间变量
    int diji_time;




/////主飞机

    //绘制图片
    void paintEvent(QPaintEvent *event);
    //飞机坐标计算
    void mouseMoveEvent(QMouseEvent *event);

////敌机
    void enemyToScene();



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
