#ifndef CMANUALDECLENCHEUR_H
#define CMANUALDECLENCHEUR_H

#include "cdeclencheur.h"

class CManualDeclencheur : public CDeclencheur
{
	public:
		virtual QString type() {return "manuel";}
		CManualDeclencheur();
		QString texte() ;
};

#endif // CMANUALDECLENCHEUR_H
