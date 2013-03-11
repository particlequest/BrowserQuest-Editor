#ifndef ANIMATION_H
#define ANIMATION_H

#include <QVector>
#include <QImage>

class Animation
{
public:
							Animation(QVector<QImage>& sprites);

	QImage&					nextFrame();

private:
	QVector<QImage>&		_sprites;
	int						_frame;
};

#endif // ANIMATION_H
