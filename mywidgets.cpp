#include "mywidgets.h"
#include <QHBoxLayout>
#include <QTimer>
#include <QtMath>
#include <QDebug>


mywidget::mywidget(QWidget *parent)
    : QWidget(parent)
{
    //creation of tables of your data
    data_x = new QVector<double>;
    data_y = new QVector<double>;

    //initiation of the graphic
    init_plot();

    //creation of a layout to put the graphic inside
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setContentsMargins( 5, 5, 5, 5 ); //we set the margin of the layout
    layout->addWidget( plot ); //we add the plot

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_curve()));
    timer->setInterval(20);
    timer->start();

}

mywidget::~mywidget()
{
}


void mywidget::init_plot()
{
    plot = new QwtPlot(this); //creation of the plot
    plot->setMinimumSize(500,250); //we set the minimum size of the plot

    plot->setTitle("T = f(t)"); //title of the graphe

    // axes names
    plot->setAxisScale( QwtPlot::xBottom, 0, 2000 );
    plot->setAxisTitle(QwtPlot::xBottom, "t (s)" );
    plot->setAxisScale( QwtPlot::yLeft, -200.0, 200.0 );
    plot->setAxisTitle(QwtPlot::yLeft, "T (C)");

    plot->setLineWidth(1);
    plot->setFrameStyle(QFrame::Box | QFrame::Plain);

    // creation of the curve (you can add more curve to a graphe)
    curve = new QwtPlotCurve;
    curve->setPen(QPen(Qt::red));
    curve->attach(plot);
}

/*
void mywidget::receive()
{
    char data[255]; //creation of a char aray
   // int bytesRead = port->read(data, 255); //load the port data
    data[bytesRead] = '\0'; //end the char aray


    //we convert the char into a integer
    int i=0;
    if (bytesRead==1)
    {
        i = data[0];
    }else return; // if the data size is different from 1 => exit the function

    QTextStream out(stdout);
    out << data << " (" << bytesRead << " bytes) understood :" << i<< endl; //writing the data read in the console

    addpoint(i); //we add a point to the graphe

}
*/

void mywidget::addpoint(int point)
{
    if (data_x->size() == 2000) {
        data_y->pop_back();
        data_y->push_front(point);
    } else {
        data_x->push_front(data_x->size());
        data_y->push_front(point);
    }
    qDebug() << "data_x.size = " << data_x->size() << "data_y.size()" << data_y->size();

    curve->setSamples(*data_x, *data_y);// we set the data to the curve


    plot->replot(); // we redraw the graphe
}

void mywidget::update_curve()
{
    static double w = 0.0f;
    int v;
    static double pi = 3.1415926;

    v = 200*qSin(w);
    w += 0.01;
    addpoint(v);
}
