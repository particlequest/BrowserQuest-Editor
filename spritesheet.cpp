#include "spritesheet.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>


SpriteSheet::SpriteSheet()
{

}

/**
 * @brief Loads the Sprite with the given name from the project
 * Information regarding the Sprite and his animations will be taken from the
 * json file located in ./client/sprites and the image from ./client/img
 * @param root	Absolute root of sprite's json in ./client/sprites. It must match an image in
 * ./client/img/1 with the same name.
 */
SpriteSheet::SpriteSheet(QString root)
{
	// Load image from ./client/img/1
	// We need to modify the root in the string, beacuse we have a string with the root to the json file
	QImage spriteSheet;
	QString rootToSpriteSheet = root;
	rootToSpriteSheet.replace("sprites","img/1");
	rootToSpriteSheet.replace(".json",".png");
	if (QFile::exists(rootToSpriteSheet)) {
		spriteSheet.load(rootToSpriteSheet);
	}

	// Load sprite parameters from ./client/sprites
	QFile file(root);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream text(&file);
		QString line;

		//TODO: Fix problem reading files (read all file like a single line)
		// Information in fixed positions
		line = text.readLine(); // {
		line = text.readLine(); // "id": "name",
		_name = (line.split(":")[1]).replace("\"","");

		line = text.readLine(); // "width": w,
		_width = (line.split(":")[1]).toInt();

		line = text.readLine(); // "height": h,
		_height = (line.split(":")[1]).toInt();

		line = text.readLine(); // "animations": {
		line = text.readLine();
		while (!line.contains("offset_x")) {
			// Read name
			_names.push_back((line.split(":")[0]).replace("\"",""));

			// Read lenght
			line = text.readLine();
			_length.push_back((line.split(":")[1]).toInt());

			// Read Row
			line = text.readLine();// Not used, animations must be defined in order

			line = text.readLine();// {,
			line = text.readLine();
		}
		_offsetX = (line.split(":")[1]).toInt();
		line = text.readLine();
		_offsetY = (line.split(":")[1]).toInt();

		file.close();
		loadSpriteSheet(spriteSheet);

	} else {
		//TODO
	}
}

/**
 * @brief			Generates individual images from an sprite sheet.
 * @param image		Sprite sheet containing the animations.
 */
void SpriteSheet::loadSpriteSheet(QImage &image)
{
	QImage sprite;
	int x = 0;
	int y = 0;
	for (int i = 0; i < _names.size(); i++) {
		_sprites.push_back(QVector<QImage>(_length[i]));	// Insert row of the needed length
		y = y + (_height * i);
		for (int j = 0; j < _length[i]; j++) {
			sprite = image.copy(x,y,x + _width,y + _height);
			_sprites[i][j] = sprite;
		}
	}
}

/**
 * @brief				Image corresponding to an specific step from the animation.
 * @param animation		Name of the animation.
 * @param step			Step of the animation.
 * @return				Image on the sprite sheet in the coordinate [animation,step].
 */
QImage& SpriteSheet::spriteAt(QString animation, int step)
{
	int pos = _names.indexOf(animation);

	return _sprites[pos][step];
}

/**
 * @brief
 * @param name
 * @return
 */
Animation SpriteSheet::animation(QString name)
{
	int pos = _names.indexOf(name);

	return Animation(_sprites[pos]);
}

/**
 * @brief
 * @return
 */
QString SpriteSheet::name()
{
	return _name;
}
