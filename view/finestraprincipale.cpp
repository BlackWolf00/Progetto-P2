#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QWidget *parent)
    : QMainWindow(parent), dettagli(new QLabel("--Dettagli--", this)),
      totnoleggio(new QLabel("0€", this)), totacquisto(new QLabel("0€", this)),


