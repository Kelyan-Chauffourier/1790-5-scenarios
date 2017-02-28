WorkerScript.onMessage = function(msg) {
	if (msg.action == 'addEvent') {
		var data = {'action': msg.name, 'declencheur': msg.type};
		msg.model.append(data);
		msg.model.sync();   // updates the changes to the list
	}
}
