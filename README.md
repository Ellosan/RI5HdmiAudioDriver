# Raspberry Pi 5 HDMI Audio Driver (Source with Build Workflow)

This repository contains:

- A KMDF-based Windows 11 ARM64 HDMI audio driver for Raspberry Pi 5.
- Visual Studio solution (`.sln`) and project (`.vcxproj`) files.
- `RPi5HdmiAudio.inf` to install the driver.
- GitHub Actions workflow to build on `windows-latest`.

## Building via GitHub Actions

Just push this repo to GitHub and the `build-driver.yml` workflow will compile the driver and publish the `.sys` and `.inf` as artifacts.

## Installation on Pi

1. Download and unzip the artifact on your Pi.
2. (Optional) Sign `RPi5HdmiAudio.sys` for test signing:
   ```powershell
   signtool sign /fd SHA256 /a /tr http://timestamp.digicert.com RPi5HdmiAudio.sys
   ```
3. Install:
   ```powershell
   pnputil /add-driver RPi5HdmiAudio.inf /install
   ```
4. Reboot and select "Raspberry Pi 5 HDMI Audio" in Settings → System → Sound.
