#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "template/container.h"
#include "template/deepptr.h"

#include "gerarchia/item.h"
#include "gerarchia/libro.h"
#include "gerarchia/fumetto.h".h"
#include "gerarchia/rivista.h".h"

class XmlIO
{
public:
    static bool leggi(const QString, Container<DeepPtr<Item>>& catalogo);
    //static bool scrivi(const Container<DeepPtr<Item>>&, const Qstring);
};

#endif // XMLIO_H
