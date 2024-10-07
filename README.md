# pro-test

This repository contains a set of C algorithms covering areas like sorting, searching, data structures and a few miscellaneous scripts. The intent is to provide a useful source for beginners in learning C and to give pro-users the facility to use readily available code snippets.

## Pre-requisites

To clone and run this project, you'll need Git and GCC installed on your computer. Here are the installation steps for different platforms.

#### Mac:

1. Install Homebrew (if you don't have it).

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

2. Install Git and GCC.

```bash
# update homebrew
brew update

# install git
brew install git

# install gcc
brew install gcc
```

#### Windows:

1. Install Git Bash (https://git-scm.com/download/win)
2. Install MinGW (https://sourceforge.net/projects/mingw) and add it to your path.

## Start Locally

Clone the project and compile and run any script. Here's how you do that:

```bash
# Clone this repository
git clone https://github.com/username/pro-test.git

# Go into the repository
cd pro-test

# Compile and run any C script (example)
gcc -o bubblesort c/algorithms/bubblesort.c
./bubblesort
```

## CI/CD

This repository follows certain CI/CD practices using Github Actions. 

## Contribution

Read the Contribution Guidelines before making a contribution. 

## License

This repository follows a certain licensing policy. Make sure to read that.