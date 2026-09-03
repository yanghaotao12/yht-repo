// device_detail.dart - simple device details & control
import 'package:flutter/material.dart';
import '../services/mqtt_service.dart';

class DeviceDetailPage extends StatefulWidget {
  final String deviceId;
  final MqttService mqtt;
  const DeviceDetailPage({required this.deviceId, required this.mqtt, super.key});

  @override
  State<DeviceDetailPage> createState() => _DeviceDetailPageState();
}

class _DeviceDetailPageState extends State<DeviceDetailPage> {
  String lastTelemetry = '{}';

  @override
  void initState() {
    super.initState();
    widget.mqtt.onMessage = (topic, payload) {
      if (topic.contains(widget.deviceId)) {
        setState(() { lastTelemetry = payload; });
      }
    };
    widget.mqtt.subscribe('device/${widget.deviceId}/telemetry');
  }

  void _toggleRelay(int relay, bool on) {
    final cmd = '{"relay$relay":"${on?"on":"off"}"}';
    widget.mqtt.publish('device/${widget.deviceId}/command', cmd);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(widget.deviceId)),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text('Telemetry:'),
            Text(lastTelemetry),
            const SizedBox(height: 20),
            Row(children: [
              ElevatedButton(onPressed: () => _toggleRelay(1, true), child: const Text('Relay1 ON')),
              const SizedBox(width: 10),
              ElevatedButton(onPressed: () => _toggleRelay(1, false), child: const Text('Relay1 OFF')),
            ])
          ],
        ),
      ),
    );
  }
}
