#ifndef CHUCKAPP_H
#define CHUCKAPP_H

#include <QObject>
#include <chucknorrisapi.h>
#include <joke.h>

class ChuckApp : public QObject
{
    Q_OBJECT
public:
    explicit ChuckApp(QObject *parent = 0);

    void start(QStringList args);

signals:
    
public slots:
    void showJoke(const QByteArray &jokeData);


private:
    ChuckNorrisAPI m_api;
};

#endif // CHUCKAPP_H
