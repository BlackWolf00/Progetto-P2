#include "fumetto.h"

Fumetto::Fumetto(string t, string g, double p, int n, string a, string e)
    : Item(t, g, p), numeroUscita(n), autore(a), editore(e) {}

Fumetto::Fumetto(const Fumetto& f) : Item(f), numeroUscita(f.getNumeroUscita()), autore(f.getAutore()),
    editore(f.getEditore()) {}

Fumetto *Fumetto::clone() const {
    return new Fumetto(*this);
}

bool Fumetto::operator==(const Item& i) const {
    return dynamic_cast<const Fumetto*>(&i) && Item::operator==(i) && numeroUscita==(static_cast<const Fumetto*>(&i))->getNumeroUscita() &&
            autore==(static_cast<const Fumetto*>(&i))->getAutore() && editore==(static_cast<const Fumetto*>(&i))->getEditore();
}

bool Fumetto::operator!=(const Item& i) const {
    return dynamic_cast<const Fumetto*>(&i) && Item::operator!=(i) && numeroUscita!=(static_cast<const Fumetto*>(&i))->getNumeroUscita() &&
            autore!=(static_cast<const Fumetto*>(&i))->getAutore() && editore!=(static_cast<const Fumetto*>(&i))->getEditore();
}

int Fumetto::getNumeroUscita() const {
    return numeroUscita;
}

string Fumetto::getAutore() const {
    return autore;
}

string Fumetto::getEditore() const {
    return editore;
}

QString Fumetto::getType() const {
    return "f";
}

string Fumetto::print() const {
    return Item::print() + "\n" + "Autore: " + autore + " Numero Uscita: " + std::to_string(numeroUscita) + "\n" + "Editore: " + editore + "\n";
}

Fumetto *Fumetto::unserialize(QXmlStreamReader &rd) {
    QString t = "--Empty--", g = "--Empty--", a = "--Empty--",
            e = "--Empty--";
    double p = 0;
    unsigned int n = 0;

    if (rd.readNextStartElement() && rd.name() == "titolo")
        t = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "genere")
        g = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "prezzo")
        p = rd.readElementText().toDouble();

    if (rd.readNextStartElement() && rd.name() == "autore")
        a = rd.readElementText();

    if (rd.readNextStartElement() && rd.name() == "numeroUscita")
        n = rd.readElementText().toInt();

    if (rd.readNextStartElement() && rd.name() == "editore")
        e = rd.readElementText();

    rd.skipCurrentElement();
    return new Fumetto(t.toStdString(), g.toStdString(), p, n,
                     a.toStdString(), e.toStdString());
}

void Fumetto::serializzaDati(QXmlStreamWriter &wr) const {
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

    wr.writeStartElement("autore");
    wr.writeCharacters(QString::fromStdString(getAutore()));
    wr.writeEndElement();

    wr.writeStartElement("editore");
    wr.writeCharacters(QString::fromStdString(getEditore()));
    wr.writeEndElement();

    wr.writeEndElement();

    if(wr.hasError())
        throw "Errore in scrittura Fumetto";
}
