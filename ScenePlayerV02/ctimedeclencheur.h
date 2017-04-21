#ifndef CTIMEDECLENCHEUR_H
#define CTIMEDECLENCHEUR_H

#include "cdeclencheur.h"

class CTimeDeclencheur : public CDeclencheur
{
	private:
		QString m_time ;

	public:
		CTimeDeclencheur();
		void setTime(QString time) ;
		QString texte() ;
};

#endif // CTIMEDECLENCHEUR_H
