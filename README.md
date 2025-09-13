# C++ Vision Starter (OpenCV → ONNX Runtime CLI)

Minimal **C++20 / CMake** starter intended to bridge Python training and C++ inference:

- **Stage 1:** basic **OpenCV** operations (read, resize 224×224, BGR→RGB, save).
- **Stage 2:** **ONNX Runtime** CLI (e.g., ResNet18 inference @ 224×224) on macOS (Apple Silicon).

---

## Motivation

Many real-world workflows train models in **Python** (PyTorch/TF) but deploy inference in **C++** for:
- **Performance & startup time** (native, no interpreter warm-up),
- **Portability** (ship a single binary),
- **Tighter integration** with existing C++ systems.

This repo is a clean, minimal scaffold to learn/ship that pipeline: OpenCV preprocessing → ONNX Runtime inference.

---

## Project Structure

```bash
opencv-to-onnxruntime-cpp-cli/
├── CMakeLists.txt                  # CMake build recipe (C++20, targets, deps)
├── README.md
├── .gitignore
├── .gitattributes
├── src/
│   └── main.cpp                    # CLI entry point (Stage 1: OpenCV basics)
├── include/                        # your headers (for later)
├── assets/
│   ├── samples/                    # input images for testing (add your own)
│   └── models/                     # .onnx files (Stage 2)
├── scripts/                        # helper scripts (setup, export_to_onnx.py, etc.)
├── cmake/                          # extra cmake modules (if needed later)
├── tests/                          # gtest (optional, later)
└── out/                            # generated outputs (git-ignored)
 
