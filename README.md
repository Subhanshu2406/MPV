# 🎵 Music Visualizer (MPV)

A real-time audio visualization tool built using C++, OpenGL, and PortAudio that transforms audio frequencies into visually dynamic graphics such as circular and bar-based patterns. Supports both MP3 and WAV file formats with customizable visualization options.

---

## 🚀 Features

- 🎧 **Audio Support**: Plays and processes both `.mp3` and `.wav` formats.
- 🔊 **FFT Audio Processing**: Uses FFTW to compute real-time frequency magnitudes.
- 🎨 **Multiple Visualizations**:
  - **Bar Visualization** – Frequency bars colored by magnitude
  - **Circular Visualization** – Radial patterns responding to frequency intensity
- 🖼️ **OpenGL Rendering**: Dynamic, GPU-accelerated rendering using shaders.
- 🌈 **Color Mapping**: Smooth amplitude-driven color gradients via `ColorUtils`.
- 🧵 **Thread-Safe Buffering**: Efficient multithreading with mutexes for real-time FFT computation.

---

## 🗂️ Project Structure

```
Subhanshu2406-mpv/
├── audio/                  # Audio file reading and FFT processing
│   ├── AudioReader.cpp     # MP3/WAV decoding
│   └── FFTProcessor.cpp    # FFT analysis
├── sample_audios/          # Sample MP3/WAV files for testing
├── src/                    # Core application and visualization logic
│   ├── main.cpp            # CLI + app entrypoint
│   ├── Audio.cpp           # Manages playback and FFT updates
│   ├── ShaderUtils.cpp     # Loads and compiles GLSL shaders
│   ├── visualizations/
│   │   ├── BarVisualization.*     # Bar chart renderer
│   │   ├── CircleVisualization.*  # Radial pattern renderer
│   │   ├── fragmentShader.glsl    # GLSL fragment shader
│   │   └── vertexShader.glsl      # GLSL vertex shader
├── README.md               # Project overview and instructions
└── Makefile                # Build instructions
```

---

## 🛠️ Dependencies

- **OpenGL / GLEW / GLFW** – Rendering and window management
- **PortAudio** – Real-time audio playback
- **FFTW3** – Fast Fourier Transform calculations
- **libsndfile** – WAV decoding
- **mpg123** – MP3 decoding

On Windows, you can install these via MSYS2 or vcpkg. Make sure to update the `Makefile` with appropriate include/library paths.

---

## 🧪 Build Instructions

### 🔧 On Windows (MSYS2):

```bash
make
```

### 🔧 On Linux:

```bash
g++ src/*.cpp audio/*.cpp src/visualizations/*.cpp -o audio_visualizer \
    -lGL -lGLEW -lglfw -lportaudio -lmpg123 -lfftw3f -lsndfile -std=c++17
```

---

## ▶️ How to Use

1. Run the executable:
   ```
   ./audio_visualizer
   ```

2. Enter the path to your `.mp3` or `.wav` file when prompted.

3. Select a visualization mode:
   ```
   1. Circle Visualization
   2. Bar Visualization
   ```

4. Watch your music come alive!

---

## 🧠 Design Highlights

- **Polymorphic Visual Base**: All visualization types inherit from `BaseVisualization`, enabling easy extensibility.
- **Amplitude Smoothing**: Visuals are stabilized with a decay filter to prevent jitter.
- **Color Dynamics**: Frequency intensities are converted to RGB gradients in `ColorUtils`.

---

## 💡 Future Improvements

- Add support for more visualization types (e.g., waveform, radial spectrogram).
- Add GUI using ImGui or Qt for better user interaction.
- Enable real-time microphone input.
- Export visualization as video or GIF.

---

## 📜 License

MIT License. See [LICENSE](LICENSE) for details.

---

## ✨ Credits

Developed by [Subhanshu2406](https://github.com/divyansh1010x)  
Libraries: PortAudio, mpg123, FFTW3, libsndfile, OpenGL, GLEW, GLFW
