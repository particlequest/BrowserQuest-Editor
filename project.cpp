#include "project.h"
#include <QStringList>
#include <QDir>

Project::Project(QString root)
	:_root(root)
{
	loadSprites();
}

QImage Project::sprite(QString sprite, QString animation, int frame)
{
	for (int i = 0; i < _spriteSheets.size(); i++) {
		if (_spriteSheets[i].name() == sprite) {
			return _spriteSheets[i].spriteAt(animation,frame);
		}
	}
	return QImage();
}

void Project::loadSprites()
{
	QStringList files;
	QStringList filter;
	QDir directory(_root + "/client/sprites/");

	filter.push_back("*.json");
	files = directory.entryList(filter);

	for (int i = 0; i < files.size(); i++) {
		_spriteSheets.push_back(SpriteSheet(directory.path() + "/" + files[i]));
	}

}
