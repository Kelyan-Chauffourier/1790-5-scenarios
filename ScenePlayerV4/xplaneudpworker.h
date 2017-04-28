/*  ---------------------------------------------------------------------------
 *  filename    :   xplaneudpworker.h
 *  description :   INTERFACE de la classe XPlaneUdpWorker
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

#ifndef XPLANEUDPWORKER_H
#define XPLANEUDPWORKER_H

//	Classe d'interface entre FlightSim et X-Plane
// ---------------------------------------------------------------------------
// - agrégation avec la liste des DataRef
// - émission des requêtes RREF
// - réception des réponses RREF périodiques
// - émission des commandes DREF / OBJN / OBJL
// ---------------------------------------------------------------------------

#include <QObject>
#include <QTimer>
#include <QamUdpSocket>
#include "dataref.h"

class XPlaneUdpWorker : public QObject
{
	Q_OBJECT

  public:
//	explicit XPlaneUdpWorker(const QString& host, int port, QList<DataRef*>& datarefs ) ;
	explicit XPlaneUdpWorker(const QString& host, int recvPort, int sendPort, int rref_req) ;

	void stop() ;

  public slots:
	void send(const QByteArray& data ) ;

  private slots:
	void timeout() ;

  private:
//	QamUdpSocket*		m_udpSocket ;
	QamUdpSocket*		m_udpRecvSocket ;		// socket de réception
	QamUdpSocket*		m_udpSendSocket ;		// socket d'émission
	QString				m_udpHost ;				// hôte distant
// 	int					m_udpPort ;
	int                 m_xplane_rref_req ;     // X-Plane Refresh RREF
	int					m_udpRecvPort ;			// X-Plane UDP receive port
	int					m_udpSendPort ;			// X-Plane UDP send port

	QTimer*				m_rrefWaitingTimer ;
	int 				m_rrefWaitingId ;
} ;

#endif
