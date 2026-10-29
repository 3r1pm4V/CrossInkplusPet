# 🐾 CrossInk + Pet (CrossPet Rebuild)

[![Release](https://img.shields.io/github/v/release/3r1pm4V/CrossInkplusPet?style=flat-square)](https://github.com/3r1pm4V/CrossInkplusPet/releases)
[![Device](https://img.shields.io/badge/Device-Xteink%20X3-blue?style=flat-square)](#supported-devices)
[![Base](https://img.shields.io/badge/Base-CrossInk%20v1.6.1-brightgreen?style=flat-square)](https://github.com/uxjulia/CrossInk)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

> **CrossInk + Pet** is a specialized firmware that merges the modern, high-performance e-reader capabilities of **[CrossInk](https://github.com/uxjulia/CrossInk)** (v1.6.1) with the beloved **Virtual Pet (Thú Ảo)** habit-building companion system from CrossPet, designed specifically for **Xteink X3** and compatible e-paper devices.

---

## 🌟 What is CrossInk + Pet?

The original CrossPet firmware provided a wonderful concept: **a virtual pet that grows as you read books**. However, older CrossPet releases lagged behind the massive performance, rendering, and stability improvements in newer versions of CrossInk.

This project **rebuilds CrossPet from the ground up** on top of the latest CrossInk v1.6.1 codebase:
- **Zero Bloat**: Unnecessary legacy mini-games and calculator/tool apps have been pruned to maximize free flash memory, heap, and battery life.
- **Modern E-Reader Core**: Crisp typography, high-performance EPUB/TXT/XTC rendering, customizable margins, scalable fonts, bookmarks, reading statistics, and full Vietnamese language support.
- **Deep Virtual Pet Integration**: Your pet lives right on your home screen, with its hunger, happiness, and growth directly fueled by your real reading progress.

---

## 🐾 Virtual Pet System (Thú Ảo Đọc Sách)

### 📚 Reading-Driven Evolution
Your pet is more than just a Tamagotchi — it's an interactive reading companion that motivates daily habits:
- **Pages to Food**: Reading books accumulates page counts that reward meals and snacks for your pet.
- **Reading Streak**: Your daily reading streak keeps your pet healthy and prevents sickness.
- **Evolution Stages**: Your companion evolves through 5 distinct life stages:
  $$\text{Egg} \longrightarrow \text{Hatchling} \longrightarrow \text{Youngster} \longrightarrow \text{Companion} \longrightarrow \text{Elder}$$
- **Diverse Species**: Choose from multiple pet types, each with custom pixel art sprites and evolution variants:
  - 🐥 **Chicken**
  - 🐱 **Cat** (with special evolution branches)
  - 🐶 **Dog**
  - 🐲 **Dragon**
  - 🐰 **Bunny**

### 🎮 Care & Interaction Menu
Access the **My Pet** menu directly from the Home screen (`Home -> My Pet`) to manage:
- **Feeding**: Feed meals earned by reading or give snacks for instant happiness.
- **Medical Care**: Treat illness when your pet falls sick.
- **Cleaning**: Keep your pet's environment clean.
- **Discipline & Attention**: Respond to calls and guide your pet's behavior.
- **Sleep & Rest**: Toggle lights or let your pet sleep peacefully.
- **Personalization**: Name or rename your pet anytime, or hatch a new egg when ready.

---

## 📖 Modern Reader Highlights (From CrossInk v1.6.1)

- **Optimized Typography**: Enhanced fonts tailored for E-Ink readability (Bitter, Lexend Deca) with crisp anti-aliasing and zero ghosting.
- **Multi-Format Support**: Reads EPUB, TXT, XTC, and markdown files smoothly.
- **Reading Statistics**: Live tracking of reading time, pages turned, reading speed, and daily streaks.
- **Themes & Layouts**: Standard, Minimal, Dashboard, and Carousel UI modes.
- **Wi-Fi Web Server & Sync**: Effortless file transfers and book management over local Wi-Fi.

---

## ⚡ Direct SD Card Firmware Updating

Updating firmware on your Xteink X3 has never been easier:
1. Put any `.bin` firmware file on your MicroSD card.
2. In **File Browser**, highlight the `.bin` file and press **Confirm**.
3. The system automatically inspects:
   - ESP32-C3 chip compatibility
   - Board hardware tag (X3/X4)
   - Partition bounds
   - SHA256 integrity checksum
4. Press **Confirm** to flash, and the device will automatically reboot into the new firmware!

---

## 📥 Installation & Flashing Guide

### Method 1: Update via SD Card (Recommended)
1. Download the latest `crosspet_xteink_x3.bin` from the [Releases](https://github.com/3r1pm4V/CrossInkplusPet/releases) page.
2. Copy the file into the root of your FAT32-formatted MicroSD card.
3. Power on your Xteink X3, open **File Browser**, select `crosspet_xteink_x3.bin`, và bấm xác nhận để cập nhật.

### Method 2: Bootloader / Recovery Flash
1. Rename the firmware file to `update.bin` and copy it to the root of your MicroSD card.
2. Power on the device while holding the **Back / Side button** to enter bootloader recovery mode.
3. The system will detect `update.bin` and update automatically.

### Method 3: USB Flashing with PlatformIO / esptool
Connect your device via USB-C and run:
```bash
pio run -e default --target upload
```

---

## 🛠️ Building from Source

### Prerequisites
- [PlatformIO Core](https://platformio.org/) or VS Code with the PlatformIO extension.
- Python 3.10+

### Build Steps
```bash
# Clone the repository
git clone --recurse-submodules https://github.com/3r1pm4V/CrossInkplusPet.git
cd CrossInkplusPet

# Compile default firmware for ESP32-C3 (Xteink X3)
pio run -e default
```
The compiled firmware image will be generated at:
`.pio/build/default/firmware.bin`

---

## 🎮 Controls (Xteink X3)

| Button | Home Menu | Virtual Pet Screen | Reader Mode |
|---|---|---|---|
| **Up / Left** | Previous item | Move action menu up | Previous page |
| **Down / Right** | Next item | Move action menu down | Next page |
| **Confirm** | Open selected app | Execute action / Hatch egg | In-book menu |
| **Back** | Continue reading book | Save pet state & exit to Home | Exit book / Go back |

---

## 📄 License & Credits

- Based on **[CrossInk](https://github.com/uxjulia/CrossInk)** by [@uxjulia](https://github.com/uxjulia) and **[CrossPoint Reader](https://github.com/crosspoint-reader/crosspoint-reader)**.
- Virtual Pet mechanics inspired by the original **CrossPet** Tamagotchi engine.
- Licensed under the [MIT License](LICENSE).
