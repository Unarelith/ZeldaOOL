# The Legend of Zelda: Oracle of Light

### By gnidmoo

- This game is a Zelda fangame, based on the *Oracle of* series on GBC

![](http://img15.hostingpics.net/pics/255623Capturedcrande20141005181925.png)

## Keys

- A : `W` (or `Z` on QWERTY keyboards)
- B : `X`
- Start : `Enter`
- Select : `Backspace`
- Directional keys: Arrows

## How to compile

- Dependencies:
    - [CMake](http://www.cmake.org/download/)
    - [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2_image](https://www.libsdl.org/projects/SDL_image/), [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)
    - OpenGL >= 2.1, [glm](http://sourceforge.net/projects/ogl-math/files/latest/download?source=files)
    - [glew](http://sourceforge.net/projects/glew/files/latest/download) *(only required for Windows)*
- **GCC Users:** There's a [bug](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=55914) in GCC < 4.9, so the code won't compile. Please install at least GCC 4.9.
- Run `cmake .` at the root of the game folder
- Run `make`, wait, run the game and enjoy!

## Pre-compiled builds

- **Windows:** (old) [ZeldaOOT.zip](https://dl.dropboxusercontent.com/u/41571323/ZeldaOOT.zip) _works with Wine without sound_
- **Linux:** _Not available yet_
- **OS X:** _Not available yet_

