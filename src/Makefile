# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall 

# Include and Library Paths for MinGW64 (MSYS2)
INCLUDE_PATHS = -I/mingw64/include
LIBRARY_PATHS = -L/mingw64/lib

# Libraries
LIBS = -lglew32 -lglfw3 -lopengl32 -lportaudio -lmpg123 -lfftw3f -lm -lsndfile


# Source files
SRC = main.cpp Audio.cpp Visuals.cpp ../audio/AudioReader.cpp ../audio/FFTProcessor.cpp

# Output binary
OUT = audio_visualizer

# Target to build the program
$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LIBS)

# Clean target to remove the binary (Windows Compatible)
clean:
	-del /f /q $(OUT) 2> nul
