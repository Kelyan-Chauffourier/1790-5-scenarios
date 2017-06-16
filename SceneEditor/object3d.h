/*  ---------------------------------------------------------------------------
 *  filename    :   object3d.h
 *  description :   INTERFACE de la classe Object3D
 *
 *	project     :	FlightSim
 *  start date  :   février 2016
 *  ---------------------------------------------------------------------------
 *  Copyright 2016 by Alain Menu   <alain.menu@ac-creteil.fr>
 *
 *  This file is part of "LLF Flight Simulator Project"
 *
 *  This program is free software ;  you can  redistribute it and/or  modify it
 *  under the terms of the  GNU General Public License as published by the Free
 *  Software Foundation ; either version 3 of the License, or  (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 *  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 *  more details.
 *
 *	You should have  received  a copy of the  GNU General Public License  along
 *	with this program. If not, see <http://www.gnu.org/licenses/>.
 *  ---------------------------------------------------------------------------
 */

// Objet 3D à destination d'X-Plane
// commandes OBJN pour le chargement et OBJL pour le positionnement spatial


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <QString>
#include <QVector3D>

// OBJN struct : size = 5 + 504 = 509 bytes

typedef struct {
	int		index ;				// 4
	char	path[500] ;			// 500
} XPlaneObjLoad ;

// OBJL struct : size = 5 + 56 = 61 bytes

typedef struct {				// 8-bytes alignment (because of double...)
	int		index ;				//    4 (+4)	  --> 1 x 8
	double	lat_lon_ele[3] ;	//    3 x 8		  --> 3 x 8
	float	psi_the_phi[3] ;	//    3 x 4		|
	int		on_ground ;			//    4			| --> 3 x 8
	float	smoke_size ;		//    4 (+4)	|
} XPlaneObjPlace ;				// = 48 (+8)	  --> 7 x 8 = 56 bytes

class Object3D
{
private:
  QString		m_name ;		// nom de l'objet
  int			m_id ;			// n° discriminant
  QString		m_path ;		// chemin relatif p/r à executable X-Plane
  QVector3D	m_position ;	// latitude, longitude et altitude
  QVector3D	m_attitude ;	// rotations
  bool		m_onGround ;
  float		m_smokeSize ;
  public:
	Object3D(int index, const QString& path, QString name) ;
	Object3D(const Object3D &copy) {
		m_id = copy.m_id;
		m_name = copy.m_name ;
		m_path = copy.m_path ;
		m_position = copy.m_position ;
		m_attitude = copy.m_attitude ;
		m_onGround = copy.m_onGround ;
		m_smokeSize = copy.m_smokeSize ;
	}

	int id() const ;
	void setId(int id) {m_id = id;}

	QString path() const ;

	void setPosition(double lat, double lon, double ele ) ;
	void setAttitude(float psi, float the, float phi ) ;
	void setOnGround(int onGround = 0 ) ;
	void setSmokeSize(float smokeSize = 0 ) ;
	void setName(QString name) {m_name = name;}

	QString affichageName() const ;
	QString affichagePosition() const ;
	QString affichageAttitude() const ;
	QString affichageOnGround() const ;
	QString affichageSmokeSize() const ;

	QByteArray xplaneObjectLoadRequest() const ;
	QByteArray xplaneObjectPlaceRequest() const ;

	bool isOnGround() {return m_onGround;}
	QVector3D position() {return m_position;}
	QVector3D attitude() {return m_attitude;}
	float smokeSize() {return m_smokeSize;}
	QString name() {return m_name;}

} ;

#endif
