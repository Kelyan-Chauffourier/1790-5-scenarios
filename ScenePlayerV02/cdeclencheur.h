#ifndef CDECLENCHEUR_H
#define CDECLENCHEUR_H

#include <QString>

class CDeclencheur
{
	private:
		QString m_description ;

	public:
		CDeclencheur();
		void setDescription(QString description) ;
		virtual QString texte() = 0 ;
		QString description() ;
};

#endif // CDECLENCHEUR_H
