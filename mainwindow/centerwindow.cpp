#include "centerwindow.h"
#include "functionpages/gradientshow.h"
#include "functionpages/webkitshow.h"
#include "functionpages/basequickwidget.h"
#include "functionpages/qmlviwer.h"
#include "QFramer/fcenterwindow.h"
#include "functionpages/mathplot.h"
CenterWindow* CenterWindow::instance = NULL;

CenterWindow::CenterWindow(QWidget *parent) :
    FCenterWindow(parent)
{
    initUI();
}

void CenterWindow::initUI()
{
    gradientShow = new GradientShow;
//    pdfTool = new PDFTool;
    MathPlot* p1 = new MathPlot;
//    webkitShow = new WebkitShow();
//    qmlViwer2 = new BaseQuickWidget;
//    qmlViwer3 = new QmlViwer;
//    qmlViwer4 = new BaseQuickWidget;
//    qmlViwer5 = new BaseQuickWidget;
//    qmlViwer2->setSource(QUrl(QString("qrc:/home/qml/home.qml")));
//    qmlViwer4->setSource(QUrl(QString("qrc:/home/qml/photowall.qml")));
//    qmlViwer5->setSource(QUrl(QString("qrc:/home/qml/about.qml")));

    addWidget(tr("Home"), gradientShow);
    addWidget(tr("MathPlot"), p1);
//    addWidget(tr("QtWebkit"), webkitShow);
//    addWidget(tr("QQuickWidget"), qmlViwer2);
//    addWidget(tr("QmlViewer"), qmlViwer3);
//    addWidget(tr("PhotoWall"), qmlViwer4);
//    addWidget(tr("About"), qmlViwer5);

    setAlignment(TopCenter);
}

CenterWindow* CenterWindow::getInstance()
{
    if(!instance)
    {
        instance = new CenterWindow();
    }
    return instance;
}


void CenterWindow::cloudAntimation(const int index)
{
    currentIndex = index;
    QLabel* circle = new QLabel(stackWidget);
    circle->setStyleSheet(QString("\
         QLabel{background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(1, 255, 255, 255), stop:0.511364 rgba(255, 255, 0, 255), stop:1 rgba(0, 137, 0, 238));}"\
                                  ));
    circle->show();
    QPropertyAnimation *animation = new QPropertyAnimation(circle, "size");
    connect(animation,SIGNAL(finished()), this, SLOT(switchscreen()));
    connect(animation,SIGNAL(finished()), circle, SLOT(deleteLater()));
    animation->setDuration(1000);
    animation->setStartValue(QSize(stackWidget->width(), 0));
    animation->setEndValue(stackWidget->size());
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start();
}