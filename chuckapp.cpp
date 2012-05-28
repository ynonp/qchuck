#include "chuckapp.h"

ChuckApp::ChuckApp(QObject *parent) :
    QObject(parent)
{
}

void ChuckApp::showJoke(const QByteArray &jokeData)
{
    Joke j( jokeData );
    qDebug() << j.text();
    qDebug() << j.categories();
    exit(0);
}

void ChuckApp::start(QStringList args)
{
    QObject::connect(&m_api, SIGNAL(jokeReady(QByteArray)), this, SLOT(showJoke(QByteArray)));

    if ( args.size() == 2 )
    {
        m_api.randomJoke( args.at(0), args.at(1) );
    }
    else
    {
        m_api.randomChuckNorrisJoke();
    }
}
