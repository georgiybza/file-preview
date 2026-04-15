# file-preview

## A file previewer, currently in progress.

## File Structure:
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   │
│   ├── app/              # App lifecycle / orchestration
│   ├── core/             # Core logic (file handling, routing)
│   ├── render/           # Rendering system
│   ├── ui/               # Windowing + display
│   ├── input/            # Hotkeys, CLI, integrations
│   ├── utils/            # Shared helpers
│   └── platform/         # Linux-specific stuff (Wayland/X11)
│
├── include/              # Public headers (mirrors src/)
│
├── assets/               # Icons, themes, etc.
├── config/               # Default config files
├── tests/                # Unit/integration tests
