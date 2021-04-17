#include "listasmart.h"

ListaSmart::ListaSmart(QWidget *parent) : QListWidget(parent) {}

unsigned int ListaSmart::getIndice() const {
    return (uint)this->selectedIndexes()[0].row();
}

bool ListaSmart::isSelezionato() const {
    return !this->selectedIndexes().empty();
}

void ListaSmart::deselezionaIndice() const {
    this->selectedIndexes().clear();
}
