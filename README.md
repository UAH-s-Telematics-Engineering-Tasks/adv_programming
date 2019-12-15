# Advanced Programming Practices by Pablo Collado Soto
This repository contains all the code we've needed to write for the **Advanced Programming** course over at the **Universidad de Alcalá, Madrid, Spain**. We have gathered everything in a GitHub (:octocat) repository for several reasons:

1. To keep a clean working environment enabling faster developing.
2. To practice managing a `git` repository.
3. To use emojis :+1:

## Repository structure
You'll find a folder for each of the practices we've doing throughout the course. As many of them had two different versions we made a couple of subfolders, one for each with a `_X` suffix where `X` is either `a` or `b`. Each project folder usuaaly contains:

* `inc directory`: You will find every header (`.h`) file here unless the project has an `inc_class` subfolder. These include class definitions, library imports and the like. Some class definitions include the definition of `setter`s and `getter`s as they are simple one-liners. Method definitions are often included in `.cpp` files nonetheless.

* `src directory`: You'll find `.cpp` files containing `main's` code, all the method definitions, auxiliary functions used for ` terminal I/O`...

* `inc_class directory`: This directory is only present on **P_6** as the number of files was getting out of hand... This directory includes class definitions whilst `inc` will only contain library imports and the like.

* `src_class directory`: Just like before, this folder only appears on **P_6** and will contain the methods' definitions. Code pertaining `main` and `I/O` functions will still be under the `src` directory.

* `Makefile`: This file contains the "instructions" on how to compile the rest of the code. It's kind of a botched job as I'm not really proficient with them but hey, it works! :panda_face:. We encourage you to read up on `Makefile`s as they are commonly used. We should do the same too... :crying_cat_face:

* `.ex file`: This file will be generated upon a successful compilation. We'll get into compilation in a jiff :boom:

## Compiling and running the code
All the projects we've had to do are fairly small but the are composed of many files... That's why we decided to prepare a **Makefile** for each. In order to compile each project you just need to navigate to the project's folder and run `make`. Note that for projects with two versions the project folder will be `P_X_Y` where `X` is a number and `Y` is either `a` or `b`. In other words, navigate to a folder containing a file named `Makefile` and just run `make`. If you happen not to have `make` installed you could try with `sudo apt install build-essential` on an Ubuntu based distro.

To run the code you only need to run the `.ex` file that'll be generated after compiling the code with `make`. If for any reason the compilation fails you won't see the `.ex` file... Every project should compile correctly but if that's not the case you must hunt down the mistake... Good luck :stuck_out_tongue_winking_eye:

## Hunting for Memory Leaks
As the utility we've been given works only with Windows based compilers we have used `valgrind` to track 'em down. On an Ubuntu system like ours you can just run `sudo apt install valgrind` to get the program. In order to use it you just need to run `valgrind <command>` where command might be `./P_5` for us.

## Why so many `this`?

Our first steps in programming where with good ol' `C`. What we liked the most about it was how clear and strict it was on data type declarations. When working with `C++` some if not many of the statements we write imply some implicit operations: `C++` does some operations "behind the courtain" so that everything works smoothly. This can simplify code but it may also obscure its inner workings... That's why we like to use `this` explicitly in every method call and attribute access as we believe clarity is desirable over code brevity. It's also a nice way of being sure wich object's mehtod will be called! We understand this may not be the best approach for produciton code but ours is an academic use of the language :smiley_cat:

## Final notes

No matter the problems you might encounter, remember that...

<p align="center">
  <img src="./Memes/It_works.jpg">
</p>
