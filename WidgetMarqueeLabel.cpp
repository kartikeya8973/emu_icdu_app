#include "WidgetMarqueeLabel.h"
#include <QPainter>

WidgetMarqueeLabel::WidgetMarqueeLabel(QWidget *parent)
{
	px = 0;
	py = 15;
	speed = 2;	
    connect(&timer, SIGNAL(timeout()), this, SLOT(refreshLabel()));
    timer.start(40);
}

void WidgetMarqueeLabel::refreshLabel()
{
    update();
}

WidgetMarqueeLabel::~WidgetMarqueeLabel()
{}

void WidgetMarqueeLabel::show()
{	
	QLabel::show();
}

void WidgetMarqueeLabel::setAlignment(Qt::Alignment al)
{
	m_align = al;
	updateCoordinates();
	QLabel::setAlignment(al);
}

void WidgetMarqueeLabel::paintEvent(QPaintEvent *evt)
{
    QPainter p(this);
    px -= speed;
    if(px <= (-textLength))
        px = width();
    p.drawText(px, py + fontPointSize, text());
    p.translate(px,0);
}

void WidgetMarqueeLabel::resizeEvent(QResizeEvent *evt)
{
    updateCoordinates();
    QLabel::resizeEvent(evt);
}

void WidgetMarqueeLabel::updateCoordinates()
{
	switch(m_align)
	{
		case Qt::AlignTop:
			py = 10;
			break;
		case Qt::AlignBottom:
			py = height()-10;
			break;
		case Qt::AlignVCenter:
			py = height()/2;
			break;
	}
	fontPointSize = font().pointSize()/2;
    textLength = 50;// fontMetrics().  horizontalAdvance(text());
}

void WidgetMarqueeLabel::setSpeed(int s)
{
	speed = s;
}

int WidgetMarqueeLabel::getSpeed()
{
	return speed;
}
