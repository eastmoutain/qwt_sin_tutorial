#ifndef WIDGETSSS_H
#define WIDGETSSS_H

#include <QWidget>
#include <QTimer>
#include <QtGui>
#include <QVector>


#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>

class mywidget : public QWidget
{
    Q_OBJECT

public:
    mywidget(QWidget *parent = 0); //creation function
    ~mywidget();//destructor

    void addpoint(int point);//add a new point to the graphe

private slots:
    void update_curve();

private :
    void init_plot();

    QTimer *timer;
    QwtPlot *plot;
    QwtPlotCurve *curve;
    QVector<double> *data_x, *data_y;

};


#endif // WIDGETSSS_H
