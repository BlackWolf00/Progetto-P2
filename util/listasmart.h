#ifndef LISTASMART_H
#define LISTASMART_H

#include <QListWidget>

class ListaSmart : public QListWidget
{
    Q_OBJECT
public:
    ListaSmart(QWidget * =nullptr);

    unsigned int getIndice() const;

    bool isSelezionato() const;

    void deselezionaIndice() const;
};

#endif // LISTASMART_H
