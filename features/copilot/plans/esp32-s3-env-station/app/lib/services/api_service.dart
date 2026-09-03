// services/api_service.dart - REST helper to fetch historical data from Node-RED/InfluxDB REST endpoint

import 'dart:convert';
import 'package:http/http.dart' as http;

class ApiService {
  final String baseUrl;
  ApiService(this.baseUrl);

  Future<List<double>> fetchTemperatureHistory(String deviceId, String hours) async {
    final url = Uri.parse('$baseUrl/api/history?device=$deviceId&hours=$hours');
    final res = await http.get(url);
    if (res.statusCode == 200) {
      final data = jsonDecode(res.body) as List;
      return data.map((e) => (e['temp'] as num).toDouble()).toList();
    }
    return [];
  }
}
