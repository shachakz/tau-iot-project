var mqtt 				= require('mqtt');
var express 			= require('express');
var bodyParser 			= require('body-parser');
var delayed				= require('delayed');
const uuidv4 			= require('uuid/v4');

const REPLY_PREFIX = "reply/";

var queries = {};

app = express();
listenPort = process.env.PORT || 8080;

// Create a client connection
var client = mqtt.connect(process.env.CLOUDMQTT_URL || 'mqtt://qzsobrnn:8kKmrPwIWkLI@m14.cloudmqtt.com:12001');

app.use(bodyParser.json());

// Do this on connection
client.on('connect', function() {

	// subscribe to a topic for responses
  	client.subscribe(REPLY_PREFIX + '+', function() {

		// when a message arrives, do something with it
		client.on('message', onResponseReceived);
	});
});

app.post("/api/cmd", function(req, res)
{
	try {
        console.log('Received post to /api/cmd with body: ' + JSON.stringify(req.body));;

        var isQuery = true;

        var token = generateUid();
        queries[token] = res;

        var payload = createMqttPayload(req, token, isQuery);
        client.publish(createMqttRouting(req), JSON.stringify(payload), function () {
        	console.log("Message is published with payload" + JSON.stringify(payload));
        });

	var dialogflowResp = generateDialogflowResponse(req.body.result.fulfillment.speech);

        if(isQuery){

		delayed.delay(function () { onResponseWaitTimeout(token, res, dialogflowResp); }, 3000);
		return;
	}

	delete queries[token];
	res.status(200).json(dialogflowResp);
    }
    catch(err) {
		console.log('Couldnt handle request beacuse of err: ' + err);
		res.status(501).json({error: err.message});
	}

});

var server = app.listen(listenPort, function () {
	var port = server.address().port;
    	console.log("App now running on port", port);
});

function onResponseWaitTimeout(token, resp, defaultResp) {
	if(queries[token])
	{
		delete queries[token];
		resp.status(200).json(defaultResp);
	}
}

function onResponseReceived(topic, message, packet) {
    	var token = topic.substring(REPLY_PREFIX.length);
	message = JSON.parse(message);
    	console.log("Received '" + message + "' on '" + topic + "'" + ' with token: ' + token);

    	if(queries[token]){
		console.log("I am here with response: " + JSON.stringify(generateDialogflowResponse(message.value)));
		console.log("value is: " + message.value);
    		queries[token].status(200).json(generateDialogflowResponse(message.value));
		delete queries[token];
	}
}

function generateDialogflowResponse(msg) {

	return {
		speech: msg,
		displayText: msg,
		data: {},
		contextOut: [],
		source: "NoOne"
	}
}

function createMqttRouting(req) {
	var location 	= req.body.result.parameters.location;
    	var device 	= req.body.result.parameters.device;
    	var command 	= req.body.result.parameters.command;

    	return location + '/' + device + '/' + command;
}

function createMqttPayload(req, token, isQuery) {
    	var payload = req.body.result.parameters;
	//payload.correlation = token;

    	if (isQuery) {
        	payload.replyTo = REPLY_PREFIX + token;
    	}

    	return payload;
}

function generateUid() {
	var id = uuidv4();
	return id.substring(0, id.indexOf('-'));
}
