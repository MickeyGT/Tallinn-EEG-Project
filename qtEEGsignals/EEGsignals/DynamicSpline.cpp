#include "DynamicSpline.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

DynamicSpline::DynamicSpline(QGraphicsItem *parent, Qt::WindowFlags wFlags) :
	QChart(QChart::ChartTypeCartesian, parent, wFlags),
	m_series(0),
	m_axis(new QValueAxis),
	m_step(0),
	m_x(5),
	m_y(1),
	mSignalYValue(0)
{
	QObject::connect(&m_timer, &QTimer::timeout, this, &DynamicSpline::handleTimeout);
	m_timer.setInterval(600);

	m_series = new QSplineSeries(this);
	QPen pen(Qt::red);
	pen.setWidth(3);
	m_series->setPen(pen);
	m_series->append(m_x, m_y);

	addSeries(m_series);
	createDefaultAxes();
	setAxisX(m_axis, m_series);
	m_axis->setTickCount(5);
	axisX()->setRange(0, 10);
	axisY()->setRange(-5, 10);

	m_timer.start();
}

DynamicSpline::~DynamicSpline()
{

}

void DynamicSpline::handleTimeout()
{
	qreal x = plotArea().width() / m_axis->tickCount();
	qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
	m_x += y;
	m_y = mSignalYValue;
	m_series->append(m_x, m_y);
	scroll(x, 0);
	if (m_x == 100)
		m_timer.stop();
}

void DynamicSpline::setSignalYValue(const qreal &signalYValue)
{
	mSignalYValue = signalYValue;
}