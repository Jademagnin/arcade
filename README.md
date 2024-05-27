
# Arcade project


The Arcade project for Epitech is a collaborative effort between two groups aiming to recreate classic arcade games using modern programming techniques. The project focuses on implementing two iconic games: Snake and Pacman. These games are developed using three different graphical libraries: SFML, SDL2, and Ncurses. One of the primary objectives of the project is to ensure compatibility between the architectures developed by the two groups, allowing seamless integration of games developed by one group into the codebase of the other group.
This project was carried out by Jade MAGNIN (jade.magnin@epitech.eu), Nathanael MOEHN (nathanael.moehn@epitech.eu), produced during our second year at Epitech, in collaboration with the other group made up of Jean-Baptiste KRIMM (jean-baptiste.krimm@epitech.eu), Auguste MULLEY (auguste.mulley@epitech.eu) and Arthur GASMI (arthur.gasmi@epitech.eu).

## Game Descriptions

Snake is a classic arcade game where the player controls a snake that moves around a bounded area, consuming food items to grow longer. The objective is to avoid colliding with the walls of the play area or the snake's own tail while maneuvering to eat as much food as possible.

Pacman is a classic maze arcade game where the player controls a character navigating through a maze filled with pellets while avoiding ghosts. The objective is to consume all the pellets in the maze while evading the ghosts. 

You are free to add the games you want. All you have to do is create a .so file. You can either add it directly to /lib, or follow the model of existing games by implementing it in /src/modules/games and adding it to the makefile in this folder.

## Supported Librairies

The project supports three different graphical libraries, which are used for rendering the games:

SFML (Simple and Fast Multimedia Library): A cross-platform software development library designed to provide a simple interface to various multimedia components in computers.

SDL2 (Simple DirectMedia Layer): A cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

Ncurses: A programming library that provides an API for building text-based user interfaces in a terminal-independent manner.

You are free to add the libs you want. All you have to do is create a .so, which you can either add directly to /lib, or follow the model of existing libs by implementing it in /src/modules/display and adding it to the makefile in this folder.


## Compatibility
One of the primary goals of the project is to ensure compatibility between the architectures developed by the two groups. This compatibility allows the games implemented by one group to be launched within the codebase of the other group without any modifications.

## Achieving Compatibility
Both groups adhere to a standardized architecture and interface for game development.
Common design patterns and principles are followed to ensure consistency.
Communication between the groups is maintained throughout the development process to address any compatibility issues.

## Usage

Clone the project

```bash
  git clone git@github.com:EpitechPromo2027/B-OOP-400-STG-4-1-arcade-nathanael.moehn.git
```

Go to the project directory

```bash
  cd arcade
```

Install dependencies

```bash
  sudo apt-get install libsdl2-ttf-dev    
  sudo apt-get install libsfml-dev      
  sudo apt-get install libncurses5-dev libncursesw5-dev
```

Start the project

```bash
  make re
  ./arcade lib/<graphical_lib_name>.so
```

## Contributing

Contributions are always welcome!
If you encounter any bugs, have suggestions for improvements, or would like to contribute additional features, please feel free to submit a pull request.

## License

This project is licensed under the [MIT](https://choosealicense.com/licenses/mit/) License, which means you are free to use, modify, and distribute the code as long as you include the original copyright and license notice.