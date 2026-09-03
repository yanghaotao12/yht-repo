JLCPCB 下单与免费打板说明

目标：生成可直接上传到嘉立创（JLCPCB）进行免费 PCB 打样的 Gerber 打包与下单说明，并给出可选的贴片（SMT）组装指导与 BOM 映射建议。

我将为你准备并提交：
- gerber/esp32-s3-env-station_gerbers.zip （包含 RS-274X 格式的所有层与 drill 文件）
- Pick-and-Place.csv（用于贴片组装，若需）
- BOM_for_JLCPCB.csv（包含 JLC 可识别的元件描述/参考，用于 SMT 组装申请）
- JLCPCB_ORDER.md（本文件）

推荐的 JLCPCB 工单参数（适合免费打板/低成本快速打样）：
- 层数：2 层
- 板厚：1.6mm
- 表面处理：HASL（默认 / 选择无铅为 Pb‑free）
- 颜色：绿色或黑色（绿/白对比明显）
- 丝印：覆盖 F.SilkS + B.SilkS
- 最小线宽/线距：默认 6/6 mil（KiCad 里我们会保持 >= 10/10 mil 以安全起见）
- 最小孔径：0.4mm
- 边框（Edge.Cuts）：请确保边界封闭无多段断裂

上传前的检查清单（我会在生成 Gerber 后帮你检查）：
1. Edge.Cuts 完整并形成闭合多边形；四个安装孔（M3）中心已留好并标注。  
2. 设计中没有未连接的 nets（Orphan nets），并保证 3.3V 与 GND 有足够的铜厚与去耦。  
3. 天线 keepout 区域（若使用 PCB 天线）已设置空白，天线周围无地铜覆盖。  
4. I2C 上拉电阻、UART 端口电平、电源过滤电容均在 BOM 中注明位置。  
5. 生成的 BOM 与 Pick-and-Place CSV 中的封装名与坐标与 Gerber/PCB 一致（PnP 以 mm 为单位）。

关于是否做 SMT 组装（JLC 提供 SMT 服务）：
- 如果你只想免费拿到 PCB，选择“裸板”即可（最便宜，免费样板一般为裸板）。  
- 如果想要直接拿到贴好元器件的成品板，需要额外付贴片与元件费用，并且 BOM 必须映射到 JLC 可采购的料号或你提供元件。  
- 默认我会为你准备裸板的 Gerber 与完整 BOM；如果你后续想做 SMT，我可把 BOM 映射到 JLC 的料号并生成 PnP 文件，协助你直接在 JLC 下单贴片。

接下来我会做的事情（立即执行）：
1. 基于当前 KiCad PCB（features/.../kicad/pcb/esp32-s3-env-station.kicad_pcb）完善布线与封装（若尚未完整）。  
2. 导出 Gerber（RS-274X）和 Drill（Excellon），并生成 gerber_zip。  
3. 生成 Pick-and-Place CSV（坐标、角度、封装）以及面向 JLC 的 BOM CSV（元件参考、数量、封装、建议物料描述）。  
4. 把生成的文件打包并推送到 esp32-s3-env-station 分支下的 features/.../kicad/gerber/ 路径。

如果你同意上述流程，我就立即开始生成 Gerber 并上传打包文件；若你希望我在下单前先把 BOM 映射到 JLC 的料号并报价，请回复“需要映射并报价”，我会额外处理（这一步会花更多时间来匹配料号）。

默认动作（我将执行）：生成 Gerber + PnP + BOM（用于裸板下单），并把文件上传到分支。若你现在同意，请回复 “开始生成 Gerber”。