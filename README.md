# 🐾 PetInk (CrossPet Rebuild)

[![Release](https://img.shields.io/github/v/release/3r1pm4V/CrossInkplusPet?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Version](https://img.shields.io/badge/Version-v0.11-orange?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Device](https://img.shields.io/badge/Devices-Xteink%20X3%20%7C%20X4%20Classic-blue?style=flat-square)](#-thiết-bị-hỗ-trợ-supported-devices)
[![Base](https://img.shields.io/badge/Base-CrossInk%20v1.6.1-brightgreen?style=flat-square)](https://github.com/uxjulia/CrossInk)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

> **PetInk** (trước đây là CrossPet Rebuild) là bản firmware tuỳ biến kết hợp giữa trình đọc sách hiện đại, hiệu năng cao của **[CrossInk](https://github.com/uxjulia/CrossInk)** (v1.6.1) và hệ thống **Thú Ảo (Virtual Pet)** rèn luyện thói quen đọc sách.
>
> ⚠️ **Hỗ trợ phần cứng:** Hiện tại firmware **chỉ hỗ trợ 2 dòng máy: Xteink X3 và Xteink X4 Classic** (phiên bản phím bấm vật lý, không cảm ứng).

---

## 📝 Nhật ký thay đổi (Changelog - v0.11)

* **Bộ nhận diện thương hiệu PetInk:**
  * Màn hình khởi động mới với Logo **"Dấu chân cưng trong trang sách" (Paw in Open Book)** độc quyền.
  * Tên thương hiệu hiển thị rõ nét: **`PetInk`** kèm phiên bản rút gọn sạch sẽ: **`PetInk v0.11`** (thay thế mã dev commit cũ).
* **Tích hợp Thú Ảo đọc sách (Virtual Pet):** Đưa toàn bộ cơ chế thú ảo rèn luyện thói quen đọc sách lên nền tảng **CrossInk v1.6.1** mới nhất.
* **Loại bỏ Bloatware:** Xóa hoàn toàn các công cụ, máy tính và mini-game thừa thãi, tối ưu hóa tối đa RAM và bộ nhớ Flash.
* **Tối ưu hóa EPUB cực đại (Sliding Window Cache):** Giảm mức RAM tĩnh khi duyệt metadata chương sách xuống chỉ ~128 bytes (ngay cả với sách hàng nghìn chương), triệt tiêu lỗi tràn RAM (OOM) trên ESP32.
* **Tăng tốc hiển thị & bố cục:** Tích hợp bộ cấp phát token chữ `WordStore` dạng arena tránh phân mảnh heap, streaming `InflateReader` giải nén ảnh/nội dung mượt mà, hỗ trợ ngắt dòng CJK theo chuẩn Unicode UAX#14.
* **Hỗ trợ 2 thiết bị:** Hỗ trợ chính thức cả **Xteink X3** và **Xteink X4 Classic**.

---

## 📱 Thiết bị hỗ trợ (Supported Devices)

| Thiết bị | Vi điều khiển (MCU) | Màn hình | Điều khiển | Tên file Firmware xuất ra |
|---|---|---|---|---|
| **Xteink X3** | ESP32-C3 (RISC-V) | 3.97" E-Ink (792x528, ~300 PPI) | Phím cứng (4 phím mặt trước) | `petink_x3_v0.11.bin` |
| **Xteink X4 Classic** | ESP32-S3R8 (Xtensa Dual-Core, 8MB PSRAM) | 4.2" E-Ink (800x480, ~220 PPI) | Phím cứng (2 phím cạnh + 4 phím trước) | `petink_x4-classic_v0.11.bin` |

> ⚠️ **Lưu ý:** Bản **X4 Pro** (có màn hình cảm ứng Touch và đèn nền Frontlight) hiện **chưa** được hỗ trợ trong bản build này.

---

## 🌟 Điểm nổi bật của PetInk

1. **Zero Bloat (Sạch sẽ, gọn nhẹ)**: Toàn bộ mini-game cũ và máy tính/bộ công cụ phụ trợ đã được loại bỏ sạch sẽ khỏi firmware, giải phóng bộ nhớ heap và flash để thiết bị hoạt động nhanh, mát và tiết kiệm pin tối đa.
2. **Cốt lõi Đọc Sách Hiện Đại**: Thừa hưởng toàn bộ tính năng cao cấp của CrossInk: Focus Reading, Guide Dots, Inline Images, Scalable TTF Fonts, thống kê thời gian đọc, đánh dấu trang và hỗ trợ tiếng Việt hoàn chỉnh.
3. **Thú Ảo Gắn Liền Với Thói Quen Đọc**: Thú ảo sinh sống ngay ngoài màn hình chính. Càng đọc nhiều trang sách, bạn càng nhận được nhiều thức ăn, duy trì chuỗi ngày đọc (reading streak) và giúp thú tiến hóa qua từng giai đoạn.

---

## 🐾 Hệ thống Thú Ảo Đọc Sách (Virtual Pet)

### 📚 Đọc sách để nuôi và tiến hóa thú
* **Trang sách $\to$ Bữa ăn:** Mỗi khi hoàn thành số trang sách nhất định, bạn sẽ nhận được phần thưởng thức ăn (Meals) và đồ ăn vặt (Snacks).
* **Chuỗi ngày đọc (Reading Streak):** Duy trì đọc sách hàng ngày giúp thú luôn khỏe mạnh, vui vẻ và không bị ốm.
* **5 Giai đoạn tiến hóa:**
  $$\text{Quả trứng (Egg)} \longrightarrow \text{Mới nở (Hatchling)} \longrightarrow \text{Thiếu niên (Youngster)} \longrightarrow \text{Trưởng thành (Companion)} \longrightarrow \text{Lão niên (Elder)}$$
* **Đa dạng giống loài:** Gà (Chicken), Mèo (Cat - nhiều nhánh tiến hóa), Chó (Dog), Rồng (Dragon), Thỏ (Bunny).

### 🎮 Menu chăm sóc thú ảo (`Home -> My Pet`)
* **Ăn uống (Feed):** Cho ăn bữa chính kiếm được từ việc đọc sách hoặc cho ăn vặt để tăng chỉ số vui vẻ.
* **Chữa bệnh (Cure):** Khám và tiêm thuốc khi thú bị ốm do bỏ bê đọc sách.
* **Dọn dẹp (Clean):** Dọn vệ sinh môi trường sống của thú.
* **Giáo dục / Chú ý (Discipline):** Rèn luyện thói quen và phản hồi khi thú gọi.
* **Nghỉ ngơi (Sleep):** Tắt đèn cho thú đi ngủ vào ban đêm.
* **Đặt tên & Ấp trứng mới:** Đặt tên tuỳ ý cho thú cưng bất kỳ lúc nào.

---

## 📥 Hướng dẫn Cài đặt & Flash Firmware

### Cách 1: Nâng cấp trực tiếp qua Thẻ nhớ SD (Khuyên dùng)
1. Tải file firmware tương ứng với thiết bị của bạn từ mục [Releases](https://github.com/3r1pm4V/CrossInkplusPet/releases):
   * Với **Xteink X3**: tải `petink_x3_v0.11.bin`
   * Với **Xteink X4 Classic**: tải `petink_x4-classic_v0.11.bin`
2. Chép file `.bin` vào thư mục gốc của thẻ MicroSD (định dạng FAT32).
3. Bật máy đọc sách, mở mục **Quản lý tệp (File Browser)**, chọn file `.bin` vừa chép và nhấn **Xác nhận (Confirm)**.
4. Máy sẽ tự động kiểm tra chip ESP32, tag phần cứng, tính toàn vẹn SHA256 và tiến hành flash. Sau khi hoàn tất máy sẽ tự khởi động lại.

### Cách 2: Flash bằng chế độ Cứu hộ (Bootloader Recovery)
1. Đổi tên file firmware thành `update.bin` và chép vào thư mục gốc của thẻ MicroSD.
2. Tắt máy, sau đó nhấn giữ nút **Quay lại (Back)** đồng thời bấm nút Nguồn để vào chế độ nạp khẩn cấp.
3. Thiết bị sẽ tự động phát hiện `update.bin` và tiến hành nạp firmware.

### Cách 3: Nạp qua cổng USB bằng PlatformIO
Kết nối máy đọc sách qua cáp USB-C và chạy lệnh:
```bash
# Cho Xteink X3:
pio run -e default --target upload

# Cho Xteink X4 Classic:
pio run -e x4-classic --target upload
```

---

## 🛠️ Biên dịch từ Mã Nguồn (Build from Source)

### Yêu cầu
* [PlatformIO Core](https://platformio.org/) hoặc VS Code cài PlatformIO extension.
* Python 3.10+

### Các bước biên dịch
```bash
# Clone repository
git clone --recurse-submodules https://github.com/3r1pm4V/CrossInkplusPet.git
cd CrossInkplusPet

# 1. Biên dịch cho Xteink X3 (ESP32-C3)
pio run -e default
# File xuất ra: petink_x3_v0.11.bin

# 2. Biên dịch cho Xteink X4 Classic (ESP32-S3)
pio run -e x4-classic
# File xuất ra: petink_x4-classic_v0.11.bin
```

---

## 🎮 Thao tác Phím Bấm

| Phím | Màn hình chính (Home) | Màn hình Thú Ảo | Trong trình đọc sách (Reader) |
|---|---|---|---|
| **Lên / Trái** | Chọn mục trước | Di chuyển con trỏ hành động lên | Lật trang trước |
| **Xuống / Phải** | Chọn mục kế tiếp | Di chuyển con trỏ hành động xuống | Lật trang tiếp theo |
| **Xác nhận (Confirm)** | Mở ứng dụng đã chọn | Thực hiện hành động / Ấp trứng | Mở menu tùy chọn đọc sách |
| **Quay lại (Back)** | Tiếp tục đọc cuốn sách gần nhất | Lưu trạng thái & về Home | Thoát sách / Quay lại menu trước |

---

## 📄 Bản quyền & Lời cảm ơn (Credits)

* Kế thừa nền tảng **[CrossInk](https://github.com/uxjulia/CrossInk)** phát triển bởi [@uxjulia](https://github.com/uxjulia) và **[CrossPoint Reader](https://github.com/crosspoint-reader/crosspoint-reader)**.
* Hệ thống Thú Ảo xây dựng dựa trên ý tưởng từ **CrossPet**.
* Mã nguồn phát hành dưới giấy phép mã nguồn mở [MIT License](LICENSE).
