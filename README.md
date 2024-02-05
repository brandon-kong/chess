<img src="static/header.png" />

<h1 align="center">Chess (with no additional features) </h1>

<div align="center">
  
[![CI Build](https://github.com/brandon-kong/chess/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/brandon-kong/chess/actions/workflows/cmake-single-platform.yml)

</div>

<p>

Yup. It's just chess. No additional features. Just chess. I know what you're thinking. "Why would I want to play chess with no additional features?" Well, I don't know. Maybe you're a purist. Maybe you're a minimalist. Maybe you like the idea of playing chess with no additional features. Maybe you're just bored.

The real question you should be asking yourself is "Why do I have so much time on my hands that I'm reading the README for a chess game with no additional features?" To which I would respond, "I don't know. Why do you?"

</p>

## Table of Contents

- [Table of Contents](#table-of-contents)
- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)

## About

This is a simple chess game with no additional features. It's written in C++ and uses the [SFML](https://www.sfml-dev.org/) library for graphics. The game is built using the [CMake](https://cmake.org/) build system.

## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

- CMake

### Installation

1. Clone the repo

```sh
   git clone https://github.com/brandon-kong/chess.git
```

2. Build the project

    On Windows:

```sh
cd chess
mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

On Linux/Mac:

```sh
cd chess
mkdir build
cd build
cmake ..
make
```

3. Run the game

```sh
    ./chess
```

4. Lose to the computer

> Note: The game is currently only playable in single-player mode. Multiplayer mode is not yet supported.

## License

Distributed under the MIT License. See `LICENSE` for more information.
