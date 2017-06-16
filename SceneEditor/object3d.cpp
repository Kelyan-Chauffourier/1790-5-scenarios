/*  ---------------------------------------------------------------------------
 *  filename    :   object3d.cpp
 *  description :   IMPLEMENTATION de la classe Object3D
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

#include "object3d.h"

#include <QDebug>

Object3D::Object3D(int index, const QString& path , QString name)
	: m_name(name)
	, m_id( index )
	, m_path( path )
	, m_onGround( 0 )
	, m_smokeSize( 0.0 )
{
}

int Object3D::id() const { return m_id ; }
QString Object3D::path() const { return m_path ; }

void Object3D::setPosition(double lat, double lon, double ele )
{
	m_position = QVector3D(lat, lon, ele ) ;
}

void Object3D::setAttitude(float psi, float the, float phi )
{
	m_attitude = QVector3D(psi, the, phi ) ;
}

void Object3D::setOnGround(int onGround )
{
	m_onGround = onGround ;
}

void Object3D::setSmokeSize(float smokeSize )
{
	m_smokeSize = smokeSize ;
}

QString Object3D::affichageName() const
{
	QString name ;
	name = "Objet : " ;
	name += m_name ;
	//name += "\n" ;
	return name ;
}

QString Object3D::affichagePosition() const
{
	QString pos ;
	pos = "Latitude : " ;
	pos += pos.number(m_position.x()) ;
	pos += "\nLongitude : " ;
	pos += pos.number(m_position.y()) ;
	pos += "\nÉlévation : " ;
	pos += pos.number(m_position.z()) ;
	pos += "\n\n" ;
	return pos ;
}

QString Object3D::affichageAttitude() const
{
	QString att ;
	att = "Psi : " ;
	att += att.number(m_attitude.x()) ;
	att += "\nThe : " ;
	att += att.number(m_attitude.y()) ;
	att += "\nPhi : " ;
	att += att.number(m_attitude.z()) ;
	att += "\n\n" ;
	return att ;
}

QString Object3D::affichageOnGround() const
{
	QString gnd ;
	gnd = "Sur le sol : " ;
	if (m_onGround == true)
		gnd += "Oui\n" ;
	else
		gnd += "Non\n" ;
	return gnd ;
}

QString Object3D::affichageSmokeSize() const
{
	QString smk ;
	smk = "Taille de la fumée : " ;
	smk += smk.number(m_smokeSize) ;
	smk += "\n" ;
	return smk ;
}

QByteArray Object3D::xplaneObjectLoadRequest() const
{
	QByteArray frame("OBJN", 4 ) ;
	frame.append( char(0) ) ;
	frame.append((char*)(&m_id), 4 ) ;
	frame.append( m_path ) ;
	frame.append( QByteArray(500 - m_path.size(), 0 ) ) ;

	return frame ;
}

QByteArray Object3D::xplaneObjectPlaceRequest() const
{
	QByteArray frame("OBJL", 4 ) ;
	frame.append( char(0) ) ;

	XPlaneObjPlace	data ;

	data.index          = (int)m_id ;
	data.lat_lon_ele[0] = (double)( m_position.x() ) ;
	data.lat_lon_ele[1] = (double)( m_position.y() ) ;
	data.lat_lon_ele[2] = (double)( m_position.z() ) ;
	data.psi_the_phi[0] = (float)( m_attitude.x() ) ;
	data.psi_the_phi[1] = (float)( m_attitude.y() ) ;
	data.psi_the_phi[2] = (float)( m_attitude.z() ) ;
	data.on_ground      = (int)m_onGround ;
	data.smoke_size     = (float)m_smokeSize ;

	frame.append((char*)(&data), sizeof(XPlaneObjPlace) ) ;

	return frame ;
}
