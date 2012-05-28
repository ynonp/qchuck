#include "joke.h"
#include <QtCore/QtCore>

#include <qjson/include/QJson/Parser>

QStringList variantListToStringList(QVariantList vlist)
{
    QStringList result;

    foreach ( QVariant v, vlist )
    {
        result << v.toString();
    }
    return result;
}


Joke::Joke( const QByteArray &jokeAsJSON )
{
    QJson::Parser parser;
    bool ok;
    QVariantMap result = parser.parse (jokeAsJSON, &ok).toMap();

    if ( ok )
    {
        QVariantMap jokeData = result["value"].toMap();
        m_id                 = jokeData["id"].toInt();
        m_text               = jokeData["joke"].toString();
        m_categories         = variantListToStringList(jokeData["categories"].toList());
        m_isValid            = true;
    }
}


QString Joke::text()
{
    return m_text;
}

int Joke::id()
{
    return m_id;
}

QStringList Joke::categories()
{
    return m_categories;
}

bool Joke::valid()
{
    return m_isValid;
}

