# 🐾 CrossInk + Pet (CrossPet Rebuild)

[![Release](https://img.shields.io/github/v/release/3r1pm4V/CrossInkplusPet?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Version](https://img.shields.io/badge/Version-v0.11-orange?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Device](https://img.shields.io/badge/Devices-Xteink%20X3%20%7C%20X4%20Classic-blue?style=flat-square)](#-thiết-bị-hỗ-trợ-supported-devices)
[![Base](https://img.shields.io/badge/Base-CrossInk%20v1.6.1-brightgreen?style=flat-square)](https://github.com/uxjulia/CrossInk)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

> **CrossInk + Pet** là bản firmware tuỳ biến kết hợp giữa trình đọc sách hiện đại, hiệu năng cao của **[CrossInk](https://github.com/uxjulia/CrossInk)** (v1.6.1) và hệ thống **Thú Ảo (Virtual Pet)** rèn luyện thói quen đọc sách từ CrossPet.
>
> ⚠️ **Hỗ trợ phần cứng:** Hiện tại firmware **chỉ hỗ trợ 2 dòng máy: Xteink X3 và Xteink X4 Classic** (phiên bản phím bấm vật lý, không cảm ứng).

---

## 📌 Quy ước phiên bản (Versioning Scheme)

Để người dùng và lập trình viên dễ dàng theo dõi nguồn gốc và mức độ thay đổi, dự án áp dụng quy ước đánh số phiên bản như sau:
* **Phiên bản cơ sở bắt đầu:** `0.1` (CrossInk 1.6.1 + Virtual Pet tích hợp).
* **Cập nhật từ CrossInk gốc:** Mỗi lần đồng bộ, tải về và cập nhật phiên bản mới từ thượng nguồn [uxjulia/CrossInk](https://github.com/uxjulia/CrossInk) sẽ **cộng `+0.1`** vào version (ví dụ: `0.1` $\to$ `0.2` $\to$ `0.3`...).
* **Tối ưu hoá / Custom tweaks:** Mỗi lần bổ sung tối ưu nội bộ (tăng tốc độ tải file EPUB, giảm RAM, cải tiến bố cục, vá lỗi riêng...) sẽ **cộng `+0.01`** vào version (ví dụ: `0.10` $\to$ `0.11` $\to$ `0.12`...).
* **Phiên bản hiện tại: `v0.11`**:
  * Tích hợp toàn diện Thú ảo đọc sách trên nền CrossInk 1.6.1.
  * Lược bỏ hoàn toàn bloatware (trò chơi, công cụ thừa) để tối ưu RAM và Flash.
  * Tối ưu bộ nhớ đệm EPUB Spine theo cấu trúc Cửa sổ trượt (Sliding Window Cache), giảm RAM tiêu thụ xuống chỉ ~128 bytes ngay cả với sách hàng nghìn chương.
  * Bổ sung streaming `InflateReader`, `WordStore` layout arena và bộ ngắt dòng CJK Unicode UAX#14.
  * Hỗ trợ đầy đủ cho cả **Xteink X3** và **Xteink X4 Classic**.

---

## 📱 Thiết bị hỗ trợ (Supported Devices)

| Thiết bị | Vi điều khiển (MCU) | Màn hình | Điều khiển | Tên file Firmware |
|---|---|---|---|---|
| **Xteink X3** | ESP32-C3 (RISC-V) | 3.52" E-Ink (360x240) | Phím cứng | `crosspet_x3_v0.11.bin` |
| **Xteink X4 Classic** | ESP32-S3 (Xtensa Dual-Core) | 4.2" E-Ink (800x480) | Phím cứng (6 phím) | `crosspet_x4_classic_v0.11.bin` |

*Ghi chú: Bản X4 Pro (màn hình cảm ứng / frontlight) hiện không nằm trong danh sách hỗ trợ của bản build này.*

---

## 🌟 Điểm nổi bật của CrossInk + Pet

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
   * Với **Xteink X3**: tải `crosspet_x3_v0.11.bin`
   * Với **Xteink X4 Classic**: tải `crosspet_x4_classic_v0.11.bin`
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
# File xuất ra: .pio/build/default/firmware.bin

# 2. Biên dịch cho Xteink X4 Classic (ESP32-S3)
pio run -e x4-classic
# File xuất ra: .pio/build/x4-classic/firmware.bin
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
