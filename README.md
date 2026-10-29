# 🐰 CrossImple

[![Release](https://img.shields.io/github/v/release/3r1pm4V/CrossInkplusPet?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Version](https://img.shields.io/badge/Version-v0.11-orange?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Device](https://img.shields.io/badge/Devices-Xteink%20X3%20%7C%20X4%20Classic-blue?style=flat-square)](#-thiết-bị-hỗ-trợ-supported-devices)
[![Base](https://img.shields.io/badge/Base-CrossInk%20v1.6.1-brightgreen?style=flat-square)](https://github.com/uxjulia/CrossInk)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

> **CrossImple** là bản firmware tối giản (*Simple*), thuần khiết và siêu tối ưu dành cho máy đọc sách E-Ink Xteink X3 và X4 Classic.
> 
> Được xây dựng trên nền tảng **[CrossInk](https://github.com/uxjulia/CrossInk)** (v1.6.1), **CrossImple** loại bỏ hoàn toàn các tính năng thừa thãi (Virtual Pet, trò chơi, máy tính, ứng dụng phụ) để tập trung 100% tài nguyên phần cứng vào trải nghiệm đọc sách mượt mà, tốc độ phản hồi tức thì và tiết kiệm pin tối đa.

---

## 📝 Nhật ký thay đổi (Changelog - v0.11)

* **Bộ nhận diện thương hiệu CrossImple:**
  * Màn hình khởi động mới với Logo **Chú thỏ ngồi đọc sách (Bunny Reading a Book)** đơn sắc cực kỳ sắc nét.
  * Tên thương hiệu hiển thị trang nhã: **`CrossImple`** kèm phiên bản rút gọn: **`CrossImple v0.11`**.
* **Loại bỏ hoàn toàn Virtual Pet & Bloatware (Pure Reader):**
  * Gỡ bỏ toàn bộ code thú ảo chạy nền, triệt tiêu background timers, giải phóng hoàn toàn bộ nhớ heap và flash.
  * Thiết bị hoạt động mát mẻ, ổn định, không có bất kỳ tiến trình ngầm nào làm tiêu hao pin khi đọc.
* **Tối ưu hóa EPUB cực đại (Sliding Window Cache):**
  * Giảm mức RAM tĩnh khi duyệt metadata chương sách xuống chỉ ~128 bytes (ngay cả với sách hàng nghìn chương), triệt tiêu hoàn toàn nguy cơ tràn RAM (OOM) trên ESP32.
* **Tăng tốc hiển thị & bố cục:**
  * Tích hợp bộ cấp phát token chữ `WordStore` dạng arena tránh phân mảnh heap.
  * Streaming `InflateReader` giải nén ảnh và nội dung mượt mà.
  * Hỗ trợ ngắt dòng CJK và tiếng Việt theo chuẩn Unicode UAX#14.
* **Hỗ trợ 2 thiết bị:** Hỗ trợ chính thức cả **Xteink X3** và **Xteink X4 Classic**.

---

## 📱 Thiết bị hỗ trợ (Supported Devices)

| Thiết bị | Vi điều khiển (MCU) | Màn hình | Điều khiển | Tên file Firmware xuất ra |
|---|---|---|---|---|
| **Xteink X3** | ESP32-C3 (RISC-V) | 3.97" E-Ink (792x528, ~300 PPI) | Phím cứng (4 phím mặt trước) | `crossimple_x3_v0.11.bin` |
| **Xteink X4 Classic** | ESP32-S3R8 (Xtensa Dual-Core, 8MB PSRAM) | 4.2" E-Ink (800x480, ~220 PPI) | Phím cứng (2 phím cạnh + 4 phím trước) | `crossimple_x4-classic_v0.11.bin` |

> ⚠️ **Lưu ý:** Bản **X4 Pro** (màn hình cảm ứng Touch và đèn nền Frontlight) hiện **không** nằm trong danh sách hỗ trợ của bản build này.

---

## 🌟 Điểm nổi bật của CrossImple

1. **Thuần Đọc Sách (Pure & Minimal)**: Không trò chơi, không thú ảo, không ứng dụng thừa. Thiết bị khởi động thẳng vào kho sách của bạn.
2. **Cốt lõi Đọc Sách Hiện Đại**: Focus Reading, Guide Dots, Inline Images, Scalable TTF Fonts, thống kê thời gian đọc, đánh dấu trang và hỗ trợ tiếng Việt hoàn chỉnh.
3. **Hiệu Năng & Pin Tối Đa**: Toàn bộ chu kỳ CPU và RAM của ESP32 được dành trọn vẹn cho việc render trang sách và giải mã font chữ.

---

## 📥 Hướng dẫn Cài đặt & Flash Firmware

### Cách 1: Nâng cấp trực tiếp qua Thẻ nhớ SD (Khuyên dùng)
1. Tải file firmware tương ứng với thiết bị của bạn từ mục [Releases](https://github.com/3r1pm4V/CrossInkplusPet/releases):
   * Với **Xteink X3**: tải `crossimple_x3_v0.11.bin`
   * Với **Xteink X4 Classic**: tải `crossimple_x4-classic_v0.11.bin`
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
# File xuất ra: crossimple_x3_v0.11.bin

# 2. Biên dịch cho Xteink X4 Classic (ESP32-S3)
pio run -e x4-classic
# File xuất ra: crossimple_x4-classic_v0.11.bin
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
