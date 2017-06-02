/*  ---------------------------------------------------------------------------
 *  filename    :   dataref.h
 *  description :   INTERFACE de la classe DataRef
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

#ifndef DATAREF_H
#define DATAREF_H

// Associations X-Plane Datarefs/Commands, QFI axis et Modbus IO
// ---------------------------------------------------------------------------
//
// fonction de transfert : output = input * scale + offset
//
// par défaut, scale = 1 et offset = 0
// pour inverser un booléen : scale = -1 et offset = 1
//
// 1-	RREF_QFI : RREF --> axe aId de l'instrument iId
//
// 2-	RREF_TOR : RREF --> indicateur TOR
//
// 3-	RREF_ANA : RREF --> indicateur ANA
//
// 4-	TOR_DREF : DREF <-- actuateur TOR
//
// 5- 	ANA_DREF : DREF <-- actuateur ANA (0..1000)
//
// 6-	TOR_CMND : CMND <-- actuateur TOR
//
// Un objet DataRef peut aussi représenter un lien direct entre un indicateur
// ou actuateur et une E/S d'instrument...
//
// 7-	ANA_QFI : actuateur ANA (0..1000) --> numéro d'entrée ANA aId de l'instrument iId
//
// 8-	TOR_QFI : actuateur TOR --> numéro d'entrée TOR aId de l'instrument iId
//
// 9-	QFI_TOR : numéro de sortie TOR aId de l'instrument iId --> indicateur TOR
//
// 10-	TOR_TOR : actuateur TOR --> indicateur TOR
//
// ---------------------------------------------------------------------------

#include <QString>
#include <QByteArray>

#define UNLIKELY_FLOAT	0.123456789

typedef struct {
	int	  id ;
	float value ;
} XPlaneRrefAnswer ;

class DataRef
{
  public:
	DataRef(const QString& path, int freq = 0 ) ;
	DataRef(int iId, int aId, bool input = true ) ;
	DataRef(const QString& input, const QString& output, float scale = 1, float offset = 0 ) ;
	DataRef(const QString& input, const QString& output, const QString& trueSuffix, const QString& falseSuffix ) ;

	void bindToInstrument(int iId, int aId, float scale = 1, float offset = 0 ) ;
	void bindToDigitalIo(const QString& name, float scale = 1, float offset = 0 ) ;
	void bindToAnalogIo(const QString& name, float scale = 1, float offset = 0 ) ;

	enum BindType { UNK, RREF, DREF, CMND, QFI, TOR, ANA } ;

	QByteArray xplaneRrefRequest() const ;
	QByteArray xplaneRrefStop() const ;
	QByteArray xplaneDref(float value ) const ;
	QByteArray xplaneCmnd(bool inputState = true ) const ;

	int id() const ;

	QString sourceName() const ;
	QString targetName() const ;

	int instrumentId() const ;
	int instrumentAxis() const ;
	float scale() const ;
	float offset() const ;

	float lastValue() const ;
	void setLastValue(float v ) ;

	bool isRref() const ;				// RREF_*
	bool isRrefQfi() const ;			// RREF_QFI
	bool isRrefDigital() const ;		// RREF_TOR
	bool isRrefAnalog() const ;			// RREF_ANA

	bool isDref() const ;				//    *_DREF
	bool isDrefDigital() const ;		//  TOR_DREF
	bool isDrefAnalog() const ;			//  ANA_DREF

	bool isCmnd() const ;				//  TOR_CMND

	bool isDigitalQfiInput() const ;	//  TOR_QFI
	bool isAnalogQfiInput() const ;		//  ANA_QFI
	bool isDigitalQfiOutput() const ;	//  QFI_TOR
	bool isDigitalToDigital() const ;	//  TOR_TOR

	float scaled(float value ) const ;

  private:
	QByteArray xplaneRref(int freq = 0 ) const ;

  private:
	static int	m_idProvider ;			// association id
	int 		m_id ;

	BindType	m_source ;				// association source type
	BindType	m_target ;				// association target type
	QString		m_sourceName ;			// association source path or name
	QString		m_targetName ;			// association target path or name

	QString		m_trueSuffix ;			// CMND suffix for true input
	QString		m_falseSuffix ;			// CMND suffix for false input

	float		m_scale ;				// scale factor
	float		m_offset ;				// zero offset
	float		m_lastValue ;			// source current value memory

	int			m_rrefFreq ;			// RREF number of request per second

	int			m_instrumentId ;		// QFI id
	int 		m_instrumentAxis ;		// QFI axis or order num
} ;

#endif
