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


//��������
    MAP  m_map;
    heroplan m_hero;

    diji m_diji[diji_suliang];



 //�л�����ʱ�����
    int diji_time;




/////���ɻ�

    //����ͼƬ
    void paintEvent(QPaintEvent *event);
    //�ɻ��������
    void mouseMoveEvent(QMouseEvent *event);

////�л�
    void enemyToScene();



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
