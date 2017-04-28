/*  ---------------------------------------------------------------------------
 *  filename    :   xplaneudpworker.cpp
 *  description :   IMPLEMENTATION de la classe XPlaneUdpWorker
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

#include <QCoreApplication>
#include "xplaneudpworker.h"

#include <QThread>

//XPlaneUdpWorker::XPlaneUdpWorker(const QString& host, int port, QList<DataRef*>& datarefs )
XPlaneUdpWorker::XPlaneUdpWorker(const QString& host, int recvPort, int sendPort, int rref_req )
	: m_udpHost( host )
	, m_xplane_rref_req( rref_req )
	, m_udpRecvPort( recvPort )
	, m_udpSendPort( sendPort )
{
	m_udpSendSocket = new QamUdpSocket( this ) ;
	m_udpSendSocket->sockBind() ;
	m_udpSendSocket->setRemoteHost( m_udpHost, m_udpRecvPort ) ;

	connect( m_udpSendSocket, SIGNAL( sockInfo(const QString& ) ),
			 this,        	  SIGNAL( udpInfo(const QString& ) ) ) ;
//
	connect( m_udpSendSocket, SIGNAL( sockReceived(const QByteArray& ) ),
			 this,        	  SLOT(   received(const QByteArray& ) ) ) ;
//
	m_udpRecvSocket = new QamUdpSocket( this ) ;
//	m_udpRecvSocket->sockBind( m_udpSendPort ) ;
	m_udpRecvSocket->sockBind() ;
	m_udpRecvSocket->setRemoteHost( m_udpHost, m_udpSendPort ) ;

	connect( m_udpRecvSocket, SIGNAL( sockInfo(const QString& ) ),
			 this,        	  SIGNAL( udpInfo(const QString& ) ) ) ;

	connect( m_udpRecvSocket, SIGNAL( sockReceived(const QByteArray& ) ),
			 this,        	  SLOT(   received(const QByteArray& ) ) ) ;
/*
	m_udpSocket = new QamUdpSocket( this ) ;
	m_udpSocket->sockBind() ;
	m_udpSocket->setRemoteHost( m_udpHost, m_udpPort ) ;

	connect( m_udpSocket, SIGNAL( sockInfo(const QString& ) ),
			 this,        SIGNAL( udpInfo(const QString& ) ) ) ;

	connect( m_udpSocket, SIGNAL( sockReceived(const QByteArray& ) ),
			 this,        SLOT(   received(const QByteArray& ) ) ) ;
*/
	m_rrefWaitingTimer = new QTimer ;
	connect(m_rrefWaitingTimer, SIGNAL( timeout() ), this, SLOT( timeout() ) ) ;
}

void XPlaneUdpWorker::stop()
{

	if ( m_rrefWaitingTimer->isActive() )	m_rrefWaitingTimer->stop() ;
	delete m_rrefWaitingTimer ;

//    m_udpSocket->sockClose() ;
//    delete m_udpSocket ;
	m_udpSendSocket->sockClose() ;
	delete m_udpSendSocket ;
	m_udpRecvSocket->sockClose() ;
	delete m_udpRecvSocket ;
}

void XPlaneUdpWorker::timeout()
{
	m_rrefWaitingId = -1 ;
}

// émission des requêtes RREF


// réception des RREF



// émission des DREF

void XPlaneUdpWorker::send(const QByteArray& data )
{
//	m_udpSocket->sockWrite( data ) ;
//	m_udpSocket->sockWrite( data, 49000 ) ;
	m_udpSendSocket->sockWrite( data, m_udpRecvPort ) ;
}
