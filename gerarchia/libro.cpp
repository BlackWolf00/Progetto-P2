#include "libro.h"

Libro::Libro(string t, string g, double p, string a, string e, string c)
    : Item(t, g, p), autore(a), annoEdizione(e), editore(c) {}

Libro *Libro::clone() const {
    return new Libro(*this);
}

bool Libro::operator==(const Item& i) const {
    return dynamic_cast<const Libro*>(&i) && Item::operator==(i) && autore==(static_cast<const Libro*>(&i))->getAutore() &&
            annoEdizione==(static_cast<const Libro*>(&i))->getAnnoEdizione() && editore==(static_cast<const Libro*>(&i))->getEditore();
}

bool Libro::operator!=(const Item& i) const {
    return dynamic_cast<const Libro*>(&i) && Item::operator!=(i) && autore!=(static_cast<const Libro*>(&i))->getAutore() &&
            annoEdizione!=(static_cast<const Libro*>(&i))->getAnnoEdizione() && editore!=(static_cast<const Libro*>(&i))->getEditore();
}

string Libro::getAutore() const {
    return autore;
}

string Libro::getAnnoEdizione() const {
    return annoEdizione;
}

QString Libro::getType() const {
    return "l";
}

string Libro::print() const {
    return Item::print() + "\n" + "Autore: " + autore + " Anno Edizione: " + annoEdizione + "\n" + "Editore: " + editore + "\n";
}

Libro *Libro::unserialize(QXmlStreamReader &rd) {
    QString t = "--Empty--", g = "--Empty--", a = "--Empty--",
            e = "--Empty--", c = "--Empty--";
    double p = 0;

    if (rd.readNextStartElement() && rd.name() == "titolo")
        t = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "genere")
        g = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "prezzo")
        p = rd.readElementText().toDouble();

    if (rd.readNextStartElement() && rd.name() == "autore")
        a = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "annoEdizione")
        e = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "editore")
        c = rd.readElementText();

    rd.skipCurrentElement();
    return new Libro(t.toStdString(), g.toStdString(), p, a.toStdString(),
                     e.toStdString(), c.toStdString());
}

void Libro::serializzaDati(QXmlStreamWriter &wr) const {
    wr.writeStartElement("item");
    wr.writeAttribute("type", getType());

    wr.writeStartElement("titolo");
    wr.writeCharacters(QString::fromStdString(getTitolo()));
    wr.writeEndElement();

    wr.writeStartElement("genere");
    wr.writeCharacters(QString::fromStdString(getGenere()));
    wr.writeEndElement();

    wr.writeStartElement("prezzo");
    wr.writeCharacters(QString::number(getPrezzo()));
    wr.writeEndElement();

    wr.writeStartElement("autore");
    wr.writeCharacters(QString::fromStdString(getAutore()));
    wr.writeEndElement();

    wr.writeStartElement("annoEdizione");
    wr.writeCharacters(QString::fromStdString(getAnnoEdizione()));
    wr.writeEndElement();

    wr.writeStartElement("editore");
    wr.writeCharacters(QString::fromStdString(getEditore()));
    wr.writeEndElement();

    wr.writeEndElement();

    if(wr.hasError())
        throw "Errore in scrittura Libro";
}
