# 🐰 CrossImple

[![Release](https://img.shields.io/github/v/release/3r1pm4V/CrossInkplusPet?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Version](https://img.shields.io/badge/Version-v0.12-orange?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Device](https://img.shields.io/badge/Devices-Xteink%20X3%20%7C%20X4%20Classic%20%7C%20X4%20Pro-blue?style=flat-square)](#-thiết-bị-hỗ-trợ-supported-devices)
[![Base](https://img.shields.io/badge/Base-CrossInk%20v1.6.1-brightgreen?style=flat-square)](https://github.com/uxjulia/CrossInk)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

> **CrossImple** là bản firmware tối giản (*Simple*), thuần khiết và siêu tối ưu dành cho máy đọc sách E-Ink Xteink X3, X4 Classic và X4 Pro.
> 
> Được xây dựng trên nền tảng **[CrossInk](https://github.com/uxjulia/CrossInk)** (v1.6.1), **CrossImple** loại bỏ hoàn toàn các tính năng thừa thãi (Virtual Pet, trò chơi, máy tính, ứng dụng phụ) để tập trung 100% tài nguyên phần cứng vào trải nghiệm đọc sách mượt mà, tốc độ phản hồi tức thì và tiết kiệm pin tối đa.

---

## 📝 Nhật ký thay đổi (Changelog)

### Phiên bản v0.12
* **Nâng cấp thuật toán Dithering & Độ tương phản E-Ink:**
  * **Ma trận 8x8 Fine Bayer:** Thay thế ma trận Bayer 4x4 cũ bằng ma trận 8x8 (64 mức sắc độ mịn), khử sạch hiện tượng sọc caro và mắt lưới thô trên hình ảnh.
  * **E-Ink Optical Clamping:** Ép ngưỡng đen (`<= 45`) về đen đặc (0) và ép ngưỡng trắng (`>= 225`) về trắng tinh (3). Loại bỏ hoàn toàn các chấm dither li ti bẩn nền giấy, giữ viền chữ và nét vẽ manga đậm nét tương tự firmware stock.
  * **Hiệu chỉnh tương phản bìa sách:** Bật bộ lọc Gamma Correction và tăng 20% tương phản (`CONTRAST_FACTOR = 1.20f`) trong `BitmapHelpers.cpp` cho các bìa sách tạo từ thẻ SD.
* **Cơ chế chống tràn RAM (OOM Guard trên X3):**
  * Tinh gọn trần bộ đệm hàng (`MAX_BAND_BYTES`) từ 24KB xuống 8KB cho vi điều khiển không có PSRAM (ESP32-C3).
  * Bổ sung cơ chế tự động thu hẹp bộ đệm xuống kích thước tối thiểu của một khối MCU (`maxBlockDstRows + 2`, ~3.6KB) khi heap bị phân mảnh, ngăn chặn sập nguồn (OOM) hoặc đơ máy (watchdog reset) khi mở sách có ảnh kích thước lớn.
* **Bổ sung hỗ trợ Xteink X4 Pro:**
  * Xuất bản chính thức firmware `crossimple_x4-pro_v0.12.bin` hỗ trợ đầy đủ màn hình cảm ứng điện dung, phím Home cảm ứng và đèn nền 2 màu Warm/Cool PWM.

---

### Phiên bản v0.11
* **Tái định vị thương hiệu CrossImple (Pure Reader):**
  * Gỡ bỏ hoàn toàn module Virtual Pet (>3.800 dòng code), đưa firmware về trạng thái thuần khiết 100% phục vụ đọc sách, không còn bất kỳ tiến trình hay timer ngầm nào, đưa mức RAM tĩnh trên X3 về mức tối ưu 19.8%.
* **Bộ nhận diện & Màn hình khởi động mới (Bunny Reader):**
  * Tích hợp logo chú thỏ ngồi đọc sách đơn sắc độ phân giải cao, khử sạch watermark.
  * Tinh chỉnh quét ma trận ảnh logo xoay 90° CCW tương thích chuẩn quét dọc (portrait panel scan) của phần cứng.
  * Chuẩn hóa dòng chữ phiên bản khởi động: hiển thị gọn gàng `CrossImple <version>` thay vì chuỗi build gốc của upstream.
* **Chuẩn hóa đặt tên file Firmware xuất ra:**
  * Quy chuẩn định dạng file build tự động: `crossimple_<mã máy>_<version>.bin`.
  * Hỗ trợ chính thức **Xteink X3** và **Xteink X4 Classic**.

---

## 📱 Thiết bị hỗ trợ (Supported Devices)

| Thiết bị | Vi điều khiển (MCU) | Màn hình | Điều khiển | Tên file Firmware xuất ra |
|---|---|---|---|---|
| **Xteink X3** | ESP32-C3 (RISC-V) | 3.97" E-Ink (792x528, ~300 PPI) | Phím cứng (4 phím mặt trước) | `crossimple_x3_v0.12.bin` |
| **Xteink X4 Classic** | ESP32-S3R8 (Xtensa Dual-Core, 8MB PSRAM) | 4.2" E-Ink (800x480, ~220 PPI) | Phím cứng (2 phím cạnh + 4 phím trước) | `crossimple_x4-classic_v0.12.bin` |
| **Xteink X4 Pro** | ESP32-S3R8 (Xtensa Dual-Core, 8MB PSRAM) | 4.2" E-Ink (800x480, ~220 PPI) + Đèn nền Warm/Cool | Cảm ứng (Capacitive Touch) + Home cảm ứng | `crossimple_x4-pro_v0.12.bin` |

---

## 🌟 Điểm nổi bật của CrossImple

1. **Thuần Đọc Sách (Pure & Minimal)**: Không trò chơi, không thú ảo, không ứng dụng thừa. Thiết bị khởi động thẳng vào kho sách của bạn.
2. **Cốt lõi Đọc Sách Hiện Đại**: Focus Reading, Guide Dots, Inline Images, Scalable TTF Fonts, thống kê thời gian đọc, đánh dấu trang và hỗ trợ tiếng Việt hoàn chỉnh.
3. **Hiệu Năng & Pin Tối Đa**: Toàn bộ chu kỳ CPU và RAM của ESP32 được dành trọn vẹn cho việc render trang sách và giải mã font chữ.

---

## 📥 Hướng dẫn Cài đặt & Flash Firmware

### Cách 1: Nâng cấp trực tiếp qua Thẻ nhớ SD (Khuyên dùng)
1. Tải file firmware tương ứng với thiết bị của bạn từ mục [Releases](https://github.com/3r1pm4V/CrossInkplusPet/releases):
   * Với **Xteink X3**: tải `crossimple_x3_v0.12.bin`
   * Với **Xteink X4 Classic**: tải `crossimple_x4-classic_v0.12.bin`
   * Với **Xteink X4 Pro**: tải `crossimple_x4-pro_v0.12.bin`
2. Chép file `.bin` vào thư mục gốc của thẻ MicroSD (định dạng FAT32).
3. Bật máy đọc sách, mở mục **Quản lý tệp (File Browser)**, chọn file `.bin` vừa chép và nhấn **Xác nhận (Confirm)**.
4. Máy sẽ tự động kiểm tra chip ESP32, tag phần cứng, tính toàn vẹn SHA256 và tiến hành flash an toàn. Sau khi hoàn tất máy sẽ tự khởi động lại.

### Cách 2: Flash bằng chế độ Cứu hộ (Bootloader Recovery)
1. Đổi tên file firmware thành `update.bin` và chép vào thư mục gốc của thẻ MicroSD.
2. Tắt máy, sau đó nhấn giữ nút **Quay lại (Back)** đồng thời bấm nút Nguồn để vào chế độ nạp khẩn cấp.
3. Thiết bị sẽ tự động phát hiện `update.bin` và tiến hành nạp firmware.

### Cách 3: Nạp qua cổng USB bằng PlatformIO
```bash
# Cho Xteink X3:
pio run -e default --target upload

# Cho Xteink X4 Classic:
pio run -e x4-classic --target upload
```

---

## 🛠️ Biên dịch từ Mã Nguồn (Build from Source)

```bash
# Clone repository
git clone --recurse-submodules https://github.com/3r1pm4V/CrossInkplusPet.git
cd CrossInkplusPet

# 1. Biên dịch cho Xteink X3 (ESP32-C3)
pio run -e default
# File xuất ra: crossimple_x3_v0.12.bin

# 2. Biên dịch cho Xteink X4 Classic (ESP32-S3)
pio run -e x4-classic
# File xuất ra: crossimple_x4-classic_v0.12.bin

# 3. Biên dịch cho Xteink X4 Pro (ESP32-S3 Touch + Frontlight)
pio run -e x4-pro
# File xuất ra: crossimple_x4-pro_v0.12.bin
```

---

## 🎮 Thao tác Phím Bấm

| Phím | Màn hình chính (Home) | Trong trình đọc sách (Reader) |
|---|---|---|
| **Lên / Trái** | Chọn mục trước | Lật trang trước |
| **Xuống / Phải** | Chọn mục kế tiếp | Lật trang tiếp theo |
| **Xác nhận (Confirm)** | Mở mục đã chọn | Mở menu tùy chọn đọc sách |
| **Quay lại (Back)** | Tiếp tục đọc cuốn sách gần nhất | Thoát sách / Quay lại menu trước |

---

## 📄 Bản quyền & Lời cảm ơn (Credits)

* Kế thừa nền tảng **[CrossInk](https://github.com/uxjulia/CrossInk)** phát triển bởi [@uxjulia](https://github.com/uxjulia) và **[CrossPoint Reader](https://github.com/crosspoint-reader/crosspoint-reader)**.
* Mã nguồn phát hành dưới giấy phép mã nguồn mở [MIT License](LICENSE).
