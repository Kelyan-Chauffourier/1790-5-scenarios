/*  ---------------------------------------------------------------------------
 *  filename    :   dataref.cpp
 *  description :   IMPLEMENTATION de la classe DataRef
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

#include <dataref.h>

// fournisseur d'id discriminant

int DataRef::m_idProvider = 0 ;

// constructeur RREF ou DREF si freq = 0 (valeur par défaut)
// bindToInstrument(), bindToDigitalIo() ou bindToAnalogIo() requis

DataRef::DataRef(const QString& path, int freq  )
	: m_scale( 1.0 )
	, m_offset( 0.0 )
	, m_lastValue( UNLIKELY_FLOAT )
{
	m_id = ++m_idProvider ;	// 1..*

	if ( freq ) {
		m_source = RREF ;
		m_sourceName = path ;
		m_rrefFreq = freq ;
		m_target = UNK ;
	}
	else {
		m_source = UNK ;
		m_target = DREF ;
		m_targetName = path ;
	}
}

// constructeur ANA_QFI, TOR_QFI (input = true) ou QFI_TOR (input = false)
// bindToDigitalIo() ou bindToAnalogIo() requis

DataRef::DataRef(int iId, int aId, bool input )
	: m_scale( 1.0 )
	, m_offset( 0.0 )
	, m_lastValue( UNLIKELY_FLOAT )
	, m_instrumentId( iId )
	, m_instrumentAxis( aId )
{
	m_id = ++m_idProvider ;	// 1..*

	if ( input ) {
		m_source = UNK ;
		m_target = QFI ;
	}
	else {
		m_source = QFI ;
		m_target = UNK ;
	}
}

// constructeur TOR_TOR ( bindToDigitalIo() superflu )

DataRef::DataRef(const QString& input, const QString& output, float scale, float offset )
	: m_scale( scale )
	, m_offset( offset )
	, m_lastValue( UNLIKELY_FLOAT )
{
	m_id = ++m_idProvider ;	// 1..*

	m_source = TOR ;
	m_sourceName = input ;
	m_target = TOR ;
	m_targetName = output ;
}

// constructeur TOR_CMND

DataRef::DataRef(const QString& input, const QString& output, const QString& trueSuffix, const QString& falseSuffix )
	: m_scale( 1.0 )
	, m_offset( 0.0 )
	, m_lastValue(0)
{
	m_id = ++m_idProvider ;	// 1..*

	m_source = TOR ;
	m_sourceName = input ;
	m_target = CMND ;
	m_targetName = output ;
	m_trueSuffix = trueSuffix ;
	m_falseSuffix = falseSuffix ;
}

// association du DataRef avec la grandeur (l'axe) aId de l'instrument iId

void DataRef::bindToInstrument(int iId, int aId, float scale, float offset )
{
	if ( m_target == UNK ) {
		m_target = QFI ;
		m_instrumentId = iId ;
		m_instrumentAxis = aId ;
		m_scale = scale ;
		m_offset = offset ;
	}
}

// association du DataRef avec un indicateur (RREF) ou un actuateur (DREF) de type TOR

void DataRef::bindToDigitalIo(const QString& name, float scale, float offset )
{
	if ( m_target == UNK )	{ m_target = TOR ; m_targetName = name ; }
	if ( m_source == UNK )	{ m_source = TOR ; m_sourceName = name ; }
	m_scale = scale ;
	m_offset = offset ;
}

// association du DataRef avec un indicateur (RREF) ou un actuateur (DREF) de type ANA

void DataRef::bindToAnalogIo(const QString& name, float scale, float offset )
{
	if ( m_target == UNK )	{ m_target = ANA ; m_targetName = name ; }
	if ( m_source == UNK )	{ m_source = ANA ; m_sourceName = name ; }
	m_scale = scale ;
	m_offset = offset ;
}

// sélecteurs

int 	DataRef::id() const 				{ return m_id ; }

QString DataRef::sourceName() const 		{ return m_sourceName ; }
QString DataRef::targetName() const 		{ return m_targetName ; }

int 	DataRef::instrumentId() const 		{ return m_instrumentId ; }
int 	DataRef::instrumentAxis() const 	{ return m_instrumentAxis ; }

float   DataRef::scale() const 				{ return m_scale ; }
float	DataRef::offset() const 			{ return m_offset ; }

bool DataRef::isRref() const				{ return   m_source == RREF ; }
bool DataRef::isRrefQfi() const				{ return ( m_source == RREF )&&( m_target == QFI ) ; }
bool DataRef::isRrefDigital() const			{ return ( m_source == RREF )&&( m_target == TOR ) ; }
bool DataRef::isRrefAnalog() const			{ return ( m_source == RREF )&&( m_target == ANA ) ; }

bool DataRef::isDref() const				{ return   m_target == DREF ; }
bool DataRef::isDrefDigital() const			{ return ( m_target == DREF )&&( m_source == TOR ) ; }
bool DataRef::isDrefAnalog() const			{ return ( m_target == DREF )&&( m_source == ANA ) ; }

bool DataRef::isCmnd() const				{ return   m_target == CMND ; }

bool DataRef::isDigitalQfiInput() const		{ return ( m_target == QFI )&&( m_source == TOR ) ; }
bool DataRef::isAnalogQfiInput() const		{ return ( m_target == QFI )&&( m_source == ANA ) ; }
bool DataRef::isDigitalQfiOutput() const	{ return ( m_source == QFI )&&( m_target == TOR ) ; }

bool DataRef::isDigitalToDigital() const	{ return ( m_source == TOR )&&( m_target == TOR ) ; }

// mémoire valeur brute courante

float DataRef::lastValue() const 		{ return m_lastValue ; }
void  DataRef::setLastValue(float v ) 	{ m_lastValue = v ; }

// retourne la valeur corrigée en fonction de scale et offset

float DataRef::scaled(float value ) const
{
	return value * m_scale + m_offset ;
}

// retourne la trame de requête d'émission RREF à envoyer à X-Plane

QByteArray DataRef::xplaneRrefRequest() const
{
	return xplaneRref( m_rrefFreq ) ;
}

// retourne la trame de demande d'arrêt d'émission RREF

QByteArray DataRef::xplaneRrefStop() const
{
	return xplaneRref() ;
}

// retourne la trame de commande CMND

QByteArray DataRef::xplaneCmnd(bool inputState ) const
{
	QByteArray frame("CMND", 4 ) ;
	frame.append( char(0) ) ;
	frame.append( m_targetName ) ;
	frame.append( inputState ? m_trueSuffix : m_falseSuffix ) ;
	frame.append( char(0) ) ;
	return frame ;
}

// (private)
// fabrication de la trame RREF (freq = 0 par défaut)

QByteArray DataRef::xplaneRref(int freq ) const
{
	QByteArray frame("RREF", 4 ) ;
	frame.append( char(0) ) ;
	frame.append((char*)(&freq), 4 ) ;
	frame.append((char*)(&m_id), 4 ) ;
	frame.append( m_sourceName ) ;
	frame.append( QByteArray(400 - m_sourceName.size(), 0 ) ) ;
	return frame ;
}

// retourne la trame DREF de demande de modification du Dataref

QByteArray DataRef::xplaneDref(float value ) const
{
	QByteArray frame("DREF", 4 ) ;
	frame.append( char(0) ) ;
	frame.append((char*)(&value), 4 ) ;
	frame.append( m_targetName ) ;
	frame.append( QByteArray(500 - m_targetName.size(), 0 ) ) ;
	return frame ;
}
