#ifndef FINESTRADIMODIFICA_H
#define FINESTRADIMODIFICA_H

#include "view/finestradiinserimento.h"

class FinestraDiModifica : public FinestraDiInserimento
{
    Q_OBJECT
private:
    unsigned int i;
public:
    explicit FinestraDiModifica(QWidget *parent = nullptr);

    void caricaDataPerModifica(const QStringList, const unsigned int);

public slots:
    void conferma() override;

signals:
    void rimpiazzaOggetto(const unsigned int, const QStringList);
};

#endif // FINESTRADIMODIFICA_H
