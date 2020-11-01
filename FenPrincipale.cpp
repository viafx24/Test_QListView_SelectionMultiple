#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    QVBoxLayout *layout = new QVBoxLayout;

    QStringList listePays;
    listePays << "France" << "Espagne" << "Italie" << "Portugal" << "Suisse";
    modele = new QStringListModel(listePays);

    vue = new QListView ;
    vue->setModel(modele);

    bouton = new QPushButton("Afficher la sélection");

    layout->addWidget(vue);
    layout->addWidget(bouton);

    setLayout(layout);

    connect(bouton, SIGNAL(clicked()), this, SLOT(clicSelection()));
}

void FenPrincipale::clicSelection()
{
    QItemSelectionModel *selection = vue->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);
    QMessageBox::information(this, "Elément sélectionné", elementSelectionne.toString());
}
