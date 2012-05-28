#ifndef JOKE_H
#define JOKE_H

#include <QtCore/QString>
#include <QtCore/QStringList>

class Joke
{
public:
    Joke( const QByteArray &jokeAsJSON );

    QString     text();
    int         id();
    QStringList categories();

    bool        valid();

private:
    int         m_id;
    QString     m_text;
    QStringList m_categories;
    bool        m_isValid;
};

#endif // JOKE_H
