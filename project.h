#ifndef PROJECT_H
#define PROJECT_H

#include "spritesheet.h"
#include <QPixmap>

class Project
{
public:
										Project(QString root);
	QImage								sprite(QString sprite, QString animation, int frame);

private:
	void								loadSprites();

private:
	QString								_root;
	QVector<SpriteSheet>				_spriteSheets;
};

#endif // PROJECT_H
