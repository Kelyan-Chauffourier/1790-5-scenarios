#ifndef CMANUALDECLENCHEUR_H
#define CMANUALDECLENCHEUR_H

#include "cdeclencheur.h"

class CManualDeclencheur : public CDeclencheur
{
	public:
		CManualDeclencheur();
		QString texte() ;
};

#endif // CMANUALDECLENCHEUR_H
