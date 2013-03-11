#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QImage>
#include <QVector>
#include <QString>
#include "animation.h"

class SpriteSheet
{
public:
								SpriteSheet();
								SpriteSheet(QString root);
	QImage&						spriteAt(QString animation, int step);
	QVector<QString>&			animationsNames();
	Animation					animation(QString name);
	QString						name();

private:
	void						loadSpriteSheet(QImage& image);

private:
	QVector<QVector<QImage> >	_sprites;
	QVector<int>				_length;	//Lenght of each animation
	QVector<QString>    		_names;		//Names of the animations
	QString						_name;
	int							_width;
	int							_height;
	int							_offsetX;
	int							_offsetY;
};

#endif // SPRITESHEET_H
