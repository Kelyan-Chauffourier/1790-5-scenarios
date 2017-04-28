import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
import QtQuick.XmlListModel 2.0

Window {
	id: sP
	visible: true
	width: 640
	height: 480
	title: qsTr("ScenePlayer")

	Rectangle {
		id: main
		color: "#ffffff"
		anchors.fill: parent
		ColumnLayout {
			anchors.fill: parent

			Text {
				id: appName
				text: "ScenePlayer"
				Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				font.pointSize: 15
			}

			ColumnLayout {
				id: columnLayout

				RowLayout {
					id: header
					Layout.fillWidth: true

					Label {
						id: labSCN
						text: qsTr("Fichier SCN : ")
					}

					TextField {
						id: txtSCN
						text: fileDialog.fileUrl
						readOnly: true
						placeholderText: "chemin d'accès"
						Layout.fillWidth: true
//						onTextChanged: pbuOK.enabled = true
					}
					Button {
						id: pbuSCN
						text: qsTr("...")
						Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
						onClicked: fileDialog.open()
					}
					FileDialog {
						id: fileDialog
						title: "Charger un scénario"
						sidebarVisible: false
						nameFilters: [
							"Fichiers scénario (*.scn)",
							"All files (*)"
						]
						onAccepted: pbuOK.enabled = true
					}
				}

				Component {
					id: scnHeader
					Rectangle {
						z: 2
						width: main.width
						height: 40
						border.width: 1
						border.color: "black"
						color: "#808080"
						Row {
							spacing: 10
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtAction
									width: parent.width
									text: "<b>Action</b>"
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtDeclencheur
									width: parent.width
									text: "<b>Declencheur</b>"
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
						}
					}
				}

//				XmlListModel {
//					id: xmlModel
////					source: txtSCN.text
//					query: "/scnfile/event"
//					XmlRole {
//						name: "name"
//						query: "name/string()"
//					}

//					XmlRole {
//						name: "action_desc"
//						query: "actions/description/string()"
//					}

//					XmlRole {
//						name: "declencheur_desc"
//						query: "declencheur/description/string()"
//					}

//					XmlRole {
//						name: "declencheur_type"
//						query: "declencheur/type/string()"
//					}

//					XmlRole {
//						name: "time"
//						query: "declencheur/time/string()"
//					}
//					XmlRole {
//						name: "latitude"
//						query: "declencheur/lat/string()"
//					}
//					XmlRole {
//						name: "longitude"
//						query: "declencheur/lon/string()"
//					}
//					XmlRole {
//						name: "rayon"
//						query: "declencheur/rayon/string()"
//					}
//				}

				ListView {
					id: scnXmlView
					Layout.fillWidth: true
					Layout.fillHeight: true
					header: scnHeader
					headerPositioning: ListView.OverlayHeader
					model: scnModel
					delegate: scnXmlDelegate
					highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
					focus: true
//					z: -1
					cacheBuffer: 0
					clip: true
				}

				ListModel {
					id: scnModel
					ListElement {
						name : "Nom événement E1"
						action : "Description E1\nType : type A1\nParamètre : paramètre  A1"
						declencheur : "Description D1\nType : type D1\nParamètre : paramètre D1"
					}
					ListElement {
						name : "Nom événement E2"
						action : "A2 description de A2"
						declencheur : "D2 description de D2"
					}
					ListElement {
						name : "Nom événement E3"
						action : "A3 description de A3"
						declencheur : "D3 description de D3"
					}
				}

				Component {
					id: scnXmlDelegate
					Rectangle {
						width: main.width
//						height: {
//							if (txtDeclencheur.implicitHeight < 40 ) {
//								return 40 ;
//							}
//							else {
//								return txtDeclencheur.implicitHeight ;
//							}
//						}
						height: element.implicitHeight
						border.width: 1
						border.color: "black"
						color: "transparent"

						Row {
							spacing: 20
							id: element
							Column {
							width: main.width
							    Text {
									width: parent.width
									text: name
									padding: 5
									font.bold: true
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
								}

								Row {
//									spacing: 10
									Column {
//										padding: 10
										width: main.width / 2
										Text {
											id: txtDescription
											width: parent.width
											text: action
											padding: font.pointSize
											horizontalAlignment: Text.AlignHCenter
											verticalAlignment: Text.AlignVCenter
											wrapMode: Text.WordWrap
											elide: Text.ElideRight
										}
									}
									Column {
//										padding: 10
										width: main.width / 2
										Text {
											width: parent.width
											text: declencheur
											padding: font.pointSize
											horizontalAlignment: Text.AlignHCenter
											verticalAlignment: Text.AlignVCenter
											wrapMode: Text.WordWrap
											elide: Text.ElideRight
										}
									}
								}
							}
						}
						MouseArea {
							anchors.fill: parent
							onClicked: scnXmlView.currentIndex = index
						}
					}
				}

				WorkerScript {
					id: worker
					source: "dataloader.js"
				}

				RowLayout {
					id: footer
					Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

					Button {
						id: pbuQuitter
						text: qsTr("Quitter")
						onClicked: messageQuitter.open()
					}

					MessageDialog {
						id: messageQuitter
						title: "Quitter ?"
						icon: StandardIcon.Question
						text: "Voulez vous vraiment quitter ScenePlayer"
						standardButtons: StandardButton.Yes | StandardButton.No
						onYes: sP.close()
					}

					Button {
						id: pbuRestart
						text: qsTr("Recommencer")
						enabled: false
						onClicked: messageRestart.open()
					}

					MessageDialog {
						id: messageRestart
						title: "Recommencer ?"
						icon: StandardIcon.Question
						text: "Voulez vous réinitialiser le scénario courant ?"
						standardButtons: StandardButton.Yes | StandardButton.No
						onYes: {
							loadScn(txtSCN.text);
							pbuRestart.enabled = false;
						}
					}

					Button {
						id: pbuDeclencher
						enabled: {
							if (scnXmlView.count != 0)
								return true ;
							return false ;
						}

						text: qsTr("Déclencher")
						onClicked: {
							xmlreader.runEvent(scnXmlView.currentIndex) ;
//							var msg = {
//								'action': 'deleteEvent',
//								'model': scnModel,
//								'index': scnXmlView.currentIndex
//							};
//							worker.sendMessage(msg);
////							scnXmlView.remove ;
//							pbuRestart.enabled = true ;
//							endScn(scnXmlView.count) ;
						}
					}

					MessageDialog {
						id: messageEnd
						title: "Fin du scénario"
						icon: StandardIcon.Information
						text: "Le scénario est terminé"
						standardButtons: StandardButton.Ok
						onAccepted: close()
					}

					Button {
						id: pbuOK
						text: qsTr("Charger")
						enabled: false
						onClicked: {
							loadScn(txtSCN.text);
							enabled = false;
							pbuRestart.enabled = false;
						}
					}
				}
			}
		}
	}
	function loadScn(file)
	{
		xmlreader.readData(file) ;
		var restart = {
			'action': 'restartScn',
			'model': scnModel
		};
		worker.sendMessage(restart) ;
		var i = 0 ;
		for (i = 0 ; i < xmlreader.numberEvents() ; i++) {
			var msg = {
				'action': 'addEvent',
				'model': scnModel,
				'name': xmlreader.eventName(i),
				'actions': xmlreader.eventActions(i),
				'declencheur': xmlreader.eventDeclencheur(i),
				'index': i
			};
			worker.sendMessage(msg) ;
		}
	}
	function endScn(nbRow)
	{
		if (nbRow == 1) {
			messageEnd.open() ;
		}
	}
}
