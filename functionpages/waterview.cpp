#include "waterview.h"
#include <QLinearGradient>
#include <QGraphicsEllipseItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>

FGraphicsEllipseItem::FGraphicsEllipseItem(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent)
{

}

FGraphicsEllipseItem::FGraphicsEllipseItem(const QRectF &rect, QGraphicsItem *parent):
    QGraphicsEllipseItem(rect, parent)
{

}

FGraphicsEllipseItem::FGraphicsEllipseItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsEllipseItem(x, y, w, h, parent)
{

}


void FGraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    QStyleOptionGraphicsItem myoption = (*option);
//    myoption.state &= !QStyle::State_Selected;
//    QGraphicsEllipseItem::paint(painter, &myoption, widget);
}

FGraphicsPixmapItem::FGraphicsPixmapItem(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{

}

FGraphicsPixmapItem::FGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent):
    QGraphicsPixmapItem(pixmap, parent)
{

}

void FGraphicsPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    QStyleOptionGraphicsItem myoption = (*option);
    myoption.state &= !QStyle::State_Selected;
    QGraphicsPixmapItem::paint(painter, &myoption, widget);
}


WaterView::WaterView(QWidget *parent) :
    QGraphicsView(parent)
{
    initData();
    initUI();
    initConnect();

    setDragMode(QGraphicsView::RubberBandDrag);
}

void WaterView::initData()
{

}

void WaterView::initUI()
{
    QGraphicsScene* scene = new QGraphicsScene;
//    setSceneRect(-100, -100, 700, 700);
    setScene(scene);
    for(int i=0; i<10; i++){
        FGraphicsEllipseItem *item = new FGraphicsEllipseItem(i * 20 + 20, 0, 40, 40);
        QRadialGradient bgradient(0, 0 , 20, 0, 0);
        bgradient.setColorAt(0,QColor(63, 120, 137));
        bgradient.setColorAt(0.5,QColor(61, 235, 188));
        bgradient.setColorAt(1.0,QColor(255, 255, 255));
        item->setBrush(QBrush(bgradient));
        item->setPen(QPen(Qt::NoPen));
        item->setFlags(FGraphicsEllipseItem::ItemIsMovable| FGraphicsEllipseItem::ItemIsSelectable);
        scene->addItem(item);
    }
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            FGraphicsPixmapItem *item = new FGraphicsPixmapItem(QPixmap(":/images/skin/images/QFramer.png"));
            item->setFlags(FGraphicsPixmapItem::ItemIsMovable| FGraphicsPixmapItem::ItemIsSelectable);
            item->setPos(j * 120, i * 120 + 40);
            scene->addItem(item);
        }
    }
}

void WaterView::initConnect()
{

}

void WaterView::resizeEvent(QResizeEvent *event)
{
    QLinearGradient bgradient(0, 100, 100, 0);
    bgradient.setSpread(QGradient::PadSpread);
    bgradient.setColorAt(0, QColor(63, 120, 137));
    bgradient.setColorAt(0.25, QColor(61, 235, 188));
    bgradient.setColorAt(0.5, QColor(63, 120, 137));
    bgradient.setColorAt(0.75, QColor(61, 235, 188));
    bgradient.setColorAt(1, QColor(63, 120, 137));
    setBackgroundBrush(QBrush(bgradient));
    QGraphicsView::resizeEvent(event);
}
