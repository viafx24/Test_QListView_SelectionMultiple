#include "FenPrincipale.h"

FenPrincipale::FenPrincipale()
{
    // Gestion de layout pour empiler des widgets verticalement
    QVBoxLayout *layout = new QVBoxLayout;

    // modèle contenant l'arbre de tout les disques dur (arborescence)
    QDirModel *modele = new QDirModel;

    // vue (schema Modèle/vue) pour visualiser l'arboresence du modèle.
    QTreeView *vue = new QTreeView;

    // ne pas oublier de relier la vue au modèle.
    vue->setModel(modele);

    // possibilité de choisir le disque dur à visualiser (ici C:)
    vue->setRootIndex(modele->index("C:"));


    // ajout du widget à la layout et ne pas oublier le set
    layout->addWidget(vue);
    setLayout(layout);
}
