// mqtt_service.dart - basic MQTT service for Flutter using mqtt_client

import 'package:mqtt_client/mqtt_client.dart';
import 'package:mqtt_client/mqtt_server_client.dart';

class MqttService {
  final MqttServerClient client;
  Function(String topic, String payload)? onMessage;

  MqttService(String host, String clientId)
      : client = MqttServerClient(host, clientId) {
    client.logging(on: false);
    client.setProtocolV311();
    client.keepAlivePeriod = 20;
  }

  Future<bool> connect({String? username, String? password}) async {
    try {
      await client.connect(username, password);
    } catch (e) {
      client.disconnect();
      return false;
    }
    client.updates?.listen((List<MqttReceivedMessage<MqttMessage>> events) {
      final recMess = events[0].payload as MqttPublishMessage;
      final payload = MqttPublishPayload.bytesToStringAsString(recMess.payload.message);
      final topic = events[0].topic;
      if (onMessage != null) onMessage!(topic, payload);
    });
    return true;
  }

  void subscribe(String topic) {
    client.subscribe(topic, MqttQos.atMostOnce);
  }

  void publish(String topic, String message) {
    client.publishMessage(topic, MqttQos.atLeastOnce, MqttClientPayloadBuilder().addString(message).payload!);
  }

  void disconnect() {
    client.disconnect();
  }
}
