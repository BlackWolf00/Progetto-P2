#include "xmlio.h"

bool XmlIO::leggi(const QString filename, Container<DeepPtr<Item> > &catalogo) {
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QXmlStreamReader reader(&file);
    QString type;
    if(reader.readNextStartElement() && reader.name() == "catalogo") {
        while(reader.readNextStartElement()) {
            type = reader.attributes().value("type").toString();
            try {
                if(type == "l")
                    catalogo.pushInOrder(Libro::unserialize(reader));
                if(type == "f")
                    catalogo.pushInOrder(Fumetto::unserialize(reader));
                if(type == "s")
                    catalogo.pushInOrder(Settimanale::unserialize(reader));
                if(type == "m")
                    catalogo.pushInOrder(Mensile::unserialize(reader));
            }
            catch (string s){
                return false;
            }
        }
    }

    else
        return false;

    file.close();
    return true;
}

bool XmlIO::scrivi(const Container<DeepPtr<Item> > & catalogo, const QString filename) {
    QSaveFile file(filename);

    if(!file.open(QIODevice::WriteOnly))
        return false;

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("Catalogo Prodotti");

    writer.writeStartElement("catalogo");

    try {
        auto cit = catalogo.constBegin();
        for (int k = 0; (uint)k<catalogo.size(); k++) {
            (*cit)->serializzaDati(writer);
            ++cit;
        }
    }
    catch (string s) {
        return false;
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    file.commit();
    return true;
}
