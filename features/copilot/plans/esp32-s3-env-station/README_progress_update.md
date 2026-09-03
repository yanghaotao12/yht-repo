# Updated README: progress and how to build

Progress:
- KiCad placeholders & DFM notes added. Full KiCad schematic & PCB will be added in the next commit.
- Firmware components: bme280, sgp30, pms7003, ds18b20, ota_wrapper, webui implemented as skeletons with stubs for demo values.
- Flutter app: added mqtt service, device list/detail pages, and history chart page + REST API service.
- Node-RED and Grafana example flows updated.

Build steps summary:
- Firmware: follow firmware/README.md
- App: follow app/README.md
- Node-RED / InfluxDB / Grafana: deploy via Docker or cloud; use provided flows/dashboard JSON as import templates.

What's next (after this commit):
- Generate full KiCad schematic (.sch) and PCB (.kicad_pcb) and Gerbers
- Implement production-grade sensor drivers (replace stubs) and run hardware-in-the-loop testing once PCB is available
- Add GitHub Actions for automated builds (if you confirmed)
