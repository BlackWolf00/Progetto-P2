#include "xmlio.h"

bool XmlIO::leggi(const QString filename, Container<DeepPtr<Item> > &catalogo) {
    /*QFile file(filename);

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
                    catalogo.pushInOrder();
            }
        }
    }*/
}
