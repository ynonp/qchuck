#ifndef CHUCKNORRISAPI_H
#define CHUCKNORRISAPI_H

#include <QObject>
#include <QtNetwork/QtNetwork>

class ChuckNorrisAPI : public QObject
{
    Q_OBJECT
public:
    explicit ChuckNorrisAPI(QObject *parent = 0);
    
    void randomChuckNorrisJoke();
    void randomJoke( const QString &firstName, const QString &lastName);

private:
    void getRequest( const QString &url );

signals:
    void jokeReady( const QByteArray &jokeAsJSON );
    void networkError( QNetworkReply::NetworkError err );

public slots:
    void parseNetworkResponse( QNetworkReply *finished );

private:
    QNetworkAccessManager m_nam;
};

#endif // CHUCKNORRISAPI_H
