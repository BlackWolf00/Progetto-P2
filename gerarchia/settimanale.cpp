#include "settimanale.h"

Settimanale::Settimanale(string t, string g, double p, int u, string e)
    : Rivista(t, g, p, u, e) {}

Settimanale *Settimanale::clone() const {
    return new Settimanale(*this);
}

bool Settimanale::operator==(const Item& i) const {
    return dynamic_cast<const Settimanale*>(&i) && Rivista::operator==(i);
}

bool Settimanale::operator!=(const Item& i) const {
    return dynamic_cast<const Settimanale*>(&i) && Rivista::operator!=(i);
}

QString Settimanale::getType() const {
    return "s";
}

string Settimanale::print() const {
    return Rivista::print();
}

Settimanale *Settimanale::unserialize(QXmlStreamReader &rd) {
    QString t = "--Empty--", g = "--Empty--", e = "--Empty--";
    double p = 0;
    int n = 0;

    if (rd.readNextStartElement() && rd.name() == "titolo")
        t = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "genere")
        g = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "prezzo")
        p = rd.readElementText().toDouble();

    if (rd.readNextStartElement() && rd.name() == "numeroUscita")
        n = rd.readElementText().toInt();

    if (rd.readNextStartElement() && rd.name() == "editore")
        e = rd.readElementText();

    rd.skipCurrentElement();
    return new Settimanale(t.toStdString(), g.toStdString(), p, n, e.toStdString());
}

void Settimanale::serializzaDati(QXmlStreamWriter &wr) const {
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

    wr.writeStartElement("numeroUscita");
    wr.writeCharacters(QString::number(getNumeroUscita()));
    wr.writeEndElement();

    wr.writeStartElement("editore");
    wr.writeCharacters(QString::fromStdString(getEditore()));
    wr.writeEndElement();

    wr.writeEndElement();

    if(wr.hasError())
        throw "Errore in scrittura Settimanale";
}
