#ifndef SOUND_H
#define SOUND_H

#include <QString>
#include <QtMultimedia/QSoundEffect>

using namespace std;
class Sound {
   static Sound *instance_;
   QSoundEffect* effect;

public:
   void playSound(QString s, float volume);
   void playSoundTrack();
   static Sound& instance();
};

#endif // SOUND_H

