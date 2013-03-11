#include "animation.h"

Animation::Animation(QVector<QImage>& sprites)
	:_sprites(sprites)
{
	_frame = 0;
}

/**
 * @brief	The animation advance to the next frame.
 * @return	Image corresponding to the actual frame of the animation.
 */
QImage& Animation::nextFrame()
{
	int old = _frame;
	_frame = (_frame + 1) % _sprites.size();
	return _sprites[old];
}
