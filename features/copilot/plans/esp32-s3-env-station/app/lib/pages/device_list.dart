// device_list.dart - simple device list page

import 'package:flutter/material.dart';
import '../services/mqtt_service.dart';

class DeviceListPage extends StatefulWidget {
  final MqttService mqtt;
  const DeviceListPage({required this.mqtt, super.key});

  @override
  State<DeviceListPage> createState() => _DeviceListPageState();
}

class _DeviceListPageState extends State<DeviceListPage> {
  final List<String> devices = ["DEV001"];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Devices')),
      body: ListView.builder(
        itemCount: devices.length,
        itemBuilder: (context, idx) {
          final id = devices[idx];
          return ListTile(
            title: Text('Device: $id'),
            subtitle: const Text('Online'),
            onTap: () {
              Navigator.push(context, MaterialPageRoute(builder: (_) => DeviceDetailPage(deviceId: id, mqtt: widget.mqtt)));
            },
          );
        },
      ),
    );
  }
}

// Forward declare DeviceDetailPage to avoid import cycle in this minimal example
import 'device_detail.dart';
