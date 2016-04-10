#include <sound.h>
#include <roadrace.h>
#include <QString>
#include <QFile>
#include <QObject>
#include <QtMultimedia/QSoundEffect>
#include <QMessageBox>
using namespace std;

Sound *Sound::instance_ = NULL;

Sound& Sound::instance() {
    if ( instance_ == NULL ) {
        instance_ = new Sound;
    }
    return *instance_;
}

void Sound::playSound(QString s, float volume)
{
    effect = new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile(s));
    effect->setVolume(volume);
    effect->play();
}

void Sound::playSoundTrack()
{
    effect = new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile(":/music"));
    effect->setVolume(.6f);
    effect->setLoopCount(QSoundEffect::Infinite);
    effect->play();
}
