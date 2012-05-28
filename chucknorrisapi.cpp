#include "chucknorrisapi.h"

const QString kBaseUrl = "http://api.icndb.com/";

ChuckNorrisAPI::ChuckNorrisAPI(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
}

void ChuckNorrisAPI::randomChuckNorrisJoke()
{
    getRequest(kBaseUrl + "/jokes/random");
}

void ChuckNorrisAPI::randomJoke( const QString &firstName, const QString &lastName)
{
    getRequest( kBaseUrl + QString("/jokes/random?firstName=%1&lastName=%2").arg(firstName, lastName) );
}

void ChuckNorrisAPI::getRequest( const QString &urlString )
{
    QUrl url ( urlString );
    QNetworkRequest req ( url );
    m_nam.get( req );
}

void ChuckNorrisAPI::parseNetworkResponse( QNetworkReply *finished )
{
    if ( finished->error() != QNetworkReply::NoError )
    {
        // A communication error has occurred
        emit networkError( finished->error() );
        return;
    }

    // QNetworkReply is a QIODevice. So we read from it just like it was a file
    QByteArray data = finished->readAll();
    emit jokeReady( data );
}

