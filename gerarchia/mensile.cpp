#include "mensile.h"

Mensile::Mensile(string t, string g, double p, double pn, int u, string e, bool s, bool m)
    : Rivista(t, g, p, pn, u, e, s, m) {}

Mensile::Mensile(const Mensile& m) : Rivista(m) {}

Mensile *Mensile::clone() const {
    return new Mensile(*this);
}

bool Mensile::operator==(const Item& i) const {
    return dynamic_cast<const Mensile*>(&i) && Rivista::operator==(i);
}

bool Mensile::operator!=(const Item& i) const {
    return dynamic_cast<const Mensile*>(&i) && Rivista::operator!=(i);
}

QString Mensile::getType() const {
    return "m";
}

string Mensile::print() const {
    return Rivista::print();
}

Mensile *Mensile::unserialize(QXmlStreamReader &rd) {
    QString t = "--Empty--", g = "--Empty--", e = "--Empty--";
    double p = 0, pn = 0;
    int n = 0;
    bool s = false, m = false;

    if (rd.readNextStartElement() && rd.name() == "titolo")
        t = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "genere")
        g = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "prezzo")
        p = rd.readElementText().toDouble();

    if (rd.readNextStartElement() && rd.name() == "prezzoNoleggio")
        pn = rd.readElementText().toDouble();

    if (rd.readNextStartElement() && rd.name() == "numeroUscita")
        n = rd.readElementText().toInt();

    if (rd.readNextStartElement() && rd.name() == "editore")
        e = rd.readElementText();

    if(rd.readNextStartElement() && rd.name() == "settimanale")
        s = rd.readElementText() == "1" ? true:false;

    if(rd.readNextStartElement() && rd.name() == "mensile")
        m = rd.readElementText() == "1" ? true:false;

    rd.skipCurrentElement();
    return new Mensile(t.toStdString(), g.toStdString(), p, pn, n, e.toStdString(), s, m);
}

void Mensile::serializzaDati(QXmlStreamWriter &wr) const {
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

    wr.writeStartElement("prezzoNoleggio");
    wr.writeCharacters(QString::number(getPrezzoNoleggio()));
    wr.writeEndElement();

    wr.writeStartElement("numeroUscita");
    wr.writeCharacters(QString::number(getNumeroUscita()));
    wr.writeEndElement();

    wr.writeStartElement("editore");
    wr.writeCharacters(QString::fromStdString(getEditore()));
    wr.writeEndElement();

    wr.writeStartElement("settimanale");
    wr.writeCharacters(QString::fromStdString(getSettimanale() ? "1" : "0"));
    wr.writeEndElement();

    wr.writeStartElement("mensile");
    wr.writeCharacters(QString::fromStdString(getMensile() ? "1" : "0"));
    wr.writeEndElement();

    wr.writeEndElement();

    if(wr.hasError())
        throw "Errore in scrittura Mensile";
}

