Gerber export checklist:

1. Open esp32-s3-env-station.kicad_pcb in KiCad PCBNew
2. File -> Plot -> RS-274X, select layers: F.Cu, B.Cu, F.SilkS, B.SilkS, F.Mask, B.Mask, Edge.Cuts
3. Generate Drill file (Excellon)
4. Zip gerbers and drill file. Include BOM and Pick-and-Place CSV for assembly.

Recommended JLCPCB settings: 2-layer, 1.6mm, HASL lead-free, ENIG if you need better finish. Minimum track/space 6/6 mil.
