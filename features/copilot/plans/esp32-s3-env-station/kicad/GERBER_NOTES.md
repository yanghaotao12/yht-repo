# KiCad Gerber & DFM notes

When KiCad files are ready, export Gerbers with the following settings for JLCPCB:
- Gerber format: RS-274X
- Layers: F.Cu, B.Cu, F.Paste, B.Paste, F.SilkS, B.SilkS, F.Mask, B.Mask, Edge.Cuts
- Drill file: Excellon
- Board thickness: 1.6mm
- Surface finish: HASL
- Minimum trace/space: 6/6 mil recommended (10/10 mil safe)
- Provide BOM and Pick-and-Place CSV for assembly

I will generate Gerbers in the next commit after producing the .kicad_pcb.
