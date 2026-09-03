# Flutter: history chart page (uses fl_chart)

import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';

class HistoryChartPage extends StatelessWidget {
  final List<FlSpot> spots;
  const HistoryChartPage({required this.spots, super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('History')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: LineChart(LineChartData(lineBarsData: [
          LineChartBarData(spots: spots, isCurved: true, dotData: FlDotData(show: false))
        ])),
      ),
    );
  }
}
